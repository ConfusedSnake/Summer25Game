#include "entities/deck.h"

Deck::Deck(){
    totalCards = 0;
    for(const auto& [key, value] : cardAmount){
        totalCards += value;
    }

    drawDeck.reserve(totalCards);
    seaDeck.reserve(totalCards);

    for(const auto& [key, value] : cardAmount){
        for(int i = 0; i < value; i++){
            drawDeck.push_back(std::make_unique<Card>(Card{key.navigation, key.action}));
        }
    }
}

void Deck::swap(int index1, int index2){
    std::swap(drawDeck.at(index1), drawDeck.at(index2));
}

void Deck::shuffle(){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0,totalCards-1);

    for (int i = 0; i < totalCards; i++){
        int random = distribution(generator);
        swap(i,random);
    }
}

void Deck::print(){
    for (int i = 0; i < drawDeck.size(); i++){ 
        std::cout << toString(drawDeck.at(i)->navigation) << ", " << toString(drawDeck.at(i)->action) << std::endl; 
    }
}

std::string Deck::toString(Navigation nav) {
    switch (nav) {
        case Navigation::pirate: return "pirate";
        case Navigation::sailor: return "sailor";
        case Navigation::cult: return "cult";
    }
    return "Unknown";
}

std::string Deck::toString(Action act) {
    switch (act) {
        case Action::drunk: return "drunk";
        case Action::mermaid: return "mermaid";
        case Action::telescope: return "telescope";
        case Action::armed: return "armed";
        case Action::disarmed: return "disarmed";
        case Action::cultUprising: return "cult uprising";
    }
    return "Unknown";
}

