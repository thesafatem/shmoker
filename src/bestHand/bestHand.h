#pragma once

#include <vector>
#include "../card/card.h"
#include "../handRanking/handRanking.h"

class BestHand {
public:
    HandRanking handRanking;
    std::vector<Card> hand;
    BestHand(HandRanking handRanking, std::vector<Card> hand);

    bool operator<(BestHand const& rhs) const;
    bool operator>(BestHand const& rhs) const;
    bool operator==(BestHand const& rhs) const;
    bool operator!=(BestHand const& rhs) const;
    operator std::string() const;
    friend std::ostream & operator <<(std::ostream &out, const BestHand &bh);
};