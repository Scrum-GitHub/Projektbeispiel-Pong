
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;


int main()
{   
    // Spielefenster erstellen
    RenderWindow meinSpieleFenster(VideoMode(800, 600), "Pong");
    meinSpieleFenster.setFramerateLimit(30);

    // Erstellen Sie eine Schaltfl�che
    RectangleShape buttonStart(Vector2f(200, 100));
    buttonStart.setFillColor(Color::Green);
    buttonStart.setPosition(300, 250); // Positionieren Sie die Schaltfl�che in der Mitte des Fensters
    
    // Schriftart
    Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) 
        std::cout << "Fehlermeldung: Schriftart Arial konnte nicht geladen werden!" << std::endl;

    // Buttontext 
    Text buttonText("Start das Spiel!", font);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(Color::Black);
    buttonText.setPosition(buttonStart.getPosition().x + 20, buttonStart.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Erstellen Sie einen Booleschen Wert, um zu �berpr�fen, ob das Spiel gestartet wurde
    bool gameStarted = false;

    // Spiel-Schleife
    while (meinSpieleFenster.isOpen()) {
        Event event;
        while (meinSpieleFenster.pollEvent(event)) {
            if (event.type == Event::Closed)
                meinSpieleFenster.close();

            // �berpr�fen Sie, ob die linke Maustaste gedr�ckt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // �berpr�fen Sie, ob die Maus auf der Schaltfl�che ist
                if (buttonStart.getGlobalBounds().contains(meinSpieleFenster.mapPixelToCoords(Mouse::getPosition(meinSpieleFenster)))) {
                    gameStarted = true;
                }
            }
        }

        meinSpieleFenster.clear();

        // Zeichnen Sie die Schaltfl�che nur, wenn das Spiel nicht gestartet wurde
        if (!gameStarted) {
            meinSpieleFenster.draw(buttonStart);
            meinSpieleFenster.draw(buttonText);
        }

        // Hier k�nnte die Spiellogik hinzugef�gt werden

        meinSpieleFenster.display();
    }

    return 0;
}
/*
In diesem Code erstellen wir ein Fenster und eine Schaltfl�che.Dann starten wir eine Schleife, 
um auf Ereignisse zu warten.Wenn die linke Maustaste gedr�ckt wird und die Position der Maus 
innerhalb der Grenzen der Schaltfl�che liegt, setzen wir gameStarted auf true.Die Schaltfl�che 
wird nur gezeichnet, wenn das Spiel nicht gestartet wurde.

Dieser Code l�dt eine Schriftart aus einer Datei und erstellt ein sf::Text-Objekt mit dieser Schriftart. 
Der Text wird dann auf den Button positioniert. Beachte, dass du den Pfad zur Schriftartendatei anpassen 
musst, damit sie korrekt geladen wird.
*/