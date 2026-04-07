#include "header.h"
#include <stdlib.h>

bool en_passant(Game_state *game, int from_row, int from_column, int to_row, int to_column){
    if(game->move_count==0)return false;
    
    int fr = game->moves[game->move_count-1].from_row;
    int fc = game->moves[game->move_count-1].from_column;
    int tr = game->moves[game->move_count-1].to_row;
    int tc = game->moves[game->move_count-1].to_column;
    piece opponent_pawn = game->board[tr][tc];  
    piece our_pawn = game->board[from_row][from_column];
    int step = (our_pawn.color == White) ? -1 : 1;
    

    if(opponent_pawn.type != Pawn || our_pawn.type != Pawn) return false;
    if(opponent_pawn.color == our_pawn.color) return false;
    if(abs(fr - tr) != 2 || fc != tc) return false;
    if(tr != from_row || abs(tc - from_column) != 1) return false;
    if(to_row != from_row + step || to_column != tc) return false;
    if(game->board[to_row][to_column].type != Empty) return false;

    return true;
}