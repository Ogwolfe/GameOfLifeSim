#include <stdio.h>
#include "grid.h"

int main(void){

    struct Grid *my_grid = createGrid(12);
    
    printGrid(my_grid);
    destroyGrid(my_grid);

    return 0;
}