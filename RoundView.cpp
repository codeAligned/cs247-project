#include <cstdlib>
#include "RoundView.h"

using namespace std;

void RoundView::startRound() {
    int player_number = controller_->who7Spades();
    cout << "A new round begins. It's player "<< player_number
         << "'s turn to play." << endl;
    startRoundLoop(player_number);
}

RoundView::RoundView(vector<Player*> players, int seed) {
    controller_ = new RoundController(players,seed);
    startRound();
}

RoundView::RoundView(vector<Player*> players, Deck* previous_deck, int seed ) {
    controller_ = new RoundController(players, previous_deck, seed);
    startRound();
}

RoundView::~RoundView() {
    delete controller_;
}

void plusPlayerNum(int &player_number){
    player_number = player_number+1;
    if(player_number == 5){
        player_number = 1;
    }
}

void RoundView::startTurns(int &player_number) {
    Player* currentPlayer = controller_->getPlayer(player_number);
    if (currentPlayer->isHuman()) {
        cout << "Cards on the table:" << endl;
        cout << "Clubs: ";
        printClubs();
        cout << "Diamonds: ";
        printDiamonds();
        cout << "Hearts: ";
        printHearts();
        cout << "Spades: ";
        printSpades();
        cout << "Your hand: ";
        printHand(currentPlayer);
        cout << "Legal plays: ";
        printLegalPlays(currentPlayer);//<legal plays in your hand>"
        turnLoop(player_number);
    }
    else {
        turnLoop(player_number);
    }
}

void RoundView::turnLoop(int &player_number){
    int tempNum = player_number;
    Player* currentPlayer = controller_->getPlayer(player_number);
    while(tempNum == player_number) {
        currentPlayer = controller_->getPlayer(player_number);
        Command cmd;
        if(currentPlayer->isHuman()) {
            cmd = getCommand();
        }
        else{
            cmd = controller_->playTurn(currentPlayer);
        }
        executeCommand(cmd, player_number);
    }
}

void RoundView::startRoundLoop(int &player_number){
    for(int i = 0; i<52; i++){
        startTurns(player_number);
    }
    printScores(player_number);
    controller_->updatePlayerScores();
}

void RoundView::printScores(int &player_number) {
    int starting_player = player_number;
    do {
        Player* current_player = controller_->getPlayer(player_number);
        cout << "Player " << player_number << "'s discards: ";
        printDiscards(current_player);
        int current_score = current_player->getScore();
        int round_score = controller_->getRoundScore(current_player);

        cout << "Player " << player_number << "'s score: " << current_player->getScore();
        cout << " + " << controller_->getRoundScore(current_player) << " = ";
        cout << current_score + round_score << endl;
        plusPlayerNum(player_number);
    } while (starting_player != player_number);
}

void printCardList(vector<Card*> list){
    for( int i = 0; i<list.size(); i++ ){
        cout<<*list.at(i)<<" ";
    }
    cout<<endl;
}

void printCardRank(vector<Card*> list){
    for( int i = 0; i<list.size(); i++ ){
        cout<<list.at(i)->getRank()+1<<" ";
    }
    cout<<endl;
}

void RoundView::printClubs() {
    vector<Card*> played_clubs = controller_->getClubs();
    printCardRank(played_clubs);
}

void RoundView::printDiamonds() {
    vector<Card*> played_diamonds = controller_->getDiamonds();
    printCardRank(played_diamonds);
}

void RoundView::printHearts() {
    vector<Card*> played_hearts = controller_->getHearts();
    printCardRank(played_hearts);
}

void RoundView::printSpades() {
    vector<Card*> played_spades = controller_->getSpades();
    printCardRank(played_spades);
}

void RoundView::printHand(Player* player){
    printCardList(player->getCards());
}

void RoundView::printDiscards(Player* player) {
    printCardList(player->getDiscards());
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

Deck* RoundView::getRoundDeck() {
    controller_->getDeck();
}

void RoundView::executeCommand(Command cmd, int &player_number){
    Player* currentPlayer = controller_->getPlayer(player_number);
    switch (cmd.type){
        case PLAY:
            if ( controller_->isLegalPlay(currentPlayer, cmd.card) ) {
                controller_->playCard(currentPlayer, cmd.card);
                cout << "Player " << player_number << " plays " << cmd.card << "." << endl;
                plusPlayerNum(player_number);
            }
            else {
                cout << "This is not a legal play." << endl;
                executeCommand(getCommand(), player_number);
            }
            break;
        case DISCARD:
            if (controller_->calculateLegalPlay(currentPlayer).size() == 0) {
                controller_->discardCard(currentPlayer, cmd.card);
                cout << "Player " << player_number << " discards " << cmd.card << "." << endl;
                plusPlayerNum(player_number);
            }
            else {
                cout << "You have a legal play. You may not discard." << endl;
                executeCommand(getCommand(), player_number);
            }
            break;
        case DECK:
            printDeck();
            break;
        case QUIT:
            exit(1);
        case RAGEQUIT:
            controller_->ragequit(player_number);
            break;
        default:
            throw "Bad Command";
    }
}

void RoundView::newRound(){
    controller_->newRound();
}