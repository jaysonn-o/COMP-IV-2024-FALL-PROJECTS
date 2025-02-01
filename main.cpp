#include <SFML/Graphics.hpp>
#include <cstdlib>  // For EXIT_SUCCESS and EXIT_FAILURE
#include <iostream> // For std::cerr

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
    {
        std::cerr << "Error: Could not load sprite.png" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Sprite sprite(texture);
    
    // Set initial position for the sprite
    sprite.setPosition(400, 300);

    // Define the movement speed (fixed pixels per key press)
    float speed = 5.0f;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window on close event
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle keyboard input (move sprite directly)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.move(-speed, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.move(speed, 0); // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.move(0, -speed); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.move(0, speed); // Move down
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

