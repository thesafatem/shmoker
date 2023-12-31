#pragma once
#include "suit.h"
#include "value.h"

class Card {
public:
    Value value;
    Suit suit;

    Card(Value value, Suit suit);
    bool equals(Card const& rhs) const;

    bool operator>(Card const& rhs) const;
    bool operator>=(Card const& rhs) const;
    bool operator<(Card const& rhs) const;
    bool operator<=(Card const& rhs) const;
    bool operator==(Card const& rhs) const;
    bool operator!=(Card const& rhs) const;
    operator std::string() const;

    friend std::ostream & operator <<(std::ostream &out, const Card &card);
};