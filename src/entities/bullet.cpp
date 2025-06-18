#include "entities/bullet.h"

Bullet::Bullet() {
    bull = sf::RectangleShape(sf::Vector2f(10.f, 5.f));
    bulletSpeed = 1.f;
    direction = sf::Vector2f(0.f, 0.f);
}

void Bullet::setDirection(sf::Vector2f dir){
    direction = dir-bull.getPosition();
    direction = direction/(std::sqrt(direction.x*direction.x+direction.y*direction.y));
}

void Bullet::setInitPosition(sf::Vector2f pos){
    bull.setPosition(pos);
}

void Bullet::bulletMove(){
    bull.move(direction*bulletSpeed);
}
