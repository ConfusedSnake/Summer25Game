#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Player{
    private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    
    public:
    sf::Texture getTexture(){return playerTexture;}
    sf::Sprite getSprite(){return playerSprite;}
    
    Player(std::string spritePath, int XIndex, int YIndex);
    void handleMovement();
    void draw(sf::RenderWindow& window);
};