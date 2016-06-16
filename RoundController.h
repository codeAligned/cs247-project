#ifndef _ROUNDCONTROLLER_
#define _ROUNDCONTROLLER_

#include <vector>
#include <iostream>
#include "Player.h"
#include "ComputerPlayer.h"
#include "RoundModel.h"

class RoundController {
public:
    RoundController(std::vector<Player*>);
    ~RoundController();
    // void dealCards();
    int who7Spades();
    Player* getPlayer(int);
    // bool isLegalPlay();
    // std::vector<Card> getClubs();
    // std::vector<Card> getDiamonds();
    // std::vector<Card> getSpades();
    // std::vector<Card> getHearts();
    // std::vector<Card> calculateLegalPlay(Player);//?
    // void playCard(Player, Card);
    // void discardCard(Player, Card);
    // std::vector<Card> deck();
    // void quit();
    // ComputerPlayer ragequit();
private:
    RoundModel* model_;
};

#endif