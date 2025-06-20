#include "entities/npc.h"

NPC::NPC(std::string spritePath, int XIndex, int YIndex){
    if(texture.loadFromFile(spritePath)){
        std::cout << "Player Images Loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(spriteSize * XIndex, spriteSize*YIndex, spriteSize, spriteSize));
        sprite.scale(sf::Vector2f(spriteScalar,spriteScalar));

    } else {std::cout << "Player image failed to load" << std::endl;}

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(2);
    boundingRectangle.setSize(sf::Vector2f(spriteSize, spriteSize));
    boundingRectangle.scale(sprite.getScale());
}

void NPC::handleMovement(){
    boundingRectangle.setPosition(sprite.getPosition());
}

void NPC::draw(sf::RenderWindow& window){
    window.draw(sprite);
    window.draw(boundingRectangle);
}
