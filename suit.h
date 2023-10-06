#pragma once

enum class Suit {
    NO,
    Spades,
    Clubs,
    Hearts,
    Diamonds
};

std::string toString(Suit suit) {
    switch (suit) {
        case Suit::Spades:
            return "♠";
            break;
        case Suit::Clubs:
            return "♣";
            break;
        case Suit::Hearts:
            return "♡";
            break;
        case Suit::Diamonds:
            return "♢";
            break;
        default:
            return "X";
    }
}