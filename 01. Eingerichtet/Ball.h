#include <random>
#include <SFML/Graphics.hpp>
#include <cstdlib>


class Ball {
private:
    sf::Vector2f position;
    sf::CircleShape ballShape;
    float xVelocity = 0.0f;
    float yVelocity = 0.0f;

public:
    Ball(float startX, float startY, float radius) {
        position.x = startX;
        position.y = startY;

        ballShape.setRadius(radius);
        ballShape.setPosition(position);
        this->setRandomSpeed(25.0f); // Der Ball bewegt sich in eine zufällige Richtung.
    }

    sf::FloatRect getPosition() {
        return ballShape.getGlobalBounds();
    }

    sf::CircleShape getShape() {
        return ballShape;
    }

    float getXVelocity() {
        return xVelocity;
    }

    void reboundSides() { //Bewegungsrichtung des Balls in der x-Achse umkehrt
        xVelocity = -xVelocity;
    }
    /*
    Diese Methode ändert die Richtung der y-Geschwindigkeit des Balls, 
    was dazu führt, dass der Ball "abprallt" und in die entgegengesetzte 
    y-Richtung bewegt wird.
    */
    void reboundBatOrTop() { // Richtungsänderung vom "Schläger" oder "Oben"
        yVelocity = -yVelocity;
    }

    void update() {
        position.y += yVelocity;
        position.x += xVelocity;

        ballShape.setPosition(position);
    }

    void setRandomSpeed(float speed) {
        std::random_device rd;  // Zufallszahlengenerator initialisieren
        std::mt19937 gen(rd()); // Mersenne-Twister-Generator verwenden
        std::uniform_real_distribution<> dis(-1.0, 1.0); // Verteilung definieren

        xVelocity = speed * dis(gen); // Zufällige x-Geschwindigkeit setzen
        yVelocity = speed * dis(gen); // Zufällige y-Geschwindigkeit setzen
    }
};