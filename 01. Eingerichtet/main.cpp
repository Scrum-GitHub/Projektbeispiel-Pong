
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

int main()
{   
    
    // Schriftart
    Font font;
    font.loadFromFile("fonts/arial.ttf");

    // Label 
    Text text("Start", font);
    text.setCharacterSize(30);


    // Spielefenster erstellen
    RenderWindow meinSpieleFenster(VideoMode(800, 800), "Pong");
    meinSpieleFenster.setFramerateLimit(30);

    while (meinSpieleFenster.isOpen()) {

       
        meinSpieleFenster.clear();
        meinSpieleFenster.draw(text);
        meinSpieleFenster.display();
    }

    return 0;
}