#include <SFML/Graphics.hpp>
#include <cstdlib>


class Ball {
private:
    sf::Vector2f position;
    sf::RectangleShape ballShape;
    float xVelocity = 0.2f;
    float yVelocity = 0.2f;

public:
    Ball(float startX, float startY) {
        position.x = startX;
        position.y = startY;

        ballShape.setSize(sf::Vector2f(10, 10));
        ballShape.setPosition(position);
    }

    sf::FloatRect getPosition() {
        return ballShape.getGlobalBounds();
    }

    sf::RectangleShape getShape() {
        return ballShape;
    }

    float getXVelocity() {
        return xVelocity;
    }

    void reboundSides() {
        xVelocity = -xVelocity;
    }

    void reboundBatOrTop() {
        position.y = -position.y;
    }

    void update() {
        position.y += yVelocity;
        position.x += xVelocity;

        ballShape.setPosition(position);
    }
};