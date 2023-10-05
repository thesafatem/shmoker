#pragma once
#include "card.h"
#include <vector>

using Cards = std::vector<Card>;


enum class HandRanking {
    NO,
    HighCard,
    OnePair,
    TwoPair,
    Set,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

class BestHand {
public:
    HandRanking handRanking;
    std::vector<Card> hand;
    BestHand(HandRanking handRanking, std::vector<Card> hand);
};

class HandRankings {
public:
    static void sort(Cards& hand);
    static BestHand getBestHand(Cards hand);

private:
    static std::pair<Cards, Cards> getXHighCardsWithSameValue(int X, Cards hand);
    static Cards getAllFlushCards(Cards hand);
    static BestHand isHighCard(Cards hand);
    static BestHand isOnePair(Cards hand);
    static BestHand isTwoPair(Cards hand);
    static BestHand isSet(Cards hand);
    static BestHand isStraight(Cards hand);
    static BestHand isFlush(Cards hand);
    static BestHand isFullHouse(Cards hand);
    static BestHand isFourOfAKind(Cards hand);
    static BestHand isStraightFlush(Cards hand);
};