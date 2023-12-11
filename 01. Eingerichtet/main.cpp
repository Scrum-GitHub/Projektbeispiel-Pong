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

    Ball* ball = new Ball(200, 200);

    // Spiel-Schleife
    while (meinSpieleFenster->isOpen()) {
        Event event;
        while (meinSpieleFenster->pollEvent(event)) {
            if (event.type == Event::Closed)
                meinSpieleFenster->close();

            // Überprüfen Sie, ob die linke Maustaste gedrückt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // Überprüfen Sie, ob die Maus auf der Schaltfläche ist
                if (startButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    gameStarted = true;
                    break;
                }

                // Überprüfen Sie, ob die Maus auf dem Beenden-Button ist
                if (exitButton.getGlobalBounds().contains(meinSpieleFenster->mapPixelToCoords(Mouse::getPosition(*meinSpieleFenster)))) {
                    meinSpieleFenster->close();
                }
            } 
           
        }

        //meinSpieleFenster.clear();

        // Zeichnen Sie die Schaltfläche nur, wenn das Spiel nicht gestartet wurde
        if (!gameStarted) {
            meinSpieleFenster->draw(startButton);
            meinSpieleFenster->draw(startButtonText);
            
            gameplay(meinSpieleFenster, ball);

        } 
            meinSpieleFenster->draw(exitButton);
            meinSpieleFenster->draw(exitButtonText);
        
    }

    return 0;
}

void gameplay(sf::RenderWindow* meinSpieleFenster, Ball* ball) {
    ball->update();
    meinSpieleFenster->clear();
    meinSpieleFenster->draw(ball->getShape());
    meinSpieleFenster->display();
}