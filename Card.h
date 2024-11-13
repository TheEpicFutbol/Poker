#ifndef CARD_H
#define CARD_H

enum class Suit {
    hearts, diamonds, clubs, spades
};
enum class Rank {
    ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
};
class Card{
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit suit, Rank rank){
        this->suit = suit;
        this->rank = rank;
    }
    Suit getSuit() const {
        return suit;
    }
    Rank getRank() const {
        return rank;
    }
    std::string suitToString() const {
        switch (suit) {
            case Suit::hearts: return "Hearts";
            case Suit::diamonds: return "Diamonds";
            case Suit::clubs: return "Clubs";
            case Suit::spades: return "Spades";
            default: return "Unknown";
        }
    }
    std::string rankToString() const {
        switch (rank) {
            case Rank::ace: return "Ace";
            case Rank::two: return "Two";
            case Rank::three: return "Three";
            case Rank::four: return "Four";
            case Rank::five: return "Five";
            case Rank::six: return "Six";
            case Rank::seven: return "Seven";
            case Rank::eight: return "Eight";
            case Rank::nine: return "Nine";
            case Rank::ten: return "Ten";
            case Rank::jack: return "Jack";
            case Rank::queen: return "Queen";
            case Rank::king: return "King";
            default: return "Unknown";
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        os << card.rankToString() << " of " << card.suitToString();
        return os;
    }
};

#endif