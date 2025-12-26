#include <stdio.h>
#include <stdlib.h>

struct Grid{
    char** grid;
    unsigned int grid_size;
};

//Function Prototypes
struct Grid *createGrid(unsigned int size);
char **initGrid(unsigned int size);
char *initRow(unsigned int size);

//Create a Grid struct to represent the GoL grid
struct Grid *createGrid(unsigned int size){
    printf("Entered createGrid()\n");
    struct Grid *gp = malloc(sizeof(struct Grid));
    if(!gp) return NULL;

    gp->grid_size = size;
    gp->grid = initGrid(size);
    return gp;
}

void destroyGrid(struct Grid *g){
    printf("Entered destroyGrid()\n");
    for(int i = 0; i < g->grid_size; i++){
        printf("Entered loop\n");
        free(g->grid[i]);
    }
    free(g->grid);
    printf("free(g->grid)\n");
    free(g);
    printf("free g\n");
}

//Create and initialize the char** for the grid in the Grid struct
char **initGrid(unsigned int size){
    printf("Entered initGrid()\n");
    char **p = malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){
        p[i] = initRow(size);
    }
    return p;
}

char *initRow(unsigned int size){
    char *p = malloc((sizeof(char) * size) + 1);
    for(int i = 0; i < size; i++){
        p[i] = '#';
    }
    p[size] = '\0';
    return p;
}

int main(void){

    struct Grid *my_grid = createGrid(5);
    printf("Exited createGrid()\n");
    destroyGrid(my_grid);
    printf("Exited destroyGrid()\n");

    return 0;
}