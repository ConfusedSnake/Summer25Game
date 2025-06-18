#include <SFML/Graphics.hpp>
#include <iostream>

//music
#include <thread>
#include <chrono>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

int main() {

    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800,600), "window", sf::Style::Default, setting);
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100,100));
 
    sf::RectangleShape rectangle(sf::Vector2f(100,50));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }   
        }


        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.display();


    }
    

    

    return 0;
}
