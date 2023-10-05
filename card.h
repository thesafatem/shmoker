#pragma once
#include "suit.h"
#include "value.h"

class Card {
public:
    Value value;
    Suit suit;

    Card(Value value, Suit suit);
    bool operator>(Card const& card);
    bool operator>=(Card const& card);
    bool operator<(Card const& card);
    bool operator<=(Card const& card);
    bool operator==(Card const& card);
};