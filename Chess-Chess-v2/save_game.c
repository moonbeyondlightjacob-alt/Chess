#include <stdio.h>
#include "header.h"

void save_game(const Game_state *game, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open save file %s.\n", filename);
        return;
    }

    fwrite(game, sizeof(Game_state), 1, file);
    fclose(file);

    printf("Game saved successfully to %s.\n", filename);
}



