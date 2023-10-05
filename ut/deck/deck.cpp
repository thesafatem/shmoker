#define BOOST_TEST_MODULE boost_test_deck
#include <boost/test/included/unit_test.hpp>
#include "../../deck.cpp"
#include "../../card.cpp"

BOOST_AUTO_TEST_CASE(test_deck) {
    Deck deck = Deck();
    std::vector<Card> cards;
    while (true) {
        Card card = deck.popCard();
        if (card.value != Value::NO && card.suit != Suit::NO) {
            cards.push_back(card);
        } else {
            break;
        }
    }
    BOOST_TEST(cards.size() == 52, "Cards should be 52 in total. There are " << cards.size() << " cards in the deck.");
    int collisions = 0;
    for (int i = 0; i < cards.size(); i++) {
        for (int j = i + 1; j < cards.size(); j++) {
            if (cards[i] == cards[j] && cards[i].suit == cards[j].suit) {
                collisions++;
            }
        }
    }
    BOOST_TEST(collisions == 0, "There should be no collisions. Collisions: " << collisions << ".");
}