
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;


int main()
{   
    // Spielefenster erstellen
    RenderWindow meinSpieleFenster(VideoMode(800, 600), "Pong");
    meinSpieleFenster.setFramerateLimit(30);

    // Erstellen Sie eine Schaltfl�che zum Starten des Spiels
    RectangleShape startButton(Vector2f(200, 100));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(300, 250); // Positionieren Sie die Schaltfl�che in der Mitte des Fensters
    
    // Erstellen Sie eine Schaltfl�che zum Beenden des Spiels
    sf::RectangleShape exitButton(sf::Vector2f(200, 100));
    exitButton.setFillColor(sf::Color::Red);
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

    // Spiel-Schleife
    while (meinSpieleFenster.isOpen()) {
        Event event;
        while (meinSpieleFenster.pollEvent(event)) {
            if (event.type == Event::Closed)
                meinSpieleFenster.close();

            // �berpr�fen Sie, ob die linke Maustaste gedr�ckt wurde
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // �berpr�fen Sie, ob die Maus auf der Schaltfl�che ist
                if (startButton.getGlobalBounds().contains(meinSpieleFenster.mapPixelToCoords(Mouse::getPosition(meinSpieleFenster)))) {
                    gameStarted = true;
                }

                // �berpr�fen Sie, ob die Maus auf dem Beenden-Button ist
                if (exitButton.getGlobalBounds().contains(meinSpieleFenster.mapPixelToCoords(Mouse::getPosition(meinSpieleFenster)))) {
                    meinSpieleFenster.close();
                }
            }
        }

        meinSpieleFenster.clear();

        // Zeichnen Sie die Schaltfl�che nur, wenn das Spiel nicht gestartet wurde
        if (!gameStarted) {
            meinSpieleFenster.draw(startButton);
            meinSpieleFenster.draw(startButtonText);
        }

        // Hier k�nnte die Spiellogik hinzugef�gt werden
        
        meinSpieleFenster.draw(exitButton);
        meinSpieleFenster.draw(exitButtonText);

        

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