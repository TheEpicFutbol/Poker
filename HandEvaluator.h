#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H

#include "card.h"
#include <vector>

enum class HandRank {
    HighCard, OnePair, TwoPair, ThreeOfAKind
};

class HandEvaluator {
public:
    static HandRank evaluateHand(const std::vector<Card>& cards) {
        // Make array of 13 0's
        int count[13] = {0};

        // Adds 1 to each place the number is found
        for (const auto& card : cards) {
            int number = static_cast<int>(card.getRank());
            count[number]++;
        }

        // counts pairs
        int pairs = 0;
        bool threeOfAKind = false;

        // counts pairs
        for (int count : count) {
            if (count == 2) {
                pairs++;
            } else if (count == 3) {
                threeOfAKind = true;
            }
        }

        // Checks for each hand rank
        if (threeOfAKind) {
            return HandRank::ThreeOfAKind;
        }
        if (pairs >= 2) {
            return HandRank::TwoPair;
        }
        if (pairs == 1) {
            return HandRank::OnePair;
        }

        return HandRank::HighCard;
    }
    static std::string handRankToString(HandRank rank) {
        switch (rank) {
            case HandRank::HighCard: return "High Card";
            case HandRank::OnePair: return "One Pair";
            case HandRank::TwoPair: return "Two Pair";
            case HandRank::ThreeOfAKind: return "Three of a Kind";
            default: return "Unknown Hand";
        }
    }
};

#endif
