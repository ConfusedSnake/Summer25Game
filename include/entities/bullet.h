#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

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
    void draw(sf::RenderWindow& window);
};


class Mag{
    private:
    size_t capacity;
    std::vector<std::unique_ptr<Bullet>> bullets;
    

    public:
    Mag(size_t cap);
    Mag& operator=(const Mag&) = delete;
    
    bool tryAddBullet(std::unique_ptr<Bullet> bullet);
    std::vector<std::unique_ptr<Bullet>>& getBullets() { return bullets; }
    void updateBullets();
    void draw(sf::RenderWindow& window);
};