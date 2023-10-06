#include "handRankings.h"
#include <map>

typedef BestHand (*rankingFunction) (Cards hand);


BestHand::BestHand(HandRanking handRanking, std::vector<Card> hand)
: handRanking(handRanking)
, hand(hand) {};

BestHand::operator std::string() const {
    std::ostringstream out;
    out << *this;
    return out.str();
}

bool BestHand::operator<(BestHand const& rhs) const {
    if (this->handRanking != rhs.handRanking) {
        return this->handRanking < rhs.handRanking;
    }
    for (
        auto it1 = this->hand.begin(), it2 = rhs.hand.begin(); 
        it1 != this->hand.end() && it2 != rhs.hand.end(); 
        it1++, it2++
    ) {
        if (*it1 < *it2) return true;
        if (*it1 > *it2) return false;
    }
    return false;
}

bool BestHand::operator>(BestHand const& rhs) const {
    if (this->handRanking != rhs.handRanking) {
        return this->handRanking > rhs.handRanking;
    }
    for (
        auto it1 = this->hand.begin(), it2 = rhs.hand.begin(); 
        it1 != this->hand.end() && it2 != rhs.hand.end(); 
        it1++, it2++
    ) {
        if (*it1 > *it2) return true;
        if (*it1 < *it2) return false;
    }
    return false;
}

bool BestHand::operator==(BestHand const& rhs) const {
    if (this->handRanking != rhs.handRanking) {
        return false;
    }
    for (
        auto it1 = this->hand.begin(), it2 = rhs.hand.begin(); 
        it1 != this->hand.end() && it2 != rhs.hand.end(); 
        it1++, it2++
    ) {
        if (*it1 > *it2) return false;
        if (*it1 < *it2) return false;
    }
    return true;
}

bool BestHand::operator!=(BestHand const& rhs) const {
    return !(*this == rhs);
}

std::ostream & operator <<(std::ostream &out, const BestHand &bh) {
    out << toString(bh.handRanking) << "\n";
    for (auto card : bh.hand) {
        out << card << " ";
    }
    return out;
}


void HandRankings::sort(Cards& hand) {
    std::sort(hand.begin(), hand.end(), [&](Card left, Card right) {
        return left > right;
    });
}

BestHand HandRankings::getBestHand(Cards hand) {
    std::vector<rankingFunction> rankingFunctions = {
        HandRankings::isStraightFlush,
        HandRankings::isFourOfAKind,
        HandRankings::isFullHouse,
        HandRankings::isFlush,
        HandRankings::isStraight,
        HandRankings::isSet,
        HandRankings::isTwoPair,
        HandRankings::isOnePair,
        HandRankings::isHighCard
    };

    HandRankings::sort(hand);
    
    for (auto rf : rankingFunctions) {
        BestHand bh = rf(hand);
        if (bh.handRanking != HandRanking::NO) {
            return bh;
        }
    }
    return BestHand(HandRanking::NO, {});
}

BestHand HandRankings::isHighCard(Cards hand) {
    return BestHand(HandRanking::HighCard, {hand.begin(), hand.begin() + 5});
}

BestHand HandRankings::isOnePair(Cards hand) {
    auto [res, left] = HandRankings::getXHighCardsWithSameValue(2, hand);
    if (res.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    res.insert(res.end(), left.begin(), left.begin() + 3);
    return BestHand(HandRanking::OnePair, res);
}

BestHand HandRankings::isTwoPair(Cards hand) {
    Cards bestHand;
    auto firstPair = HandRankings::getXHighCardsWithSameValue(2, hand);
    if (firstPair.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    auto secondPair = HandRankings::getXHighCardsWithSameValue(2, firstPair.second);
    if (secondPair.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    bestHand = firstPair.first;
    bestHand.insert(bestHand.end(), secondPair.first.begin(), secondPair.first.end());
    bestHand.push_back(secondPair.second[0]);
    return BestHand(HandRanking::TwoPair, bestHand);
}

BestHand HandRankings::isSet(Cards hand) {
    Cards bestHand;
    auto set = HandRankings::getXHighCardsWithSameValue(3, hand);
    if (set.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    bestHand = set.first;
    bestHand.insert(bestHand.end(), set.second.begin(), set.second.begin() + 2);
    return BestHand(HandRanking::Set, bestHand);
}

BestHand HandRankings::isStraight(Cards hand) {
    Cards bestHand = {hand[0]};
    for (int i = 1; i < hand.size(); i++) {
        if (static_cast<int>(hand[i].value) == static_cast<int>(bestHand.back().value) - 1) {
            bestHand.push_back(hand[i]);
        } else if (static_cast<int>(hand[i].value) < static_cast<int>(bestHand.back().value) - 1) {
            // replace current straight only if there are 3 or less cards
            // 4 is good for A-?-?-5-4-3-2 situation
            if (bestHand.size() < 4) {
                bestHand = {hand[i]};
            }
        }
    }
    if (bestHand.size() < 4) {
        return BestHand(HandRanking::NO, {});
    }
    if (bestHand.size() == 4 && !(bestHand[0].value == Value::Five && hand[0].value == Value::Ace)) {
        return BestHand(HandRanking::NO, {});
    }
    if (bestHand.size() == 4) {
        bestHand.push_back(hand[0]);
    }
    return BestHand(HandRanking::Straight, Cards(bestHand.begin(), bestHand.begin() + 5)); 
}

BestHand HandRankings::isFlush(Cards hand) {
    Cards flushHand = HandRankings::getAllFlushCards(hand);
    if (flushHand.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    return BestHand(HandRanking::Flush, Cards(flushHand.begin(), flushHand.begin() + 5)); 
}

BestHand HandRankings::isFullHouse(Cards hand) {
    Cards bestHand;
    auto set = HandRankings::getXHighCardsWithSameValue(3, hand);
    if (set.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    bestHand = set.first;
    auto pair = HandRankings::getXHighCardsWithSameValue(2, set.second);
    if (pair.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    bestHand.insert(bestHand.end(), pair.first.begin(), pair.first.end());
    return BestHand(HandRanking::FullHouse, bestHand);
}

BestHand HandRankings::isFourOfAKind(Cards hand) {
    Cards bestHand;
    auto fourOfAKind = HandRankings::getXHighCardsWithSameValue(4, hand);
    if (fourOfAKind.first.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    bestHand = fourOfAKind.first;
    bestHand.push_back(fourOfAKind.second[0]);
    return BestHand(HandRanking::FourOfAKind, bestHand); 
}

BestHand HandRankings::isStraightFlush(Cards hand) {
    Cards flushHand = HandRankings::getAllFlushCards(hand);
    if (flushHand.empty()) {
        return BestHand(HandRanking::NO, {});
    }
    auto straight = HandRankings::isStraight(flushHand);
    if (straight.handRanking != HandRanking::NO) {
        if (straight.hand[0].value == Value::Ace) {
            straight.handRanking = HandRanking::RoyalFlush;
        } else {
            straight.handRanking = HandRanking::StraightFlush;
        }
    }
    return straight;
}

std::pair<Cards, Cards> HandRankings::getXHighCardsWithSameValue(int X, Cards hand) {
    for (int i = 0; i < hand.size(); i++) {
        if (i + X - 1 < hand.size()) {
            if (hand[i].equals(hand[i + X - 1])) {
                Cards take = Cards(hand.begin() + i, hand.begin() + i + X);
                hand.erase(hand.begin() + i, hand.begin() + i + X);
                return std::make_pair(take, hand);
            }
        }
    }
    return std::make_pair<Cards, Cards>({}, {});
}

Cards HandRankings::getAllFlushCards(Cards hand) {
    Cards flushHand;
    std::map<Suit, int> suitCount;
    for (auto card : hand) {
        suitCount[card.suit] += 1;
    }
    Suit largestSuit = Suit::NO;
    for (auto [suit, count] : suitCount) {
        if (count >= 5) {
            largestSuit = suit;
            break;
        }
    }
    if (largestSuit == Suit::NO) {
        return {};
    }
    for (auto card : hand) {
        if (card.suit == largestSuit) {
            flushHand.push_back(card);
        }
    }
    return flushHand;
}

