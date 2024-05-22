#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "SFML Window");

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Blue);


        // Draw
        
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(300, 200); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.3, 0.3); // Scale factor

        window->draw(outscal_sprite);

        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("Hello SFML!", font, 30);
        text.setFillColor(sf::Color::Red);
        window->draw(text);


        // Display what was drawn
        window->display();
    }

    return 0;
}