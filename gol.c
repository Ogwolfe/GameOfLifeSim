#include "gol.h"

struct Game *initGame(unsigned int size){
    struct Game *gp = malloc(sizeof(struct Game));
    if(!gp) return NULL;

    gp->gameGrid = createGrid(size);
    if(gp->gameGrid == NULL) return NULL;

    gp->statusGrid = initStatusGrid(size);



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

