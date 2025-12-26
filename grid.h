#ifndef GRID_H
#define GRID_H

struct Grid{
    char** grid;
    unsigned int grid_size;
};

//Create a Grid struct to represent the GoL grid
struct Grid *createGrid(unsigned int size);

//Create and initialize the char** for the grid in the Grid struct
char **initGrid(unsigned int size);
char *initRow(unsigned int size);

//Free all the memory allocated for the grid
void destroyGrid(struct Grid *g);

//Print the grid to console
void printGrid(struct Grid *g);

//Get and update individual char's in the grid
char getCellValue(struct Grid *g, unsigned int x, unsigned int y);
void changeCellValue(struct Grid *g, unsigned int x, unsigned int y, char val);

#endif