#define BOOST_TEST_MODULE boost_test_hand_rankings
#include <boost/test/included/unit_test.hpp>
#include "../../card.cpp"
#include "../../handRankings.cpp"

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_CASE(test_hand_rankings_high_card) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Jack, Suit::Clubs),
        Card(Value::Two, Suit::Hearts),
        Card(Value::Six, Suit::Spades),
        Card(Value::Nine, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Jack, Suit::Clubs),
        Card(Value::Ten, Suit::Diamonds),
        Card(Value::Nine, Suit::Diamonds),
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Six, Suit::Spades),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::HighCard),
        "Real: " << toString(HandRanking::OnePair) << ". Calculated: " << toString(bh.handRanking)
    );

    // TODO: good-styled messages
    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_one_pair) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Jack, Suit::Clubs),
        Card(Value::Ten, Suit::Hearts),
        Card(Value::Six, Suit::Spades),
        Card(Value::Nine, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Ten, Suit::Hearts),
        Card(Value::Ten, Suit::Diamonds),
        Card(Value::Jack, Suit::Clubs),
        Card(Value::Nine, Suit::Diamonds),
        Card(Value::Eight, Suit::Clubs),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::OnePair),
        "Real: " << toString(HandRanking::OnePair) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_two_pair) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Clubs),
        Card(Value::Two, Suit::Hearts),
        Card(Value::Six, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Two, Suit::Clubs),
        Card(Value::Two, Suit::Hearts),
        Card(Value::Ten, Suit::Diamonds)
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::TwoPair),
        "Real: " << toString(HandRanking::TwoPair) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_set) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Clubs),
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds)
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::Set),
        "Real: " << toString(HandRanking::Set) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_straight) {
    std::vector<Card> hand = {
        Card(Value::Nine, Suit::Clubs),
        Card(Value::Queen, Suit::Diamonds),
        Card(Value::Two, Suit::Clubs),
        Card(Value::Jack, Suit::Diamonds),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Queen, Suit::Diamonds),
        Card(Value::Jack, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
        Card(Value::Nine, Suit::Clubs),
        Card(Value::Eight, Suit::Spades),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::Straight),
        "Real: " << toString(HandRanking::Straight) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_flush) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Diamonds),
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Diamonds)
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::Flush),
        "Real: " << toString(HandRanking::Flush) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_full_house) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Clubs),
        Card(Value::Three, Suit::Hearts),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Ten, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Three, Suit::Hearts),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::FullHouse),
        "Real: " << toString(HandRanking::FullHouse) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_four_of_a_kind) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Eight, Suit::Hearts),
        Card(Value::Two, Suit::Diamonds),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Two, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Eight, Suit::Hearts),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Eight, Suit::Diamonds),
        Card(Value::Three, Suit::Diamonds),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::FourOfAKind),
        "Real: " << toString(HandRanking::FourOfAKind) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_straight_flush) {
    std::vector<Card> hand = {
        Card(Value::Eight, Suit::Clubs),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Diamonds),
        Card(Value::Ace, Suit::Diamonds),
        Card(Value::Eight, Suit::Spades),
        Card(Value::Four, Suit::Diamonds),
        Card(Value::Five, Suit::Diamonds),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Five, Suit::Diamonds),
        Card(Value::Four, Suit::Diamonds),
        Card(Value::Three, Suit::Diamonds),
        Card(Value::Two, Suit::Diamonds),
        Card(Value::Ace, Suit::Diamonds),
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::StraightFlush),
        "Real: " << toString(HandRanking::StraightFlush) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}

BOOST_AUTO_TEST_CASE(test_hand_rankings_royal_flush) {
    std::vector<Card> hand = {
        Card(Value::Queen, Suit::Hearts),
        Card(Value::Nine, Suit::Hearts),
        Card(Value::Ten, Suit::Hearts),
        Card(Value::Ace, Suit::Hearts),
        Card(Value::Jack, Suit::Hearts),
        Card(Value::Eight, Suit::Hearts),
        Card(Value::King, Suit::Hearts),
    };
    HandRankings::sort(hand);
    BestHand bh = HandRankings::getBestHand(hand);

    std::vector<Card> realBestHand = {
        Card(Value::Ace, Suit::Hearts),
        Card(Value::King, Suit::Hearts),
        Card(Value::Queen, Suit::Hearts),
        Card(Value::Jack, Suit::Hearts),
        Card(Value::Ten, Suit::Hearts)
    };

    BOOST_TEST(
        static_cast<int>(bh.handRanking) == static_cast<int>(HandRanking::RoyalFlush),
        "Real: " << toString(HandRanking::RoyalFlush) << ". Calculated: " << toString(bh.handRanking)
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        bh.hand.begin(), bh.hand.end(), realBestHand.begin(), realBestHand.end()
    );
}