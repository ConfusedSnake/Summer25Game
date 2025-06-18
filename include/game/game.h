#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "entities/player.h"
#include "entities/bullet.h"

void playGame();
void handleShooting(Player& player, Player& enemy, 
                    std::vector<std::unique_ptr<Bullet>>& bullets, 
                    bool& canShoot);
void updateBullets(std::vector<std::unique_ptr<Bullet>>& bullets);
