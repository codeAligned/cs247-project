#include <random>
#include "Deck.h"

using namespace std;

// Default seed value, global since shuffle expects global seed variable.
int seed = 0;

// Sets up an array of the Portable Network Graphics (PNG) file names that contain the necessary card images.
// The deck will load the contents into pixel buffers for later use.
const char * image_names[] = {
    // Set up ACE of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_0.png", "cards_png/1_0.png", "cards_png/2_0.png", "cards_png/3_0.png",
    // Set up TWO of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_1.png", "cards_png/1_1.png", "cards_png/2_1.png", "cards_png/3_1.png",
    // Set up THREE of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_2.png", "cards_png/1_2.png", "cards_png/2_2.png", "cards_png/3_2.png",
    // Set up FOUR of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_3.png", "cards_png/1_3.png", "cards_png/2_3.png", "cards_png/3_3.png",
    // Set up FIVE of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_4.png", "cards_png/1_4.png", "cards_png/2_4.png", "cards_png/3_4.png",
    // Set up SIX of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_5.png", "cards_png/1_5.png", "cards_png/2_5.png", "cards_png/3_5.png",
    // Set up SEVEN of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_6.png", "cards_png/1_6.png", "cards_png/2_6.png", "cards_png/3_6.png",
    // Set up EIGHT of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_7.png", "cards_png/1_7.png", "cards_png/2_7.png", "cards_png/3_7.png",
    // Set up NINE of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_8.png", "cards_png/1_8.png", "cards_png/2_8.png", "cards_png/3_8.png",
    // Set up TEN of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_9.png", "cards_png/1_9.png", "cards_png/2_9.png", "cards_png/3_9.png",
    // Set up JACK of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_j.png", "cards_png/1_j.png", "cards_png/2_j.png", "cards_png/3_j.png",
    // Set up QUEEN of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_q.png", "cards_png/1_q.png", "cards_png/2_q.png", "cards_png/3_q.png",
    // Set up KING of {DIAMOND,CLUB,HEART,SPADE}
    "cards_png/0_k.png", "cards_png/1_k.png", "cards_png/2_k.png", "cards_png/3_k.png",
    // Set up the back of a card for a place holder/null card
    "cards_png/back_1.png"
};

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const string & name) {
    return Gdk::Pixbuf::create_from_file( name );
}

Glib::RefPtr<Gdk::Pixbuf> Deck::getCardImage( Rank f, Suit s ) {
    int index = ((int) f)*4 + ((int) s );
    return deck[ index ];
}

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> Deck::getNullCardImage() {
    int size = deck.size();
    return deck[ size-1 ];
}


Deck::Deck() {
    for(int i = 0; i < SUIT_COUNT; ++i) {
        for(int j = 0; j < RANK_COUNT; ++j) {
            cards_.push_back( new Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
    transform( &image_names[0], &image_names[G_N_ELEMENTS(image_names)],
                    // from image_names[0] to image_names[G_N_ELEMENTS(image_names)]...
               std::back_inserter(deck), &createPixbuf );

}

Deck::Deck(int seedIn) {
    for(int i = 0; i < SUIT_COUNT; ++i) {
        for(int j = 0; j < RANK_COUNT; ++j) {
            cards_.push_back( new Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
    seed = seedIn;
}

Deck::~Deck() {
    for(int i = 0; i < cards_.size(); ++i) {
        delete cards_.at(i);
    }
}

// Return vector of 4 hands with 13 cards each.
vector<Hand*> Deck::dealCards(){
    vector<Hand*> hands = vector<Hand*>();
    for(int i = 0; i < 4; ++i) {
        vector<Card*> temp = vector<Card*>();
        for(int j = 0; j < 13; ++j) {
            temp.push_back( cards_.at(13*i+j) ); // calculate index of card from 0..51
        }
        hands.push_back(new Hand(temp));
    }
    return hands;
}

Card* Deck::at(int index){
    return cards_.at(index);
}

void Deck::shuffle(){
    static std::mt19937 rng(seed);

    int n = CARD_COUNT;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card *c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
}