#ifndef _ROUNDCONTROLLER_
#define _ROUNDCONTROLLER_

#include <vector>
#include "RoundModel.h"
#include "Player.h"

class RoundController {
public:
    RoundController();
    ~RoundController();
    void dealCards();
    Player who7Spades();
    bool isLegalPlay();
    std::vector<Card> getClubs();
    std::vector<Card> getDiamonds();
    std::vector<Card> getSpades();
    std::vector<Card> getHearts();
    std::vector<Card> calculateLegalPlay(Player);//?
    void playCard(Player, Card);
    void discardCard(Player, Card);
    std::vector<Card> deck();
    void quit();
    ComputerPlayer ragequit();
private:
    RoundModel* model_;
};

#endif