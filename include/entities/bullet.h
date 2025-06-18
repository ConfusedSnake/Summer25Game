#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "entities/player.h"

class Bullet{
    private:

    float bulletSpeed;
    sf::Vector2f direction;

    public:
    sf::RectangleShape bull;

    Bullet();
    
    void setDirection(sf::Vector2f dir);
    void setInitPosition(sf::Vector2f pos);
    void bulletMove();
    void draw(sf::RenderWindow& window, std::vector<std::unique_ptr<Bullet>> bullets);
};
