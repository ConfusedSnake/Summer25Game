#include "game/math.h"

bool Math::checkRectCollision(sf::RectangleShape rect1, sf::RectangleShape rect2){
    if(rect1.getGlobalBounds().left + rect1.getGlobalBounds().width > rect2.getGlobalBounds().left
        && rect2.getGlobalBounds().left + rect2.getGlobalBounds().width > rect1.getGlobalBounds().left
        && rect2.getGlobalBounds().top + rect2.getGlobalBounds().height > rect1.getGlobalBounds().top
        && rect1.getGlobalBounds().top + rect1.getGlobalBounds().height > rect2.getGlobalBounds().top){
            
        return true;
    }

    return false;
}