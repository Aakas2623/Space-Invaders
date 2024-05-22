#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        

        // Clear the window
        window->clear(sf::Color::Yellow);

        // Draw your content here...
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 300); // Set position
        window->draw(circle);

        sf::RectangleShape rectangle(sf::Vector2f(70,50)); // Radius 50
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(10,10); // Set position
        window->draw(rectangle);

        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(200, 250));
        triangle.setPoint(1, sf::Vector2f(250, 300));
        triangle.setPoint(2, sf::Vector2f(300, 200));
        triangle.setFillColor(sf::Color::Blue);
        window->draw(triangle);

        // Display what was drawn
        window->display();
    }

    return 0;
}