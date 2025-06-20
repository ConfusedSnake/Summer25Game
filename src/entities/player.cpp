#include "entities/player.h"

Player::Player(std::string spritePath, int XIndex, int YIndex) : mag(10){
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

void Player::handleMovement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(0.f, -0.1f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(-0.1f, 0.f);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(0.f, 0.1f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(0.1f, 0.f);

    boundingRectangle.setPosition(sprite.getPosition());
}

void Player::draw(sf::RenderWindow& window){
    window.draw(sprite);
    window.draw(boundingRectangle);
}

void Player::handleShooting(NPC& enemy, bool& canShoot) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot) {
        auto newBullet = std::make_unique<Bullet>();
        newBullet->setInitPosition(getSprite().getPosition());
        newBullet->setDirection(enemy.getSprite().getPosition());

        if (getMag().tryAddBullet(std::move(newBullet))) {
            canShoot = false;
        } else if(canShoot == false){
            std::cout << "Magasin fullt!" << std::endl;
        }
    }
    getMag().updateBullets();
}

