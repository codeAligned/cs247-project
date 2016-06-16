#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include <iostream>
#include "RoundController.h"

class RoundView {
public:
    RoundView(std::vector<Player*>);
    ~RoundView();
    void printThings();
    void startTurns(int);
private:
    RoundController* controller_;
};

#endif