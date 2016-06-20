#include "RoundView.h"

using namespace std;

RoundView::RoundView(int player_7spades) {
    printNewRound(player_7spades);
}

void RoundView::printNewRound(int player_7spades) {
    cout << "A new round begins. It's player "<< player_7spades
         << "'s turn to play." << endl;
}

// Print things for human player's turn
void RoundView::printHumanInfo(vector<Card*> clubs, vector<Card*> diamonds, vector<Card*> hearts,
                               vector<Card*> spades, vector<Card*> player_hand,
                               vector<Card*> legal_plays)
{
    cout << "Cards on the table:" << endl;
    cout << "Clubs: ";       printCardRank(clubs);
    cout << "Diamonds: ";    printCardRank(diamonds);
    cout << "Hearts: ";      printCardRank(hearts);
    cout << "Spades: ";      printCardRank(spades);
    cout << "Your hand: ";   printCardList(player_hand);
    cout << "Legal plays: "; printCardList(legal_plays);
}

// Print player's discards, current score and new score.
void RoundView::printPlayerScore(vector<Card*> discards, int current_score, int round_score, int player_number) {
        cout << "Player " << player_number << "'s discards: ";
        printCardList(discards);
        cout << "Player " << player_number << "'s score: " << current_score;
        cout << " + " << round_score << " = ";
        cout << current_score + round_score << endl;
}

// Print cards' ranks and suits
void RoundView::printCardList(vector<Card*> list){
    for( int i = 0; i < list.size(); ++i ){
        cout << *list.at(i) << " ";
    }
    cout << endl;
}

// Print only cards' ranks (for cards on table)
void RoundView::printCardRank(vector<Card*> list){
    for(int i = 0; i<list.size(); ++i ) {
        cout << list.at(i)->getRank()+1 << " ";
    }
    cout << endl;
}

void RoundView::printDeck(Deck* deck){
    for(int suit_index = 0; suit_index < SUIT_COUNT; ++suit_index) {
        for(int rank_index = 0; rank_index < RANK_COUNT; ++rank_index) {
            cout << * (deck->at( 13*suit_index + rank_index )) << " ";
        }
        cout << endl;
    }
}

void RoundView::printPlayMessage(int player_number, Card card_played) {
    cout << "Player " << player_number << " plays " << card_played << "." << endl;
}

void RoundView::printIllegalPlay() {
    cout << "This is not a legal play." << endl;
}

void RoundView::printDiscardMessage(int player_number, Card card_discarded) {
    cout << "Player " << player_number << " discards " << card_discarded << "." << endl;
}

void RoundView::printBadDiscard() {
    cout << "You have a legal play. You may not discard." << endl;
}

// Get command inputted by user
Command RoundView::getCommand(){
    Command cmd;
    cin.clear();
    cout << ">";
    cin>>cmd;
    return cmd;
}