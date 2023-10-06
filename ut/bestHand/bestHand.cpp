#define BOOST_TEST_MODULE boost_test_best_hand
#include <boost/test/included/unit_test.hpp>
#include "../../handRankings.cpp"
#include "../../card.cpp"

BOOST_AUTO_TEST_CASE(test_higher_pair) {
    std::vector<Card> table = {
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Three, Suit::Hearts),
        Card(Value::Six, Suit::Hearts),
        Card(Value::Queen, Suit::Clubs),
        Card(Value::Five, Suit::Spades),
    };

    std::vector<Card> hand1 = {
        Card(Value::Six, Suit::Hearts),
        Card(Value::King, Suit::Clubs),
    };

    std::vector<Card> hand2 = {
        Card(Value::Ace, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds)
    };

    hand1.insert(hand1.end(), table.begin(), table.end());
    hand2.insert(hand2.end(), table.begin(), table.end());

    BestHand bh1 = HandRankings::getBestHand(hand1);
    BestHand bh2 = HandRankings::getBestHand(hand2);

    BOOST_TEST(bh1 < bh2);
}

BOOST_AUTO_TEST_CASE(test_one_pair_with_kicker) {
    std::vector<Card> table = {
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Three, Suit::Hearts),
        Card(Value::Six, Suit::Hearts),
        Card(Value::Queen, Suit::Clubs),
        Card(Value::King, Suit::Spades),
    };

    std::vector<Card> hand1 = {
        Card(Value::Ace, Suit::Hearts),
        Card(Value::Seven, Suit::Clubs),
    };

    std::vector<Card> hand2 = {
        Card(Value::Ace, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds)
    };

    hand1.insert(hand1.end(), table.begin(), table.end());
    hand2.insert(hand2.end(), table.begin(), table.end());

    BestHand bh1 = HandRankings::getBestHand(hand1);
    BestHand bh2 = HandRankings::getBestHand(hand2);

    BOOST_TEST(bh1 < bh2);
}

BOOST_AUTO_TEST_CASE(test_one_pair_chop_chop) {
    std::vector<Card> table = {
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Three, Suit::Hearts),
        Card(Value::Six, Suit::Hearts),
        Card(Value::Queen, Suit::Clubs),
        Card(Value::King, Suit::Spades),
    };

    std::vector<Card> hand1 = {
        Card(Value::Ace, Suit::Hearts),
        Card(Value::Four, Suit::Clubs),
    };

    std::vector<Card> hand2 = {
        Card(Value::Ace, Suit::Spades),
        Card(Value::Two, Suit::Diamonds)
    };

    hand1.insert(hand1.end(), table.begin(), table.end());
    hand2.insert(hand2.end(), table.begin(), table.end());

    BestHand bh1 = HandRankings::getBestHand(hand1);
    BestHand bh2 = HandRankings::getBestHand(hand2);

    BOOST_TEST(bh1 == bh2);
}

BOOST_AUTO_TEST_CASE(test_two_pair_over_one_pair) {
    std::vector<Card> table = {
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Three, Suit::Hearts),
        Card(Value::Six, Suit::Hearts),
        Card(Value::Queen, Suit::Clubs),
        Card(Value::King, Suit::Spades),
    };

    std::vector<Card> hand1 = {
        Card(Value::Ace, Suit::Hearts),
        Card(Value::Four, Suit::Clubs),
    };

    std::vector<Card> hand2 = {
        Card(Value::Three, Suit::Spades),
        Card(Value::Six, Suit::Diamonds)
    };

    hand1.insert(hand1.end(), table.begin(), table.end());
    hand2.insert(hand2.end(), table.begin(), table.end());

    BestHand bh1 = HandRankings::getBestHand(hand1);
    BestHand bh2 = HandRankings::getBestHand(hand2);

    BOOST_TEST(bh1 < bh2);
}