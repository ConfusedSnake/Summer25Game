#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/npc.h"
#include "game/math.h"


void playGame();
sf::ContextSettings settings();
