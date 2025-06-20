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

void Bullet::draw(sf::RenderWindow& window){
    window.draw(bull);
}
Mag::Mag(size_t cap) : capacity(cap) {}

bool Mag::tryAddBullet(std::unique_ptr<Bullet> bullet) {
    if (bullets.size() < capacity) {
        bullets.push_back(std::move(bullet));
        return true;
    }
    return false;
}

void Mag::updateBullets() {
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [](const std::unique_ptr<Bullet>& b) {
                sf::Vector2f pos = b->bull.getPosition();
                return pos.x < 0 || pos.x > 800 || pos.y < 0 || pos.y > 600;
            }),
        bullets.end()
    );

    for (auto& bullet : bullets) {
        bullet->bulletMove();
    }
}

void Mag::draw(sf::RenderWindow& window) {
    for (auto& bullet : bullets) {
        bullet->draw(window);
    }
}

