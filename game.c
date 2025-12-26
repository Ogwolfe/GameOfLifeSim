#include <stdio.h>
#include "grid.h"

int main(void){

    struct Grid *my_grid = createGrid(12);
    
    printGrid(my_grid);
    changeCellValue(my_grid, 0,0, 'X');
    printf("\n\n\n\n\n\n\n");
    printGrid(my_grid);
    printf("val=%c\n", getCellValue(my_grid, 0, 0));

    destroyGrid(my_grid);

    return 0;
}