#include <iostream>
#include "Deck.h"
#include "HandEvaluator.h"

int validate(int playerCash) {
    // Set values
    std::string Bet;
    bool BetBool = true;
    int integerBet = 0;
    std::getline(std::cin, Bet);
    while (BetBool) {
        try {
            // Checks for decimal or above player cash
            integerBet = std::stoi(Bet);
            if (Bet.find('.') != std::string::npos) {
                std::cout << "Invalid input. Enter a number: ";
                std::getline(std::cin, Bet);
            } else if (integerBet > (playerCash)) {
                std::cout << "Input too large. Enter a number: ";
                std::getline(std::cin, Bet);
            } else {
                // If all good it moves on
                BetBool = false;
            }
        } catch (...) {
            // Checks to make sure it is a valid input and not 0
            if (Bet.length() == 0) {
                std::cout << "No input. Enter a Bet: ";
            } else {
                std::cout << "Invalid input. Enter a number: ";
            }
            std::getline(std::cin, Bet);
        }
    }
    return integerBet;
}

int main() {
    std::cout << "Welcome to practice poker versus the computer!\n";
    int playerCash = 100;
    int roundNumber = 1;

    while (playerCash >= 10) {
        std::cout << "Round "<< roundNumber << "\n";
        std::cout << "You have " << playerCash << " dollars. Good Luck!\n";

        Deck deck;
        Card& playerCard1 = deck.getCard(0);
        Card& playerCard2 = deck.getCard(1);
        std::cout << "Your cards:\n";
        std::cout << "Card 1: " << playerCard1 << "\n";
        std::cout << "Card 2: " << playerCard2 << "\n";

        Card& computerCard1 = deck.getCard(2);
        Card& computerCard2 = deck.getCard(3);
        playerCash -= 10;
        std::cout << "You have to bet 10 dollars! Now you have " << playerCash << ". How much more would you like to bet: ";

        int integerFirstBet = validate(playerCash);
        playerCash -= integerFirstBet;
        std::cout << "The computer calls! Next Cards: \n";
        Card& flop1 = deck.getCard(4);
        Card& flop2 = deck.getCard(5);
        Card& flop3 = deck.getCard(6);
        std::cout << "Flop 1: " << flop1 << "\n";
        std::cout << "Flop 2: " << flop2 << "\n";
        std::cout << "Flop 3: " << flop3 << "\n";

        std::cout << "Now you have " << playerCash << ". How much more would you like to bet: ";

        int integerSecondBet = validate(playerCash);
        playerCash -= integerSecondBet;
        std::cout << "The computer calls! Next Cards: \n";

        Card& turn = deck.getCard(7);
        std::cout << "Turn: " << turn << "\n";

        std::cout << "Now you have " << playerCash << ". How much more would you like to bet: ";
        int integerThirdBet = validate(playerCash);
        playerCash -= integerThirdBet;
        std::cout << "The computer calls! Next Cards: \n";

        Card& river = deck.getCard(8);
        std::cout << "River: " << river << "\n";
        std::cout << "Now you have " << playerCash << ". How much more would you like to bet: ";
        int integerFourthBet = validate(playerCash);
        playerCash -= integerFourthBet;

        // Add all the cards to a vector so they can be used bu the methods
        std::vector<Card> communityCards = {flop1, flop2, flop3, turn, river};
        std::vector<Card> playerHand = {playerCard1, playerCard2};
        std::vector<Card> computerHand = {computerCard1, computerCard2};

        std::vector<Card> fullPlayerHand = playerHand;
        fullPlayerHand.insert(fullPlayerHand.end(), communityCards.begin(), communityCards.end());

        std::vector<Card> fullComputerHand = computerHand;
        fullComputerHand.insert(fullComputerHand.end(), communityCards.begin(), communityCards.end());

        // Now run HandEvaluator to see which wins
        HandRank playerRank = HandEvaluator::evaluateHand(fullPlayerHand);
        HandRank computerRank = HandEvaluator::evaluateHand(fullComputerHand);

        int bets = integerFirstBet + integerSecondBet + integerThirdBet + integerFourthBet + 10;

        // Say winner and give money
        if (playerRank > computerRank) {
            std::cout << "Player wins with a " << HandEvaluator::handRankToString(playerRank) << "!\n";
            playerCash += (bets * 2);
        } else if (playerRank < computerRank) {
            std::cout << "Computer wins with a " << HandEvaluator::handRankToString(computerRank) << "!\n";
        } else {
            std::cout << "It's a tie with " << HandEvaluator::handRankToString(computerRank) << "!\n";
            playerCash += bets;
        }

        std::cout << "Player end of round cash: " << playerCash << "\n";
        roundNumber += 1;

        if (playerCash < 10) {
            std::cout << "You don't have enough cash to continue. Game over.\n";
        }
    }

    return 0;
}
