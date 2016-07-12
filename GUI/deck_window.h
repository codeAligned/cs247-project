#ifndef __DECK_WINDOW_H
#define __DECK_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

#include "DeckGUI.h"

class Deck_Window : public Gtk::Window {
public:
    Deck_Window();
    void onButtonClicked();
    virtual ~Deck_Window();
	
private:
    DeckGUI deck;             // Knows all of the card pixel buffers.
    int nextCard;
    Suits nextSuit;
    Faces nextFace;
	
    // Member widgets:
    Gtk::Image * card[13];          // Images to display.
    Gtk::Button button;           // Button that will hold an image.
    Gtk::HBox hbox;             // Horizontal box for aligning widgets in the window.
    Gtk::Frame frame;            // Create a nice framed border for the box.
};

#endif
