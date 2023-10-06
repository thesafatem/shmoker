#include "bestHand.h"

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