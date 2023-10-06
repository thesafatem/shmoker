#pragma once
#include <vector>
#include "../card/card.h"

class Deck {
public:
    Deck();
    Card popCard();

private:
    std::vector<Card> cards;
    
    void shuffle();
};