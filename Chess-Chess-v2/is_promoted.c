#include <stdio.h>
#include <stdbool.h>
#include "header.h"

bool in_promotion(Game_state  *game,int to_row, int to_column,int from_row, int from_column ){
    piece Piece = game->board[from_row][from_column];

    if(Piece.type!=Pawn){
        return false;
    }
    if(Piece.color==White && to_row==0 ){
        return is_valid_move(game,from_row,from_column,to_row,to_column);
    }

    if(Piece.color==Black && to_row==7 ){
        return is_valid_move(game,from_row,from_column,to_row,to_column);;
    }
return false;
}