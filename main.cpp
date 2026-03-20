#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Enigma Shell", sf::Style::Close);
    window.setFramerateLimit(60);

    bool lampOn = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                lampOn = true;

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                lampOn = false;
        }

        window.clear(sf::Color(30, 28, 26));

        // Lamp
        sf::CircleShape lamp(40);
        lamp.setPosition(160, 160);
        lamp.setFillColor(lampOn ? sf::Color(255, 230, 100) : sf::Color(50, 50, 40));
        lamp.setOutlineColor(sf::Color(90, 80, 65));
        lamp.setOutlineThickness(2);
        window.draw(lamp);

        window.display();
    }

    return 0;
}
