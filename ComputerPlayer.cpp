
#include "RoundController.h"
//#include "Player.h"
//#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer() {

}

bool ComputerPlayer::isHuman() const{
    return false;
}

void ComputerPlayer::playTurn(RoundController* controller) {
    vector<Card*> legalPlays = controller->calculateLegalPlay(this);
    vector<Card*> hand = hand_->getCards();
    //If we have a play, play it
    for(int i=0;i<hand.size();i++){
        for(int j=0;j<legalPlays.size();j++){
            if(*hand.at(i) == *legalPlays.at(j)){
                controller->playCard(this,*hand.at(i));
                return;
            }
        }
    }
    //else discard
    controller->discardCard(this,*hand.at(0));
    return;
}