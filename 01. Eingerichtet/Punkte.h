#pragma once
class Punkte {
private:
    int punktzahl;

public:
    Punkte() {
        punktzahl = 0;
    }

    void erhoehe() {
        punktzahl++;
    }

    int getPunkte() {
        return punktzahl;
    }


};

