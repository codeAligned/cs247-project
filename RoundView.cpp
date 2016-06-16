#include "RoundView.h"
using namespace std;

RoundView::RoundView(vector<Player*> players) {
    controller_ = new RoundController(players);
}

RoundView::~RoundView() {
    delete controller_;
}

void RoundView::printThings() {
    cout << "printing things" << endl;
}