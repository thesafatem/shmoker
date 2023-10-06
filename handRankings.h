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

std::string toString(HandRanking handRanking) {
    switch (handRanking) {
        case HandRanking::HighCard:
            return "High card";
            break;
        case HandRanking::OnePair:
            return "One pair";
            break;
        case HandRanking::TwoPair:
            return "Two pair";
            break;
        case HandRanking::Set:
            return "Set";
            break;
        case HandRanking::Straight:
            return "Straight";
            break;
        case HandRanking::Flush:
            return "Flush";
            break;
        case HandRanking::FullHouse:
            return "Full house";
            break;
        case HandRanking::FourOfAKind:
            return "Four of a kind";
            break;
        case HandRanking::StraightFlush:
            return "Straight flush";
            break;
        case HandRanking::RoyalFlush:
            return "Royal flush";
            break;
        default:
            return "X";
    }
}

class BestHand {
public:
    HandRanking handRanking;
    std::vector<Card> hand;
    BestHand(HandRanking handRanking, std::vector<Card> hand);

    operator std::string() const;
    friend std::ostream & operator <<(std::ostream &out, const BestHand &bh);
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