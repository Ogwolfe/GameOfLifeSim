#include <stdio.h>
#include <stdlib.h>

struct Grid{
    char** grid;
    unsigned int grid_size;
};

//Create a Grid struct to represent the GoL grid
struct Grid *createGrid(unsigned int size){
    struct Grid *gp = malloc(sizeof(struct Grid));
    if(!gp) return NULL;

    gp->grid_size = size;
}

//Create and initialize the char** for the grid in the Grid struct
char **initGrid(unsigned int size){
    char **gp[size];
    for(int i = 0; i < size; i++){
        char row[size + 1]; //+1 for the '\0'
        gp[i] = 
    }
}

int main(void){

    char **p = initGrid(5);

    return 0;
}