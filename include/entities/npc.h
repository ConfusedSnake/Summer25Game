#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "entities/bullet.h"


class NPC{
    private:
    sf::Texture texture;
    sf::Sprite sprite;
    float spriteSize = 64.f;
    float spriteScalar = 1.0f;

    sf::RectangleShape boundingRectangle;

    public:
    sf::Texture& getTexture() {return texture;}
    sf::Sprite& getSprite() {return sprite;}
    sf::RectangleShape& getBoundingRectangle(){return boundingRectangle;}

    NPC(std::string spritePath, int XIndex, int YIndex);

    void handleMovement();
    void draw(sf::RenderWindow& window);
};