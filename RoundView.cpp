#include "RoundView.h"
using namespace std;

RoundView::RoundView(vector<Player*> players) {
    controller_ = new RoundController(players);
    int player_number = controller_->who7Spades();
    cout << "A new round begins. It's player "<< player_number
         << "'s turn to play" << endl;
    printDeck();
    startTurns(player_number);
}

RoundView::~RoundView() {
    delete controller_;
}

void RoundView::startTurns(int player_number) {
    // Pseudocode
    if (controller_->getPlayer(player_number)->isHuman()) {
        cout << "human" << endl;
        cout << "Cards on the table:"<<endl;
        cout << "Clubs: "; printClubs(controller_->getPlayer(player_number));
        cout << "Diamonds: "; printDiamonds(controller_->getPlayer(player_number));
        cout << "Hearts: "; printHearts(controller_->getPlayer(player_number));
        cout << "Spades: "; printSpades(controller_->getPlayer(player_number));
        cout << "Your hand: "; printHand(controller_->getPlayer(player_number));
//         Legal plays: <legal plays in your hand>"
    }
    else {
//        controller_->playTurn(player_number);
        cout <<"computer";
    }
}

void printCardList(vector<Card*> list){
    for( int i = 0; i<list.size(); i++ ){
        cout<<*list.at(i)<<" ";
    }
    cout<<endl;
}

void RoundView::printClubs(Player* player) {
    vector<Card*> list = player->getClubs();
    printCardList(list);
}

void RoundView::printDiamonds(Player* player) {
    vector<Card*> list = player->getDiamonds();
    printCardList(list);
}

void RoundView::printHearts(Player* player) {
    vector<Card*> list = player->getHearts();
    printCardList(list);
}

void RoundView::printSpades(Player* player) {
    vector<Card*> list = player->getSpades();
    printCardList(list);
}

void RoundView::printHand(Player* player){
    printCardList(player->getCards());
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