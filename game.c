#include <stdio.h>
#include "grid.h"
#include "gol.h"

int main(void){

    struct Game *my_game = initGame(25);
    runGame(my_game, 200);
    destroyGame(my_game);

    return 0;
}