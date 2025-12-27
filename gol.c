#include "gol.h"

struct Game *initGame(unsigned int size){
    struct Game *gp = malloc(sizeof(struct Game));
    if(!gp) return NULL;

    gp->gameGrid = createGrid(size);
    if(gp->gameGrid == NULL) return NULL;

    gp->statusGrid = initStatusGrid(size);
    randomizeGrid(gp);

    return gp;
}

unsigned int **initStatusGrid(unsigned int size){
    unsigned int **ip = malloc(sizeof(unsigned int *) * size);    //array of int * with size elements
    if(ip == NULL) return NULL;

    for(int i = 0; i < size; i++){
        ip[i] = malloc(sizeof(unsigned int) * size);
    }

    //initialize the 2d array to 0
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            ip[i][j] = 0;

    return ip;
}

void destroyGame(struct Game *gp){
    int x = gp->gameGrid->grid_size;
    destroyGrid(gp->gameGrid);
    for(int i = 0; i < x; i++)
        free(gp->statusGrid[i]);
    free(gp->statusGrid);
}

void randomizeGrid(struct Game *gp){
    srand(time(NULL));
    for(int i = 0; i < gp->gameGrid->grid_size; i++){
        for(int j = 0; j < gp->gameGrid->grid_size; j++){
            gp->statusGrid[i][j] = rand() % 2;
        }
    }
}

//returns inner field state. If 3 -> cell will live, if 4 -> nothing, anything else -> cell dies
unsigned int checkCell(struct Game *gp, int x, int y){
    unsigned int size = gp->gameGrid->grid_size;
    unsigned int count = 0;

    //Loop over 3x3 array with target at center
    for(int i = x - 1; i <= x + 1; i++){
        for(int j = y - 1; j <= y + 1; j++){
            if(i < 0 || i > size - 1 || j < 0 || j > size - 1)
                continue;
            if(gp->gameGrid->grid[i][j] == '*')
                count++;
        }
    }

    return count;
}

void updateGrid(struct Game *gp){

    //Set the char grid based on status grid
    for(int i = 0; i < gp->gameGrid->grid_size; i++){
        for(int j = 0; j < gp->gameGrid->grid_size; j++){
            gp->gameGrid->grid[i][j] = gp->statusGrid[i][j] ? '*' : ' ';
        }
    }

    //Update status grid based on char grid
    unsigned int x;
    for(int i = 0; i < gp->gameGrid->grid_size; i++){
        for(int j = 0; j < gp->gameGrid->grid_size; j++){
            if((x = checkCell(gp, i, j)) == 4)
                continue;
            else if(x == 3)
                gp->statusGrid[i][j] = 1;
            else
                gp->statusGrid[i][j] = 0;
        }
    }
}

void runGame(struct Game *gp, unsigned int rounds){
    for(int i = 0; i < rounds; i++){
        updateGrid(gp);
        printGrid(gp->gameGrid);
        usleep(1000 * 100);
        printf("\n\n\n\n\n\n\n\n\n");
    }
}