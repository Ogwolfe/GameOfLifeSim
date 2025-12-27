#include <stdlib.h>
#include <stdio.h>
#include "grid.h"

struct Grid *createGrid(unsigned int w, unsigned int h){
    struct Grid *gp = malloc(sizeof(struct Grid));
    if(!gp) return NULL;

    gp->width = w;
    gp->height = h;
    gp->grid = initGrid(w, h);
    if(gp->grid == NULL) return NULL;
    return gp;
}

void destroyGrid(struct Grid *g){
    for(int i = 0; i < g->height; i++){
        free(g->grid[i]);
    }
    free(g->grid);
    free(g);
}

char **initGrid(unsigned int w, unsigned int h){
    char **p = malloc(sizeof(char*) * h);
    if(!p) return NULL;
    for(int i = 0; i < h; i++){
        p[i] = initRow(w);
    }
    return p;
}

char *initRow(unsigned int size){
    char *p = malloc((sizeof(char) * size) + 1);
    if(!p) return NULL;
    for(int i = 0; i < size; i++){
        p[i] = '*';
    }
    p[size] = '\0';
    return p;
}

void printGrid(struct Grid *g){
    for(int i = 0; i < g->height; i++){
        printf("%s\n", g->grid[i]);
    }
}


char getCellValue(struct Grid *g, unsigned int x, unsigned int y){
    if(x >= g->height || y >= g->width) return '\0';
    return g->grid[x][y];
}

void changeCellValue(struct Grid *g, unsigned int x, unsigned int y, char val){
    if(x >= g->height || y >= g->width) return;
    g->grid[x][y] = val;
}