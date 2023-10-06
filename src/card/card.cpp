#include "card.h"

Card::Card(Value value, Suit suit) 
: value(value)
, suit(suit) { };

bool Card::equals(Card const& rhs) const {
    return this->value == rhs.value;
}

bool Card::operator>(Card const& rhs) const {
    return this->value > rhs.value;
}

bool Card::operator>=(Card const& rhs) const {
    return this->value >= rhs.value;
}

bool Card::operator<(Card const& rhs) const {
    return this->value < rhs.value;
}

bool Card::operator<=(Card const& rhs) const {
    return this->value <= rhs.value;
}

bool Card::operator==(Card const& rhs) const {
    return this->value == rhs.value && this->suit == rhs.suit;
}

bool Card::operator!=(Card const& rhs) const {
    return this->value != rhs.value || this->suit != rhs.suit;
}

Card::operator std::string() const {
    std::ostringstream out;
    out << *this;
    return out.str();
}

std::ostream & operator <<(std::ostream &out, const Card &card) {
    out << toString(card.value) << toString(card.suit);
    return out;
}