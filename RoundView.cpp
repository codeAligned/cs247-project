#include "RoundView.h"
using namespace std;

RoundView::RoundView(vector<Player*> players) {
    controller_ = new RoundController(players);
    int player_number = controller_->who7Spades();
    cout << "A new round begins. It's player "<< player_number+1
         << "'s turn to play" << endl;
    printDeck();
    startTurns(player_number);
}

void RoundView::startTurns(int player_number) {
    // Pseudocode
    if (controller_->getPlayer(player_number)->isHuman()) {
        cout << "human" << endl;
        // cout << "Cards on the table:
        // Clubs: <list of clubs>
        // Diamonds: <list of diamonds>
        // Hearts: <list of hearts>
        // Spades: <list of spades>
        // Your hand: <cards in your hand>
        // Legal plays: <legal plays in your hand>" << endl;
    }
    else {
//        controller_->playTurn(player_number);
        cout <<"computer";
    }
}

RoundView::~RoundView() {
    delete controller_;
}

void RoundView::printDeck(){
    Deck* deck = controller_->getDeck();
    for(int i = 0; i<SUIT_COUNT;i++){
        for(int j = 0; j<RANK_COUNT;j++){
            cout<<*deck->at(13*i+j)<<" ";
        }
        cout<<endl;
    }
}