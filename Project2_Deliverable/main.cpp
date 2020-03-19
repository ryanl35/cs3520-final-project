#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

int main()
{

    // define constants
    const int posVelocity = 5;
    const int negVelocity = -5;
    const int height = 600;
    const int width = 350;
    const int shapeSize = 10;

    // Renders a window with a specified size, titles it "SFML Works!"
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    // initalizes a Circle with the Color Green
    sf::CircleShape shape(shapeSize);
    shape.setFillColor(sf::Color::Green);
    // sets the initial position to be at the bottom of the screen
    shape.setPosition(width / 2, height - (shapeSize * 2));

    // Uses the Music feature of SFML by opening a specific file
    sf::Music music;
    if (!music.openFromFile("Electro music for Doodle Jump.wav"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    // sets a loop for the music so the music continues playing for the duration of the game
    music.setLoop(true);

    // a while loop while the window / game is in session
    while (window.isOpen())
    {
        // instantiates an instance of what's known as an "Event"
        // an Event can be a mouse pressed, moved, key pressed, etc. anything that makes the game interactive
        sf::Event event;

        // while loop .. while there are events left to do... essentially allows Events to be made
        while (window.pollEvent(event))
        {
            // what to do if the user closes the window ... the window closes
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // what to do if the Event is the user is pressing a key
            else if (event.type == sf::Event::KeyPressed)
            {
                // all of these check the key code of the Event, which is essentially checking what key was pressed

                // changes the Circle to Blue if the user presses the Spacebar
                if (event.key.code == sf::Keyboard::Space)      { shape.setFillColor(sf::Color::Blue); } 
                // changes the Circle to Red if the user presses the W key
                else if (event.key.code == sf::Keyboard::W)     { shape.setFillColor(sf::Color::Red); } 
                // changes the Circle to Green if the user presses the N key
                else if (event.key.code == sf::Keyboard::N)     { shape.setFillColor(sf::Color::Green); } 

                // handles moving the player when the user presses any of the arrow keys
                else if (event.key.code == sf::Keyboard::Left)  { shape.move(negVelocity, 0); }
                else if (event.key.code == sf::Keyboard::Right) { shape.move(posVelocity, 0); }
                else if (event.key.code == sf::Keyboard::Up)    { shape.move(0, negVelocity); }
                else if (event.key.code == sf::Keyboard::Down)  { shape.move(0, posVelocity); }
            }

            // what to do when the mouse is moved within the window
            else if (event.type == sf::Event::MouseMoved)
            {
                // moves the x position so it follows the mouse wherever it goes
                // does NOT follow it's y position (keeps the current y position by using getPosition())
                // keeps y position because in Doodle Jump the player CANNOT control the y position of the player
                shape.setPosition(event.mouseMove.x, shape.getPosition().y);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}