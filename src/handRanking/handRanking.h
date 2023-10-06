#pragma once

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