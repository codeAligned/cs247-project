#include "Game.h"
#include <iostream>
#include <cstdlib>

int main(int args, char* argv[]) {
    if(args>1){
        int seed = atoi(argv[0]);
        Game new_game = Game(seed);
    }
    else{
        Game new_game = Game();
    }
    exit(0);
}