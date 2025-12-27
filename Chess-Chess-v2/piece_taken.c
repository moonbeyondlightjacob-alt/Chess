#include <stdio.h>
#include "header.h"

void piece_taken(Game_state *game) {
    printf("White captured: ");
    for (int i = 0; i < game->white_captureCount; i++)
        printf("%c ", game->white_captured[i]);
    printf("\n");

    printf("Black captured: ");
    for (int i = 0; i < game->black_captureCount; i++)
        printf("%c ", game->black_captured[i]);
    printf("\n");
}