#ifndef GOL_H
#define GOL_H

#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

struct Game {
    struct Grid *gameGrid;
    unsigned int **statusGrid;
};

struct Game *initGame(unsigned int size);
unsigned int **initStatusGrid(unsigned int size);
void destroyGame(struct Game *gp);

#endif