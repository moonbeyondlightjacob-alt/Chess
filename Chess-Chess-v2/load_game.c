#include <stdio.h>
#include "header.h"

bool load_game(Game_state *game, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open save file %s.\n", filename);
        return false;
    }

    if (fread(game, sizeof(Game_state), 1, file) != 1) {
        printf("Error: failed to load game from %s.\n", filename);
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}
