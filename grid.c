#include <stdlib.h>
#include <stdio.h>
#include "grid.h"

struct Grid *createGrid(unsigned int size){
    struct Grid *gp = malloc(sizeof(struct Grid));
    if(!gp) return NULL;

    gp->grid_size = size;
    gp->grid = initGrid(size);
    return gp;
}

void destroyGrid(struct Grid *g){
    for(int i = 0; i < g->grid_size; i++){
        free(g->grid[i]);
    }
    free(g->grid);
    free(g);
}

char **initGrid(unsigned int size){
    char **p = malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){
        p[i] = initRow(size);
    }
    return p;
}

char *initRow(unsigned int size){
    char *p = malloc((sizeof(char) * size) + 1);
    for(int i = 0; i < size; i++){
        p[i] = 'O';
    }
    p[size] = '\0';
    return p;
}

void printGrid(struct Grid *g){
    for(int i = 0; i < g->grid_size; i++){
        printf("%s\n", g->grid[i]);
    }
}