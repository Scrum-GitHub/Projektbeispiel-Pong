#pragma once
#include "Punkte.h"
#include <SFML/Graphics.hpp>

class Schlaeger {
private:
    sf::Vector2f position;
    sf::RectangleShape schlaegerShape;
    float speed = 20.0f;
    Punkte* punkte;

public:
    Schlaeger(float startX, float startY, float width, float height) {
        position.x = startX;
        position.y = startY;

        schlaegerShape.setSize(sf::Vector2f(width, height));
        schlaegerShape.setPosition(position);

        punkte = new Punkte();
    }

    // Methode zum Abrufen der globalen Grenzen des Schlaegers
    sf::FloatRect getPosition() {
        return schlaegerShape.getGlobalBounds();
    }

    sf::RectangleShape getShape() {
        return schlaegerShape;
    }

    void moveUp() {
        if (position.y > 0) {
            position.y -= speed;
            schlaegerShape.setPosition(position);
        }
    }

    void moveDown(float windowHeight) {
        if (position.y + schlaegerShape.getSize().y < windowHeight) {
            position.y += speed;
            schlaegerShape.setPosition(position);
        }
    }

    Punkte* getPunkteObj() {
        return punkte;
    }

    void setPunkteObj(Punkte* p) {
        punkte = p;
    }
};

/*
In dieser Klasse repräsentiert `position` die aktuelle Position des Schlägers und `schlaegerShape` ist 
das SFML - `RectangleShape`-Objekt, das den Schläger darstellt. `speed` ist die Geschwindigkeit, 
mit der der Schläger sich bewegt.

Die Methoden `moveUp` und `moveDown` ändern die y - Position des Schlägers, um ihn nach oben bzw.unten 
zu bewegen.Diese Methoden überprüfen auch, ob der Schläger innerhalb des Fensters bleibt, und verhindern, 
dass er über den oberen oder unteren Rand hinausgeht.

Bitte beachten Sie, dass Sie den Aufruf dieser Methoden in Ihrer Hauptschleife mit den entsprechenden 
Tastatureingaben verbinden müssen, um den Schläger tatsächlich zu bewegen.
*/