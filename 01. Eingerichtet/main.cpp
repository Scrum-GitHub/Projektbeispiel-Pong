#include "Ball.h"
#include "Schlaeger.h"
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
void gameplay(sf::RenderWindow* meinSpieleFenster, Ball* ball, Schlaeger* schlaegerL, Schlaeger* schlaegerR);

int main()
{   
    // 
    Ball* ball = new Ball(400, 300, 5);
    Schlaeger* schlaegerR = new Schlaeger(0,275,10,150);
    Schlaeger* schlaegerL = new Schlaeger(790, 275, 10, 150);

    // Spielefenster erstellen
    RenderWindow* meinSpieleFenster = new RenderWindow(VideoMode(800, 600), "Pong");
    meinSpieleFenster->setFramerateLimit(30);

    // Erstellen Sie eine Schaltfläche zum Starten des Spiels
    RectangleShape startButton(Vector2f(200, 100));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(300, 250); // Positionieren Sie die Schaltfläche in der Mitte des Fensters
    
    // Erstellen Sie eine Schaltfläche zum Beenden des Spiels
    RectangleShape exitButton(Vector2f(200, 100));
    exitButton.setFillColor(Color::Red);
    exitButton.setPosition(300, 500); 

    // Schriftart
    Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) 
        std::cout << "Fehlermeldung: Schriftart Arial konnte nicht geladen werden!" << std::endl;

    // Start Buttontext 
    /// neu
    Text startButtonText("Start", font);
    startButtonText.setCharacterSize(24);
    startButtonText.setFillColor(Color::Black);
    startButtonText.setPosition(startButton.getPosition().x + 20, startButton.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Exit Buttontext 
    Text exitButtonText("Exit", font);
    exitButtonText.setCharacterSize(24);
    exitButtonText.setFillColor(Color::Black);
    exitButtonText.setPosition(exitButton.getPosition().x + 20, exitButton.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Erstellen Sie einen Booleschen Wert, um zu überprüfen, ob das Spiel gestartet wurde
    bool gameStarted = false;
   
    // Spiel-Schleife
    while (meinSpieleFenster->isOpen()) {   // Solange das Spielfenster geöffnet ist, mache ....
        
        // User-Eingaben als "Ereginisse" auswerten:
        Event event;                        // Um Ereignisse abzurufen, die vom Benutzer ausgelöst wurden, wie z.B. Tastendrücke, Mausklicks oder das Schließen des Fensters.
        while (meinSpieleFenster->pollEvent(event)) {
           // Überprüft, ob das Spielfenster geschlossen wird
            if (event.type == Event::Closed)
                meinSpieleFenster->close();

            // Überprüfen Sie, ob die linke Maustaste gedrückt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // Überprüfen Sie, ob die Maus auf der Schaltfläche ist
                if (startButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    gameStarted = true;
                }

                // Überprüfen Sie, ob die Maus auf dem Beenden-Button ist
                if (exitButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    meinSpieleFenster->close();
                }
            } 
        }

        // Bewege den SchlägerL nach oben, wenn die obere Pfeiltaste gedrückt wird
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            schlaegerL->moveUp();
        }

        // Bewege den SchlägerL nach unten, wenn die untere Pfeiltaste gedrückt wird
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            schlaegerL->moveDown(meinSpieleFenster->getSize().y);
        }

        // Bewege den SchlägerR nach oben, wenn die obere Pfeiltaste gedrückt wird
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            schlaegerR->moveUp();
        }

        // Bewege den SchlägerR nach unten, wenn die untere Pfeiltaste gedrückt wird
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            schlaegerR->moveDown(meinSpieleFenster->getSize().y);
        }

        // Spielfeldbegrenzung
        // Ballumkehr beim Treffen des oberer und unterer Randes
        if (ball->getPosition().top             // gibt die y-Position des oberen Randes des Balls zurück
            + ball->getPosition().height        // ist die Höhe des Balls
            > meinSpieleFenster->getSize().y    // ist die Höhe des Fensters
            || ball->getPosition().top < 0) {   // y-Achse Position 0, also ganz links 
            ball->reboundBatOrTop();            // Dann Richtungsänderung
        }
        
        // Der Ball prallt ab, wenn er einen Schläger trifft.
        if (ball->getGlobalBounds().intersects(schlaegerL->getPosition())||
            ball->getGlobalBounds().intersects(schlaegerR->getPosition()))
        {
            // Ball abprallen lassen
            ball->reboundSides();
        }


        // Ballumkehr beim Treffen des linken und rechten Randes
        if (ball->getPosition().left < 0        // wenn Ball kleiner als 0 ist, berührt der Ball den linken Rand des Fensters
            || ball->getPosition().left + ball->getPosition().width    // größer als die Breite des Fensters + Ballbreite 
        > meinSpieleFenster->getSize().x) {     // berührt der Ball den rechten Rand des Fensters
            // Ballumkehren
            ball->reboundSides();
            // Punkte verteilen und Ball zurücksetzen
            if (ball->getPosition().left < 0) {
                schlaegerR->getPunkteObj()->erhoehe();
                ball->setPosition(400, 300);
            }
            if (ball->getPosition().left + ball->getPosition().width > meinSpieleFenster->getSize().x) {
                schlaegerL->getPunkteObj()->erhoehe();
                ball->setPosition(400, 300);
            }
            std::cout << "Rechtes: " << schlaegerR->getPunkteObj()->getPunkte() << " Links: " << schlaegerL->getPunkteObj()->getPunkte() << std::endl;
        }


        // Start-Menue wird gezeichnet
        if (!gameStarted) {
            meinSpieleFenster->clear();
            meinSpieleFenster->draw(startButton);
            meinSpieleFenster->draw(startButtonText);
            
            meinSpieleFenster->draw(exitButton);
            meinSpieleFenster->draw(exitButtonText);
            meinSpieleFenster->display();
        }
        else {
         // Spiel wird gezeichnet      
            gameplay(meinSpieleFenster, ball, schlaegerL, schlaegerR);

        }
    }

    return 0;
}

void gameplay(sf::RenderWindow* meinSpieleFenster, Ball* ball, Schlaeger* schlaegerL, Schlaeger* schlaegerR) {
    ball->update();
    meinSpieleFenster->clear();
    meinSpieleFenster->draw(schlaegerR->getShape());
    meinSpieleFenster->draw(schlaegerL->getShape());
    meinSpieleFenster->draw(ball->getShape());
    meinSpieleFenster->display();
}