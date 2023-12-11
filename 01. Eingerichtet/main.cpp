
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;


int main()
{   
    // Spielefenster erstellen
    RenderWindow meinSpieleFenster(VideoMode(800, 600), "Pong");
    meinSpieleFenster.setFramerateLimit(30);

    // Erstellen Sie eine Schaltfläche
    RectangleShape buttonStart(Vector2f(200, 100));
    buttonStart.setFillColor(Color::Green);
    buttonStart.setPosition(300, 250); // Positionieren Sie die Schaltfläche in der Mitte des Fensters
    
    // Schriftart
    Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) 
        std::cout << "Fehlermeldung: Schriftart Arial konnte nicht geladen werden!" << std::endl;

    // Buttontext 
    Text buttonText("Start das Spiel!", font);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(Color::Black);
    buttonText.setPosition(buttonStart.getPosition().x + 20, buttonStart.getPosition().y + 30); // Positionieren Sie den Text in der Mitte des Buttons

    // Erstellen Sie einen Booleschen Wert, um zu überprüfen, ob das Spiel gestartet wurde
    bool gameStarted = false;

    // Spiel-Schleife
    while (meinSpieleFenster.isOpen()) {
        Event event;
        while (meinSpieleFenster.pollEvent(event)) {
            if (event.type == Event::Closed)
                meinSpieleFenster.close();

            // Überprüfen Sie, ob die linke Maustaste gedrückt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // Überprüfen Sie, ob die Maus auf der Schaltfläche ist
                if (buttonStart.getGlobalBounds().contains(meinSpieleFenster.mapPixelToCoords(Mouse::getPosition(meinSpieleFenster)))) {
                    gameStarted = true;
                }
            }
        }

        meinSpieleFenster.clear();

        // Zeichnen Sie die Schaltfläche nur, wenn das Spiel nicht gestartet wurde
        if (!gameStarted) {
            meinSpieleFenster.draw(buttonStart);
            meinSpieleFenster.draw(buttonText);
        }

        // Hier könnte die Spiellogik hinzugefügt werden

        meinSpieleFenster.display();
    }

    return 0;
}
/*
In diesem Code erstellen wir ein Fenster und eine Schaltfläche.Dann starten wir eine Schleife, 
um auf Ereignisse zu warten.Wenn die linke Maustaste gedrückt wird und die Position der Maus 
innerhalb der Grenzen der Schaltfläche liegt, setzen wir gameStarted auf true.Die Schaltfläche 
wird nur gezeichnet, wenn das Spiel nicht gestartet wurde.

Dieser Code lädt eine Schriftart aus einer Datei und erstellt ein sf::Text-Objekt mit dieser Schriftart. 
Der Text wird dann auf den Button positioniert. Beachte, dass du den Pfad zur Schriftartendatei anpassen 
musst, damit sie korrekt geladen wird.
*/