#pragma once
#include <vector>
#include "card.h"

class Deck {
public:
    // std::vector<Card> cards;

    Deck();
    Card popCard();

private:
    std::vector<Card> cards;
    
    void shuffle();
};