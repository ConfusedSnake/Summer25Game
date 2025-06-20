#include <vector>
#include <map>
#include <random>
#include <iostream>

class Deck{
    public:
    enum class Navigation{
        pirate,
        sailor,
        cult
    };

    enum class Action{
        drunk,
        mermaid,
        telescope,
        armed,
        disarmed,
        cultUprising
    };

    struct Card{
        Navigation navigation;
        Action action;

        bool operator<(const Card& other) const {
            if (navigation != other.navigation)
                return navigation < other.navigation;
            return action < other.action;
        }

    };

    std::map<Card, int> cardAmount = {
        {{Navigation::cult, Action::cultUprising}, 6}, 
        {{Navigation::sailor, Action::drunk}, 5},
        {{Navigation::sailor, Action::disarmed}, 2},
        {{Navigation::pirate, Action::drunk}, 5},
        {{Navigation::pirate, Action::mermaid}, 2},
        {{Navigation::pirate, Action::telescope}, 2},
        {{Navigation::pirate, Action::armed}, 2}
    };


    Deck();

    std::vector<std::unique_ptr<Card>>& getDrawDeck(){return drawDeck;}
    std::vector<std::unique_ptr<Card>>& getSeaDeck(){return seaDeck;}


    void swap(int index1, int index2);
    std::string toString(Navigation nav);
    std::string toString(Action act);
    void print();
    void shuffle();

    private:
    std::vector<std::unique_ptr<Card>> drawDeck;
    std::vector<std::unique_ptr<Card>> seaDeck;
    int totalCards;

};