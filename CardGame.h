/*
Name: Saranya Chotsiri
Project: CardGame - PokerPal
Course: Data Structures and Algorithms I
Description: This file is for Prototypes.
Date: 9/22/2026
*/
#include <string>

using namespace std;

// Card suits = Name of card symbols
enum Suit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};

// Card ranks = Name of card's values
enum Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};


// Structure for 1 desk card
struct Card {
    Suit suit;
    Rank rank;
};


//---------- Class ------------
class CardGame {

public:
    // Constructor
    CardGame();

    // Deck functions
    void initializeDeck();
    void shuffleDeck();
    void displayDeck(); //show all 52 cards

    // Hand functions
    void dealHand(); // give hand to player
    void displayHand(); //show the player's hand

    // Poker hand evaluation
    bool isPair(); // 2 cards same (3 3 4 5 6)
    bool isTwoPair(); //2 and 2 cards same (3 3 4 4 5)
    bool isThreeOfAKind();// 3 same (3 3 3 4 5)/(x x x o .)
    bool isFourOfAKind(); // 4 same (3 3 3 3 4)/(x x x x o)
    bool isFlush(); //5 cards have same symbol(suit = o o o o o)
    bool isStraight();//5 card's number in order(rank = 2 3 4 5 6)

    void evaluateHand();

    // Menu functions
    void displayMenu();
    void handleMenuOption(int option);

// -----------------------------------------
private:
    // Original deck: 4 suits x 13 ranks
    Card deck[4][13];

    // Shuffled order of the 52 cards [all card]
    int deckOrder[52];

    // Five cards in the player's hand
    Card hand[5];

    int nextCard;
    bool handDealt; //User got hand? (T/F)

    string getSuitName(Suit suit);
    string getRankName(Rank rank);
};
