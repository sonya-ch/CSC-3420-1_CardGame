```mermaid

class CardGame {
        -Suit deckSuit[4][13]
        -Rank deckRank[4][13]
        -Suit handSuit[5]
        -Rank handRank[5]
        -bool dealt[4][13]

        +CardGame()
        +initializeDeck() void
        +shuffleDeck() void
        +dealHand() void
        +displayDeck() void
        +displayHand() void
        +isPair() bool
        +isTwoPair() bool
        +isThreeOfAKind() bool
        +isFourOfAKind() bool
        +isFlush() bool
        +isStraight() bool
        +displayMenu() void
        +handleMenuOption(option int) void
    }

    class Suit {
        <<enumeration>>
        SPADES
        HEARTS
        DIAMONDS
        CLUBS
    }

    class Rank {
        <<enumeration>>
        ACE
        TWO
        THREE
        FOUR
        FIVE
        SIX
        SEVEN
        EIGHT
        NINE
        TEN
        JACK
        QUEEN
        KING
    }

    CardGame ..> Suit : uses
    CardGame ..> Rank : uses