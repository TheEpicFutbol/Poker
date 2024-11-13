#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <random>

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck() {
        // Makes and shuffles deck
        create();
        shuffleDeck();
    };

    // For every suit add the 13 cards to the vector
    void create() {
        for (int i = 0; i < 4; i++){
            for (int x = 0; x < 13; x++){
                cards.emplace_back(static_cast<Suit>(i), static_cast<Rank>(x));
            }
        }
    }

    // Shuffle the deck
    void shuffleDeck() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    // Used to get the first 8 cards after the deck is shuffled
    Card& getCard(size_t index) {
        if (index < cards.size()) {
            return cards[index];
        }
    }
};

#endif