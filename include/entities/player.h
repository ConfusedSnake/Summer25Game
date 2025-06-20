#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "entities/bullet.h"
#include "entities/npc.h"

class Player{
    private:
    sf::Texture texture;
    sf::Sprite sprite;
    float spriteSize = 64.f;
    float spriteScalar = 1.0f;

    sf::RectangleShape boundingRectangle;
    Mag mag;

    float speed = 120.0f;

    int pistols = 3;

    std::unique_ptr<DutyBase> currentRole;

    public:
    sf::Texture& getTexture() {return texture;}
    sf::Sprite& getSprite() {return sprite;}
    sf::RectangleShape& getBoundingRectangle(){return boundingRectangle;}
    Mag& getMag() {return mag;}
    
    Player(std::string spritePath, int XIndex, int YIndex);

    void handleMovement(float deltaTime);
    void handleShooting(NPC& enemy, bool& canShoot, float deltaTime);
    void draw(sf::RenderWindow& window);


    void setRole(std::unique_ptr<DutyBase> newRole);
    void performRoleAction();
};

class DutyBase {
public:
    virtual ~DutyBase() = default;
    virtual void performAction(Player& player) = 0;
};

class CaptainRole : public DutyBase {
public:
    void performAction(Player& player) override {
        // kapteinens spesifikke oppførsel
    }
};

class NavigatorRole : public DutyBase {
public:
    void performAction(Player& player) override {
        // navigatørens oppførsel
    }
};
