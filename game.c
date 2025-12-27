#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

int main(int argc, char **argv)
{
    int height = 25;
    int width = 25;
    int num_rounds = 100;

    if (argc > 4) {
        fprintf(stderr, "Error: too many arguments\n");
        fprintf(stderr, "Usage: %s [board_size] [num_rounds]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc >= 2) {
        height = atoi(argv[1]);
    }

    if (argc >= 3) {
        width = atoi(argv[2]);
    }

    if (argc == 4) {
        num_rounds = atoi(argv[3]);
    }

    if (width <= 0 || num_rounds <= 0 || height <= 0) {
        fprintf(stderr, "Error: arguments must be positive integers\n");
        return EXIT_FAILURE;
    }

    struct Game *my_game = initGame(width, height);
    if (!my_game) {
        fprintf(stderr, "Error: failed to initialize game\n");
        return EXIT_FAILURE;
    }

    runGame(my_game, num_rounds);
    destroyGame(my_game);

    return EXIT_SUCCESS;
}
