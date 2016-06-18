#ifndef _ROUNDMODEL_
#define _ROUNDMODEL_

#include <vector>
#include "Player.h"
#include "Deck.h"

class RoundModel {
public:
    RoundModel(std::vector<Player*>, Deck*);
    ~RoundModel();
    std::vector<Player*> getPlayers();
    Player* getPlayer(int playerID);
    Deck* getDeck() const;
    void playCard(Card c);
    std::vector<Card*> getPlayedCards() const;
private:
    std::vector<Player*> players_;
    std::vector<Card*> played_cards_;
    Deck* deck_;
};

#endif