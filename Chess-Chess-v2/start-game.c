#include <stdio.h>
#include <stdbool.h>
#include "header.h"

void start_game(Game_state  *game){
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            game->board[i][j].type=Empty;
            game->board[i][j].color=none;
            game->board[i][j].has_moved=false;
        }
    }
    game->board[0][0].type=Rook;
    game->board[0][1].type=Knight;
    game->board[0][2].type=Bishop;
    game->board[0][3].type=Queen;
    game->board[0][4].type=King;
    game->board[0][5].type=Bishop;
    game->board[0][6].type=Knight;
    game->board[0][7].type=Rook;

    game->board[7][0].type=Rook;
    game->board[7][1].type=Knight;
    game->board[7][2].type=Bishop;
    game->board[7][3].type=Queen;
    game->board[7][4].type=King;
    game->board[7][5].type=Bishop;
    game->board[7][6].type=Knight;
    game->board[7][7].type=Rook;


    for(int i=0; i<8; ++i){
         game->board[1][i].type=Pawn;
         game->board[1][i].color=Black;
         game->board[0][i].color=Black;
         game->board[6][i].type=Pawn;
         game->board[6][i].color=White;
         game->board[7][i].color=White;
    }


    game->check=false;
    game->checkmate=false;
    game->stalemate=false;
    game->current_Player=White;
    game->white_captureCount=0;
    game->black_captureCount=0;
    game->move_count = 0;
    game->current_move_index = -1;
}