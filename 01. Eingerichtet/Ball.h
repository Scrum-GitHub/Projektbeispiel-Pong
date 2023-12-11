#include <random>
#include <SFML/Graphics.hpp>
#include <cstdlib>


class Ball {
private:
    sf::Vector2f position;
    sf::CircleShape ballShape;
    float xSpeed = 0.0f;
    float ySpeed = 0.0f;

public:
    Ball(float startX, float startY, float radius) {
        position.x = startX;
        position.y = startY;

        ballShape.setRadius(radius);
        ballShape.setPosition(position);
        this->setRandomSpeed(15.0f); // Der Ball bewegt sich in eine zufällige Richtung.
    }

    sf::FloatRect getPosition() {
        return ballShape.getGlobalBounds();
    }

    sf::CircleShape getShape() {
        return ballShape;
    }

    // Methode zum Abrufen der globalen Grenzen des Balls
    sf::FloatRect getGlobalBounds() {
        return ballShape.getGlobalBounds();
    }

    float getXSpeed() {
        return xSpeed;
    }

    void reboundSides() { //Bewegungsrichtung des Balls in der x-Achse umkehrt
        xSpeed = -xSpeed;
    }
    /*
    Diese Methode ändert die Richtung der y-Geschwindigkeit des Balls, 
    was dazu führt, dass der Ball "abprallt" und in die entgegengesetzte 
    y-Richtung bewegt wird.
    */
    void reboundBatOrTop() { // Richtungsänderung vom "Schläger" oder "Oben"
        ySpeed = -ySpeed;
    }

    void setPosition(float startX, float startY) {
        position.x = startX;
        position.y = startY;
    }

    void update() {
        position.y += ySpeed;
        position.x += xSpeed;

        ballShape.setPosition(position);
    }

    void setRandomSpeed(float speed) {
        std::random_device rd;  // Zufallszahlengenerator initialisieren
        std::mt19937 gen(rd()); // Mersenne-Twister-Generator verwenden
        std::uniform_real_distribution<> dis(-1.0, 1.0); // Verteilung definieren

        xSpeed = speed * dis(gen); // Zufällige x-Geschwindigkeit setzen
        ySpeed = speed * dis(gen); // Zufällige y-Geschwindigkeit setzen
    }
};