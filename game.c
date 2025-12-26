#include <stdio.h>
#include "grid.h"
#include "gol.h"

int main(void){

    struct Grid *my_grid = createGrid(12);
    destroyGrid(my_grid);

    struct Game *my_game = initGame(10);
    destroyGame(my_game);

    return 0;
}