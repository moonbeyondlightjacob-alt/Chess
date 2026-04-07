#include "header.h"

void switch_player(Game_state *game) {
    if (game->current_Player == White)
        game->current_Player = Black;
    else
        game->current_Player = White;
}

