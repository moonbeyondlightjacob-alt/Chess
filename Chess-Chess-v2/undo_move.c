#include "header.h"
#include <string.h>
#include <stdio.h>

#include "header.h"
#include <string.h>
#include <stdio.h>

void undo_move(Game_state *game){
    if(game->current_move_index < 0){
        printf("No moves to undo.\n");
        return;
    }

    move *m = &game->moves[game->current_move_index];
    piece *from = &game->board[m->from_row][m->from_column];
    piece *to = &game->board[m->to_row][m->to_column];
    piece moved_piece = *to;
    
    *from = moved_piece;
    
    if(m->promotion != Empty){
        from->type = Pawn;  
    }
    from->has_moved = m->was_firstmove;    
    game->board[m->to_row][m->to_column] = m->captured_piece;
    
    // Handle castling undo
    if(moved_piece.type == King && abs(m->from_column - m->to_column) == 2){
        bool king_side = (m->to_column > m->from_column);
        if(king_side){ 
            int rook_from_col = 5;  
            int rook_to_col = 7;  
            game->board[m->from_row][rook_to_col] = game->board[m->from_row][rook_from_col];
            game->board[m->from_row][rook_to_col].has_moved = false; 
            game->board[m->from_row][rook_from_col] = (piece){Empty, none, false};
        }
        else{ 
            int rook_from_col = 3;  
            int rook_to_col = 0;    
            game->board[m->from_row][rook_to_col] = game->board[m->from_row][rook_from_col];
            game->board[m->from_row][rook_to_col].has_moved = false; 
            game->board[m->from_row][rook_from_col] = (piece){Empty, none, false};
        }
    }
    
    // Handle en passant undo
    if (moved_piece.type == Pawn && m->captured_piece.type == Pawn && game->board[m->to_row][m->to_column].type == Empty &&  m->from_column != m->to_column){
        int captured_row = m->from_row; 
        int captured_col = m->to_column; 
        game->board[captured_row][captured_col] = m->captured_piece;
    } 
    // Remove from captured lists
    if(m->captured_piece.type != Empty){
        if(m->captured_piece.color == Black){ 
            if(game->white_captureCount > 0){
                game->white_captureCount--;
                game->white_captured[game->white_captureCount] = '\0';
            }
        }
        else if(m->captured_piece.color == White){ 
            if(game->black_captureCount > 0){
                game->black_captureCount--;
                game->black_captured[game->black_captureCount] = '\0';
            }
        }
    }  
    game->current_move_index--;
    switch_player(game);
}