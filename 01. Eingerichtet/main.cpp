#include "Ball.h"
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
void gameplay(sf::RenderWindow* meinSpieleFenster, Ball* ball);

int main()
{   
    // Spielefenster erstellen
    RenderWindow* meinSpieleFenster = new RenderWindow(VideoMode(800, 600), "Pong");
    meinSpieleFenster->setFramerateLimit(30);

    // Erstellen Sie eine Schaltfl�che zum Starten des Spiels
    RectangleShape startButton(Vector2f(200, 100));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(300, 250); // Positionieren Sie die Schaltfl�che in der Mitte des Fensters
    
    // Erstellen Sie eine Schaltfl�che zum Beenden des Spiels
    RectangleShape exitButton(Vector2f(200, 100));
    exitButton.setFillColor(Color::Red);
    exitButton.setPosition(300, 500); 

    // Schriftart
    Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) 
        std::cout << "Fehlermeldung: Schriftart Arial konnte nicht geladen werden!" << std::endl;

    // Start Buttontext 
    Text startButtonText("Start", font);
    startButtonText.setCharacterSize(24);
    startButtonText.setFillColor(Color::Black);
    startButtonText.setPosition(startButton.getPosition().x + 20, startButton.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Exit Buttontext 
    Text exitButtonText("Exit", font);
    exitButtonText.setCharacterSize(24);
    exitButtonText.setFillColor(Color::Black);
    exitButtonText.setPosition(exitButton.getPosition().x + 20, exitButton.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Erstellen Sie einen Booleschen Wert, um zu �berpr�fen, ob das Spiel gestartet wurde
    bool gameStarted = false;

    Ball* ball = new Ball(200, 200, 5);
   
    // Spiel-Schleife
    while (meinSpieleFenster->isOpen()) {   // Solange das Spielfenster ge�ffnet ist, mache ....
        
        // User-Eingaben als "Ereginisse" auswerten:
        Event event;                        // Um Ereignisse abzurufen, die vom Benutzer ausgel�st wurden, wie z.B. Tastendr�cke, Mausklicks oder das Schlie�en des Fensters.
        while (meinSpieleFenster->pollEvent(event)) {
           // �berpr�ft, ob das Spielfenster geschlossen wird
            if (event.type == Event::Closed)
                meinSpieleFenster->close();

            // �berpr�fen Sie, ob die linke Maustaste gedr�ckt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // �berpr�fen Sie, ob die Maus auf der Schaltfl�che ist
                if (startButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    gameStarted = true;
                }

                // �berpr�fen Sie, ob die Maus auf dem Beenden-Button ist
                if (exitButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    meinSpieleFenster->close();
                }
            } 
        }

        // Spielfeldbegrenzung
        // Ballumkehr beim Treffen des oberer und unterer Randes
        if (ball->getPosition().top             // gibt die y-Position des oberen Randes des Balls zur�ck
            + ball->getPosition().height        // ist die H�he des Balls
            > meinSpieleFenster->getSize().y    // ist die H�he des Fensters
            || ball->getPosition().top < 0) {   // y-Achse Position 0, also ganz links 
            ball->reboundBatOrTop();            // Dann Richtungs�nderung
        }
        
        // Ballumkehr beim Treffen des linken und rechten Randes
        if (ball->getPosition().left < 0        // wenn Ball kleiner als 0 ist, ber�hrt der Ball den linken Rand des Fensters
            || ball->getPosition().left + ball->getPosition().width    // gr��er als die Breite des Fensters + Ballbreite 
        > meinSpieleFenster->getSize().x) {     // ber�hrt der Ball den rechten Rand des Fensters
            ball->reboundSides();
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
            gameplay(meinSpieleFenster, ball);

        }
    }

    return 0;
}

void gameplay(sf::RenderWindow* meinSpieleFenster, Ball* ball) {
    ball->update();
    meinSpieleFenster->clear();
    meinSpieleFenster->draw(ball->getShape());
    meinSpieleFenster->display();
}