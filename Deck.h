#ifndef _DECK_
#define _DECK_

#include <gdkmm/pixbuf.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Card.h"
#include "Hand.h"

class Deck {
public:
    Deck();
    Deck(int);
    ~Deck();
    void shuffle();
    std::vector<Hand*> dealCards();
    Glib::RefPtr<Gdk::Pixbuf> getCardImage( Rank f, Suit s );   // Returns the image for the specified card.
    Glib::RefPtr<Gdk::Pixbuf> getNullCardImage();                 // Returns the image to use for the placeholder.
    Card* at(int);
private:
    std::vector<Card*> cards_;
    std::vector< Glib::RefPtr< Gdk::Pixbuf > > deck;                   // Contains the pixel buffer images.
    const int CARD_COUNT = 52;
};

#endif