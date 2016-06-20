#include "RoundController.h"

using namespace std;

RoundController::RoundController(vector<Player*> players, int seed) {
    Deck* new_deck = new Deck(seed);
    new_deck->shuffle();
    model_ = new RoundModel(players, new_deck);
    int player_7spades = who7Spades();
    view_ = new RoundView(player_7spades);
    startRound(player_7spades);
}

// Loop through each player's hand and check if they have 7 Spades
int RoundController::who7Spades() const{
    vector<Player*> players = model_->getPlayers();
    for ( int i = 0; i < players.size(); ++i ) {
        vector<Card*> tempHand = players.at(i)->getCards();
        for( int j = 0; j < tempHand.size(); ++j) {
            if(tempHand.at(j)->getRank() == SEVEN && tempHand.at(j)->getSuit() == SPADE){
                return i+1;
            }
        }
    }
    return -1;
}

RoundController::~RoundController() {
    delete model_;
    delete view_;
}

void RoundController::startRound(int &player_number) {
    for(int i = 0; i < 52; ++i) {
        startTurns(player_number);
    }
    updatePlayerScores();
}

void RoundController::startTurns(int &player_number) {
    Player* currentPlayer = getPlayer(player_number);
    if (currentPlayer->isHuman()) {
        view_->printHumanInfo(getClubs(), getDiamonds(), getHearts(), getSpades(),
                              currentPlayer->getCards(), calculateLegalPlay(currentPlayer));
    }
    turnLoop(player_number);
}

void RoundController::turnLoop(int &player_number) {
    int temp_num = player_number;
    Player* currentPlayer = getPlayer(player_number);
    while(temp_num == player_number) {
        currentPlayer = getPlayer(player_number);
        Command cmd;
        if(currentPlayer->isHuman()) {
            cmd = view_->getCommand();
        }
        else{
            cmd = playTurn(currentPlayer);
        }
        executeCommand(cmd, player_number);
    }
}

void RoundController::plusPlayerNum(int &player_number) {
    player_number = player_number+1;
    if(player_number == 5){
        player_number = 1;
    }
}

void RoundController::executeCommand(Command cmd, int &player_number) {
    Player* currentPlayer = getPlayer(player_number);
    switch (cmd.type){
        case PLAY:
            if ( isLegalPlay(currentPlayer, cmd.card) ) {
                playCard(currentPlayer, cmd.card);
                view_->printPlayMessage(player_number, cmd.card);
                plusPlayerNum(player_number);
            }
            else {
                view_->printIllegalPlay();
                executeCommand(view_->getCommand(), player_number);
            }
            break;
        case DISCARD:
            if (calculateLegalPlay(currentPlayer).size() == 0) {
                discardCard(currentPlayer, cmd.card);
                view_->printDiscardMessage(player_number, cmd.card);
                plusPlayerNum(player_number);
            }
            else {
                view_->printBadDiscard();
                executeCommand(view_->getCommand(), player_number);
            }
            break;
        case DECK:
            view_->printDeck(model_->getDeck());
            break;
        case QUIT:
            exit(0);
        case RAGEQUIT:
            ragequit(player_number);
            break;
        default:
            throw "Bad Command";
    }
}

int RoundController::getRoundScore(Player* p) const {
    int roundScore = 0;
    vector<Card*> discards = p->getDiscards();
    for (int i = 0; i < discards.size(); ++i) {
        roundScore += discards.at(i)->getRank()+1;
    }
    return roundScore;
}

void RoundController::updatePlayerScores() {
    vector<Player*> players = model_->getPlayers();
    for (int i = 0; i < players.size(); ++i) {
        Player* current_player = players.at(i);
        int current_score = current_player->getScore();
        int round_score = getRoundScore( current_player );
        view_->printPlayerScore(current_player->getDiscards(), current_score, round_score, i+1);
        players.at(i)->setScore(current_score + round_score);
    }
}

Player* RoundController::getPlayer(int playerID) const{
    return model_->getPlayer(playerID);
}

void RoundController::playCard(Player* p, Card c){
    model_->playCard(c);
    p->playCard(c);
}

void RoundController::discardCard(Player* p, Card c){
    p->discardCard(c);
}

// Returns vector of legal plays for a player
vector<Card*> RoundController::calculateLegalPlay(Player* p) const{
    vector<Card*> played = model_->getPlayedCards();
    vector<Card*> hand = p->getCards();
    vector<Card*> ret = vector<Card*>();

    // If first turn, only legal play is 7 spades
    if(model_->getPlayedCards().size() == 0){
        for( int i = 0; i < hand.size(); ++i ){
            if(hand.at(i)->getSuit()== SPADE && hand.at(i)->getRank() == SEVEN){
                ret.push_back(hand.at(i));
                return ret;
            }
        }
    }

    // Check player's hand and round's played cards for legal plays
    for(int i = 0; i < hand.size(); ++i ) {

        for(int j = 0; j < played.size(); ++j) {
            if(played.at(j)->getSuit()==hand.at(i)->getSuit() && abs(played.at(j)->getRank() - hand.at(i)->getRank())<=1 ){
                ret.push_back(hand.at(i));
                break;
            }
            else if(hand.at(i)->getRank()==SEVEN){
                ret.push_back(hand.at(i));
                break;
            }
        }

    }
    return ret;
}

bool RoundController::isLegalPlay(Player* p, Card c) const{
    vector<Card*> legal_plays = calculateLegalPlay(p);
    for (int i = 0; i < legal_plays.size(); ++i) {
        if (c == *(legal_plays.at(i)) )
            return true;
    }
    return false;
}

vector<Card*> RoundController::getClubs() const {
    return filterBySuit(static_cast<Suit>(0));
}
vector<Card*> RoundController::getDiamonds() const {
    return filterBySuit(static_cast<Suit>(1));
}
vector<Card*> RoundController::getHearts() const {
    return filterBySuit(static_cast<Suit>(2));
}
vector<Card*> RoundController::getSpades() const {
    return filterBySuit(static_cast<Suit>(3));
}

vector<Card*> RoundController::filterBySuit(Suit suit) const {
    vector<Card*> temp = model_->getPlayedCards();
    vector<Card*> ret = vector<Card*>();
    for(int i = 0; i < temp.size(); ++i ){
        if(temp.at(i)->getSuit() == suit){
            ret.push_back(temp.at(i));
        }
    }
    return ret;
}

Command RoundController::playTurn(Player* player) {
    ComputerPlayer* playerTemp = static_cast<ComputerPlayer*>(player);
    return playerTemp->playTurn(this);
}

void RoundController::ragequit(int player_number) {
    Player* p = model_->getPlayer(player_number);
    ComputerPlayer* newPlayer = new ComputerPlayer(*p);
    model_->ragequit(player_number, newPlayer);
}

void RoundController::newRound() {
    model_->newRound();
    view_->printNewRound(who7Spades());
}