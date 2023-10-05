#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    std::vector<Value> ALL_VALUES = {
        Value::Two, 
        Value::Three, 
        Value::Four, 
        Value::Five, 
        Value::Six, 
        Value::Seven, 
        Value::Eight, 
        Value::Nine, 
        Value::Ten, 
        Value::Jack, 
        Value::Queen, 
        Value::King, 
        Value::Ace
    }; 
    std::vector<Suit> ALL_SUITES = {
        Suit::Spades, 
        Suit::Clubs, 
        Suit::Hearts, 
        Suit::Diamonds
    };
    this->cards = {};
    for (Value value : ALL_VALUES) {
        for (Suit suit : ALL_SUITES) {
            this->cards.push_back(Card(value, suit));
        }
    }
    shuffle();
};

void Deck::shuffle() {
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
}

Card Deck::popCard() {
    Card lastCard = this->cards.back();
    this->cards.pop_back();
    return lastCard;
}