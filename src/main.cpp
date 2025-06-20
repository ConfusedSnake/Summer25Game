#include "game/game.h"
#include "entities/deck.h"

int main() {

    Deck deck;
    //deck.print();
    //std::cout << std::endl << " ----------------------" << std::endl;
    deck.shuffle();
    deck.print();
    //playGame();
    return 0;
}
