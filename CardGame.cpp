/*
Name: Saranya Chotsiri
Project: CardGame - PokerPal - Array and Enum
Course: Data Structures and Algorithms I
Description: This file is for Class and Functions.
Date: 9/22/2026
*/

#include "CardGame.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Constructor
CardGame::CardGame() { //innitialize

    //unsigned int = no negative number.
    //static_cast() = function convert data
    srand(static_cast<unsigned int>(time(0)));

    nextCard = 0;
    handDealt = false; // no card on hand

    initializeDeck();
}

// Initialize the 52-card deck (Reset Game)
void CardGame::initializeDeck() {

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
	    //s = row, r = column

            deck[s][r].suit = static_cast<Suit>(s); // card symbol
            deck[s][r].rank = static_cast<Rank>(r + 1); // card value (Ace=1)
	    //deck[0][0] = first card [Ace of Spades]

            deckOrder[s * 13 + r] = s * 13 + r; //for (int i = 0; i < 52; i++) deckOrder[i] = i;
        }
    }

    nextCard = 0;
    handDealt = false;
}

// -------- GET ----------

// Get suit name
string CardGame::getSuitName(Suit suit) {

    switch (suit) {
        case SPADES:   return "Spades";
        case HEARTS:   return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS:    return "Clubs";
    }

    return "Unknown"; //else
}

// Get rank name
string CardGame::getRankName(Rank rank) {

    switch (rank) {
        case ACE:   return "Ace";
        case TWO:   return "2";
        case THREE: return "3";
        case FOUR:  return "4";
        case FIVE:  return "5";
        case SIX:   return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE:  return "9";
        case TEN:   return "10";
        case JACK:  return "Jack";
        case QUEEN: return "Queen";
        case KING:  return "King";
    }

0000000000000000000000000000000000000000000000000000000    return "Unknown";
}

//--------------- Other Function ------------------

// Shuffle the deck
void CardGame::shuffleDeck() {

    	// Fisher-Yates shuffle (random card, bring to last)
	//1st i = 51 (last), j = 20, then swap j to last, i to 20
	//2nd i = 50, j = 32, then j to 50, i to 32...
    for (int i = 51; i > 0; i--) { // 51 loops from last card

        int j = rand() % (i + 1); //random (0 to last)

        swap(deckOrder[i], deckOrder[j]); //swap card[i] and card[j]
    } //Got the new deckOrder[] after shuffled.

    nextCard = 0;
    handDealt = false;

    cout << endl << "Deck shuffled successfully!" << endl;

    displayDeck();
}


// Display the shuffled deck in a 4 x 13 table
void CardGame::displayDeck() {

    cout << "\n========== DECK ==========\n";

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {

            int index = deckOrder[s * 13 + r]; //everycard

            int suitIndex = index / 13; // (15/13)= 1 > 'Dimond'
            int rankIndex = index % 13; // (15%13)= 2 > '3'
		// % Value [0-12] = A,2,3,...,K

            cout << getRankName(deck[suitIndex][rankIndex].rank) //'Dimond'
                 << " of "
                 << getSuitName(deck[suitIndex][rankIndex].suit) //'3'
                 << "\t"; // Tab (setw)

            if ((r + 1) % 4 == 0) { // new line, every 4 cards
                cout << endl;
            }
        }

        cout << endl;
    }
}

// Deal 5 cards to hand
void CardGame::dealHand() {

//---- Validate Cards left ----
//nextCard = index of the next card to use.
//5 = cards to deal.
//Ex. 48 + 5 = 53 > 52, so the card left, is not enough to deal 5 cards.
    if (nextCard + 5 > 52) {
        cout << "Not enough cards remaining. Shuffle first.\n";
        return; // out of the dealHand().
    }

//---- Deal 5 cards-----
    for (int i = 0; i < 5; i++) {

        int index = deckOrder[nextCard];
//Ex. deckOrder[0] is 10, so 'index' is the value of deck[10] (original deck)

        int suitIndex = index / 13; //get symbol
        int rankIndex = index % 13; //get value

        hand[i] = deck[suitIndex][rankIndex]; //Ex. hand[0] = deck[0][10]

        nextCard++;
    }

    handDealt = true; //finished deal
    cout << endl <<"Five cards dealt successfully!" << endl;
}

// Display the player's hand 5 cards
void CardGame::displayHand() {

    if (!handDealt) {
        cout << endl << "Please deal a hand first." << endl;
        return;
    }

    cout << endl << "========== YOUR HAND ==========" << endl;

//1. 3 of heart
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". "
             << getRankName(hand[i].rank)
             << " of "
             << getSuitName(hand[i].suit)
             << endl;
    }
}


// ---------- Check in hand Function ----------

// Check for Pair
bool CardGame::isPair() {
    int count[14] = {0}; // array[14] = {0,0,...,0};

//Count (value) only 5 cards on hand > what value in it > if found, count+1
    for (int i = 0; i < 5; i++) {
        count[hand[i].rank]++; //hand[1] = Ace, hand[13]=king
    }
	//Check count[1] = 2 >> have 2 Ace cards
    for (int i = 1; i <= 13; i++) {
        if (count[i] == 2) {
            return true;
        }
    }

    return false; // no pair
}

// Check for Two Pair
bool CardGame::isTwoPair() {
    int count[14] = {0};
    int pairs = 0;

// count value of cards on hand > if found > count+1
    for (int i = 0; i < 5; i++) {
        count[hand[i].rank]++;
    }
//check if any got 2 > pair +1
    for (int i = 1; i <= 13; i++) {
        if (count[i] == 2) {
            pairs++;
        }
    }
//  return true if 2 == 2, else return false
    return pairs == 2;
}

// Check for Three of a Kind
bool CardGame::isThreeOfAKind() {
    int count[14] = {0};

    for (int i = 0; i < 5; i++) {
        count[hand[i].rank]++;
    }

// [1,1,1,2,5]> true
    for (int i = 1; i <= 13; i++) {
        if (count[i] == 3) {
            return true;
        }
    }

    return false;
}

// Check for Four of a Kind
bool CardGame::isFourOfAKind() {
    int count[14] = {0};

    for (int i = 0; i < 5; i++) {
        count[hand[i].rank]++;
    }

    for (int i = 1; i <= 13; i++) {
        if (count[i] == 4) {
            return true;
        }
    }

    return false;
}

// Check for Flush = Same symbol all 5 cards.
bool CardGame::isFlush() {
    for (int i = 1; i < 5; i++) {
//hand[0] = 1st card symbol.
//hand[i] = Check each symbol.
        if (hand[i].suit != hand[0].suit) {
            return false; // if found not match > out of the function.
        }
    }
//if found all same symbol
    return true;
}

// Check for Straight > [1,2,3,4,5] in order.
bool CardGame::isStraight() {
    int ranks[5];
//Put value of each cards on hand into ranks[]
    for (int i = 0; i < 5; i++) {
        ranks[i] = static_cast<int>(hand[i].rank); //convert ENUM to int
    }

//sort index 0 to index 4
    sort(ranks, ranks + 5); //ranks+5 is the last index of the array (index 4)

    // Check for duplicates > false
    for (int i = 1; i < 5; i++) {
        if (ranks[i] == ranks[i - 1]) {
            return false;
        }
    }

    // Normal straight check
    bool normalStraight = true;

    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[0] + i) {
// Ex. ranks = {3, 4, 6, 7, 8}
// ranks[2] != ranks[0] + 2
// 6 != 3 + 2
// 6 != 5
// > false
            normalStraight = false; //Not straight
            break; // Get out of the loop
        }
    }

// if normalStraight == true
    if (normalStraight) {
        return true;
    }

// if false, Check the spacial case.
// Ace can also be highest value [14 points]: 10, J, Q, K, A
    if (ranks[0] == 1 &&  // Ace
        ranks[1] == 10 && // 10
        ranks[2] == 11 && // J
        ranks[3] == 12 && // Q
        ranks[4] == 13) { // K
        return true;
    }

    return false;
}

// Evaluate all poker hands
void CardGame::evaluateHand() {
    if (!handDealt) {
        cout << "\nPlease deal a hand first.\n";
        return;
    }

    cout << "\n========== HAND EVALUATION ==========\n";

    cout << "Pair: "
         << (isPair() ? "Yes" : "No") << "\n";

    cout << "Two Pair: "
         << (isTwoPair() ? "Yes" : "No") << "\n";

    cout << "Three of a Kind: "
         << (isThreeOfAKind() ? "Yes" : "No") << "\n";

    cout << "Four of a Kind: "
         << (isFourOfAKind() ? "Yes" : "No") << "\n";

    cout << "Flush: "
         << (isFlush() ? "Yes" : "No") << "\n";

    cout << "Straight: "
         << (isStraight() ? "Yes" : "No") << "\n";
}

// Display menu
void CardGame::displayMenu() {
    cout << "\n========== PokerPal ==========\n";
    cout << "1. Shuffle Deck\n";
    cout << "2. Deal Hand\n";
    cout << "3. Display Hand\n";
    cout << "4. Evaluate Hand\n";
    cout << "5. Exit\n";
    cout << "Plase Enter Your Choise: ";
}

// Handle menu option
void CardGame::handleMenuOption(int option) {
    switch (option) {
        case 1:
            shuffleDeck();
            break;

        case 2:
            dealHand();
            break;

        case 3:
            displayHand();
            break;

        case 4:
            evaluateHand();
            break;

        case 5:
            cout << "\nThank you for playing PokerPal!\n";
            break;

        default:
            cout << "\nInvalid choice. Please select 1-5.\n";
    }
}
