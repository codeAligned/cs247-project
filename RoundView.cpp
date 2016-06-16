#include "RoundView.h"
using namespace std;

RoundView::RoundView(vector<Player*> players) {
    controller_ = new RoundController(players);
    cout << "A new round begins. It’s player "<< controller_->who7Spades()
         << "'s turn to play" << endl;
}

RoundView::~RoundView() {
    delete controller_;
}

void RoundView::printThings() {
    cout << "printing things" << endl;
}