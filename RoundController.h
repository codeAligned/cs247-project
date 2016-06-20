#ifndef _ROUNDCONTROLLER_
#define _ROUNDCONTROLLER_

#include <vector>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "RoundModel.h"
#include "RoundView.h"

class RoundController {
public:
    RoundController(std::vector<Player*>,int seed = 0);
    ~RoundController();
    int who7Spades();
    Player* getPlayer(int);
    bool isLegalPlay(Player*, Card) const;
    int getRoundScore(Player*);
    void updatePlayerScores();
    std::vector<Card*> getClubs();
    std::vector<Card*> getDiamonds();
    std::vector<Card*> getSpades();
    std::vector<Card*> getHearts();
    void executeCommand(Command, int &);
    void turnLoop(int &);
    void startTurns(int &);
    void startRound(int &);
    void plusPlayerNum(int &);
    void newRound();
    std::vector<Card*> calculateLegalPlay(Player*) const;
    void playCard(Player*, Card);
    void discardCard(Player*, Card);
    Command playTurn(Player*);
    void ragequit(int);
private:
    std::vector<Card*> filterBySuit(Suit);
    RoundModel* model_;
    RoundView* view_;
};

#endif