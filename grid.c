#include <stdlib.h>
#include <stdio.h>
#include "grid.h"

struct Grid *createGrid(unsigned int size){
    struct Grid *gp = malloc(sizeof(struct Grid));
    if(!gp) return NULL;

    gp->grid_size = size;
    gp->grid = initGrid(size);
    if(gp->grid == NULL) return NULL;
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
    if(!p) return NULL;
    for(int i = 0; i < size; i++){
        p[i] = initRow(size);
    }
    return p;
}

char *initRow(unsigned int size){
    char *p = malloc((sizeof(char) * size) + 1);
    if(!p) return NULL;
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

char getCellValue(struct Grid *g, unsigned int x, unsigned int y){
    if(x >= g->grid_size || y >= g->grid_size) return '\0';
    return g->grid[x][y];
}

void changeCellValue(struct Grid *g, unsigned int x, unsigned int y, char val){
    if(x >= g->grid_size || y >= g->grid_size) return;
    g->grid[x][y] = val;
}