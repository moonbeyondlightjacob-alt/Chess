#include <stdio.h>
#include <stdbool.h>
#include "header.h"

bool move_piece(Game_state *game, int from_row, int from_column, int to_row, int to_column, piece_type promotion){
   
    if(!is_valid_move(game, from_row, from_column, to_row, to_column)){
        printf("invalid input\n");
        return false;
    }

    piece Piece = game->board[from_row][from_column];
    piece captured = game->board[to_row][to_column];
    bool was_in_check = is_in_check(game, Piece.color);

    if(Piece.type==Empty || Piece.color!= game->current_Player){
        printf("invalid input\n");
        return false;
    }
    
if(in_promotion(game,to_row, to_column,from_row ,from_column)){
        Piece.type = promotion;
    }

if(en_passant(game,from_row,from_column,to_row,to_column)){
    game->board[to_row][to_column] = Piece;
    game->board[from_row][from_column] = (piece){Empty,none,false};
    game->board[to_row][to_column].has_moved = true;
    int tr= game->moves[game->move_count-1].to_row;
    int tc = game->moves[game->move_count-1].to_column;
    captured = game->board[tr][tc];
    game->board[tr][tc] = (piece){Empty,none,false};
    }


else if(Piece.type==King && abs(from_column-to_column)==2){

    bool king_side = (to_column > from_column);
    game->board[to_row][to_column] = Piece;
    game->board[from_row][from_column] = (piece){Empty, none, false};
    game->board[to_row][to_column].has_moved = true;
    
    if(king_side){
        int rook_from_column = 7;
        int rook_to_column = 5;   
        game->board[from_row][rook_to_column] = game->board[from_row][rook_from_column];
        game->board[from_row][rook_from_column] = (piece){Empty, none, false};
        game->board[from_row][rook_to_column].has_moved = true;
    }
    else{
        int rook_from_column = 0;
        int rook_to_column = 3; 
        game->board[from_row][rook_to_column] = game->board[from_row][rook_from_column];
        game->board[from_row][rook_from_column] = (piece){Empty, none, false};
        game->board[from_row][rook_to_column].has_moved = true;
    }
}
else{
    game->board[to_row][to_column] = Piece;
    game->board[from_row][from_column]=(piece){Empty,none,false};
    game->board[to_row][to_column].has_moved = true;
}    


    if (is_in_check(game, Piece.color)) {
    game->board[from_row][from_column] = Piece;
    game->board[to_row][to_column] = captured;

    if (was_in_check)
        printf("invalid move (you're in check)\n\n");
    else
        printf("invalid move (you will get checked by this move)\n\n");

    return false;
    }


    if (game->current_move_index < game->move_count-1) {
        game->move_count = game->current_move_index+1;
    }


    move Move;
    Move.from_row = from_row;
    Move.from_column = from_column;
    Move.to_row = to_row;
    Move.to_column = to_column;
    Move.captured_piece =  captured;
    Move.promotion = promotion;
    Move.was_firstmove = !Piece.has_moved;

    if(captured.type != Empty){
        if(game->current_Player==White){
        game->white_captured[game->white_captureCount]= piece_to_char(captured);
        game->white_captureCount++;
        game->white_captured[game->white_captureCount]='\0';

        }
        else{
            game->black_captured[game->black_captureCount]= piece_to_char(captured);
            game->black_captureCount++;
            game->black_captured[game->black_captureCount]='\0';
        }
    }
    game->moves[game->move_count]= Move;
    game->move_count++;
    game->current_move_index = game->move_count - 1;

   return true;
}