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
    int who7Spades() const;
    void startRound(int &);
    void newRound();
    std::vector<Card*> calculateLegalPlay(Player*) const;
    std::vector<Player*> getPlayers() const;
private:
    void playCard(Player*, Card);
    void discardCard(Player*, Card);
    Command playTurn(Player*);
    void ragequit(int);
    Player* getPlayer(int) const;
    bool isLegalPlay(Player*, Card) const;
    int getRoundScore(Player*) const;
    std::vector<Card*> getClubs() const;
    std::vector<Card*> getDiamonds() const;
    std::vector<Card*> getSpades() const;
    std::vector<Card*> getHearts() const;
    void executeCommand(Command, int &);
    void turnLoop(int &);
    void startTurns(int &);
    void plusPlayerNum(int &);
    void updatePlayerScores();
    std::vector<Card*> filterBySuit(Suit) const;
    RoundModel* model_;
    RoundView* view_;
};

#endif