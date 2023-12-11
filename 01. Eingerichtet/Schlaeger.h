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
In dieser Klasse repr�sentiert `position` die aktuelle Position des Schl�gers und `schlaegerShape` ist 
das SFML - `RectangleShape`-Objekt, das den Schl�ger darstellt. `speed` ist die Geschwindigkeit, 
mit der der Schl�ger sich bewegt.

Die Methoden `moveUp` und `moveDown` �ndern die y - Position des Schl�gers, um ihn nach oben bzw.unten 
zu bewegen.Diese Methoden �berpr�fen auch, ob der Schl�ger innerhalb des Fensters bleibt, und verhindern, 
dass er �ber den oberen oder unteren Rand hinausgeht.

Bitte beachten Sie, dass Sie den Aufruf dieser Methoden in Ihrer Hauptschleife mit den entsprechenden 
Tastatureingaben verbinden m�ssen, um den Schl�ger tats�chlich zu bewegen.
*/