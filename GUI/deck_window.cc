#include "deck_window.h"
#include <iostream>

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
Deck_Window::Deck_Window() : hboxClubs( true, 10 ), hboxDias( true, 10 ), hboxHearts( true, 10 ), hboxSpades( true, 10 ){

    nextCard = 0;
    nextSuit = (Suits) 0;
    nextFace = (Faces) 0;
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( ACE, SPADE );
	
	// Sets the border width of the window.
	set_border_width( 10 );
		
	// Set the look of the frame.
	frame.set_label( "Played cards:" );
	frame.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
	
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );
	frame.add(vbox);
	
	// Add the horizontal box for laying out the images to the frame.
	vbox.add( hboxClubs );
	
	// Initialize 4 empty cards and place them in the box.
	for (int i = 0; i < 13; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hboxClubs.add( *card[i] );
	}
	
	std::cout<<"Finished loop"<<std::endl;
	// Initialize the 5th card and place the image into the button.
	//	card[4] = new Gtk::Image( cardPixbuf );	
	button.set_image( *card[12] );	
	std::cout<<"Finished setting card"<<std::endl;

	// Attach event listener to button
	button.signal_clicked().connect(sigc::mem_fun( *this, &Deck_Window::onButtonClicked));
			
	// Add the button to the box.
	hboxClubs.add( button );
// -------------------------------------
// UGLY TEMP CODE UNTIL I FIGURE THIS ARRAY SHIT

	vbox.add( hboxDias ) ;
	
	// Initialize 4 empty cards and place them in the box.
	for (int i = 13; i < 26; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hboxDias.add( *card[i] );
	}

// -------------------------------------
// UGLY TEMP CODE UNTIL I FIGURE THIS ARRAY SHIT
	
	vbox.add( hboxHearts ) ;
	
	// Initialize 4 empty cards and place them in the box.
	for (int i = 26; i < 39; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hboxHearts.add( *card[i] );
	}

// -------------------------------------
// UGLY TEMP CODE UNTIL I FIGURE THIS ARRAY SHIT
	
	vbox.add( hboxSpades ) ;
	
	// Initialize 4 empty cards and place them in the box.
	for (int i = 39; i < 52; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hboxSpades.add( *card[i] );
	}
	
	// The final step is to display this newly created widget.
	show_all();
}

Deck_Window::~Deck_Window() {
	for (int i = 0; i < 13; i++ ) delete card[i];
}

void Deck_Window::onButtonClicked()
{
    card[nextCard]->set(deck.getCardImage(nextFace, nextSuit));

    nextCard = (nextCard+1) % 13;
    if( (nextFace+1) == 13)
    {
        nextFace = (Faces) 0;
        nextSuit = (Suits) ((nextSuit + 1) % 4);
    }
    else
    {
        nextFace = (Faces) (nextFace+1);
    }
}