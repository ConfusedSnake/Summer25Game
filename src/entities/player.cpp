#include "entities/player.h"

Player::Player(std::string spritePath, int XIndex, int YIndex){
    if(playerTexture.loadFromFile(spritePath)){
        std::cout << "Player Images Loaded" << std::endl;
        playerSprite.setTexture(playerTexture);

        int spriteSize = 64;
        playerSprite.setTextureRect(sf::IntRect(spriteSize * XIndex, spriteSize*YIndex, spriteSize, spriteSize));
        playerSprite.scale(sf::Vector2f(1,1));

    } else {std::cout << "Player image failed to load" << std::endl;}
}

void Player::handleMovement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        playerSprite.move(0.f, -0.1f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        playerSprite.move(-0.1f, 0.f);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        playerSprite.move(0.f, 0.1f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        playerSprite.move(0.1f, 0.f);
}

void Player::draw(sf::RenderWindow& window){
    window.draw(playerSprite);
}