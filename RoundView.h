#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include "RoundController.h"

class RoundView {
public:
    void printThings();
private:
    RoundController* controller_;
};

#endif