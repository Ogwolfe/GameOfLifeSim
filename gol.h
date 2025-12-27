#ifndef GOL_H
#define GOL_H

#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Game {
    struct Grid *gameGrid;
    unsigned int **statusGrid;
};

struct Game *initGame(unsigned int size);
unsigned int **initStatusGrid(unsigned int size);
void destroyGame(struct Game *gp);
unsigned int checkCell(struct Game *gp, int x, int y);
void randomizeGrid(struct Game *gp);
void updateGrid(struct Game *gp);
void runGame(struct Game *gp, unsigned int rounds);

#endif