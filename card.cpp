#include "card.h"

Card::Card(Value value, Suit suit) 
: value(value)
, suit(suit) { };

bool Card::operator>(Card const& card) {
    return this->value > card.value;
}

bool Card::operator>=(Card const& card) {
    return this->value >= card.value;
}

bool Card::operator<(Card const& card) {
    return this->value < card.value;
}

bool Card::operator<=(Card const& card) {
    return this->value <= card.value;
}

bool Card::operator==(Card const& card) {
    return this->value == card.value;
}