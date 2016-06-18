#include "RoundView.h"

using namespace std;

RoundView::RoundView(vector<Player*> players) {
    controller_ = new RoundController(players);
    int player_number = controller_->who7Spades();
    cout << "A new round begins. It's player "<< player_number
         << "'s turn to play" << endl;
    printDeck();

    startRoundLoop(&player_number);
}

RoundView::~RoundView() {
    delete controller_;
}

void RoundView::startTurns(int* player_number) {
    Player* currentPlayer = controller_->getPlayer(*player_number);
    if (currentPlayer->isHuman()) {
        cout << "Cards on the table:" << endl;
        cout << "Clubs: ";
        printClubs(currentPlayer);
        cout << "Diamonds: ";
        printDiamonds(currentPlayer);
        cout << "Hearts: ";
        printHearts(currentPlayer);
        cout << "Spades: ";
        printSpades(currentPlayer);
        cout << "Your hand: ";
        printHand(currentPlayer);
        cout << "Legal plays: ";
        printLegalPlays(currentPlayer);//<legal plays in your hand>"
        turnLoop(player_number);
    }
    else {
        //        controller_->playTurn(player_number);
    }
}

void RoundView::turnLoop(int* player_number){
    int tempNum = *player_number;
    while(tempNum == *player_number) {
        Command cmd = getCommand();
        executeCommand(cmd, player_number);
    }
}

void RoundView::startRoundLoop(int* player_number){
    for(int i = 0; i<52; i++){
        startTurns(player_number);
    }
}

void printCardList(vector<Card*> list){
    for( int i = 0; i<list.size(); i++ ){
        cout<<*list.at(i)<<" ";
    }
    cout<<endl;
}
//TODO refactor these to use controller instead of directly invoking player
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

void RoundView::printLegalPlays(Player* player){
    printCardList(controller_->calculateLegalPlay(player));
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

Command RoundView::getCommand(){
    Command cmd;
    cin.clear();
    cout << ">";
    cin>>cmd;
    return cmd;
}

void plusPlayerNum(int* player_number){
    *player_number = *player_number+1;
    if(*player_number == 5){
        *player_number = 1;
    }
}

void RoundView::executeCommand(Command cmd,int* player_number){
    Player* currentPlayer = controller_->getPlayer(*player_number);
    switch (cmd.type){
        case PLAY:
            if ( controller_->isLegalPlay(currentPlayer, cmd.card) ) {
                controller_->playCard(currentPlayer, cmd.card);
                cout << "Player " << *player_number << " plays " << cmd.card << "." << endl;
                plusPlayerNum(player_number);
            }
            else {
                cout << "This is not a legal play." << endl;
                executeCommand(getCommand(), player_number);
            }
            break;
        case DISCARD:
            cout<<"cmd:discard"<<endl;
            controller_->discardCard(currentPlayer, cmd.card);
            cout << "Player " << *player_number << " discards " << cmd.card << "." << endl;
            plusPlayerNum(player_number);
            break;
        case DECK:
            cout<<"cmd:deck"<<endl;
            printDeck();
            break;
        case QUIT:
            cout<<"cmd:quit"<<endl;
            exit(1);
            break;
        case RAGEQUIT:
            cout<<"cmd:ragequit"<<endl;
            break;
        default:
            throw "Bad Command";
    }
}