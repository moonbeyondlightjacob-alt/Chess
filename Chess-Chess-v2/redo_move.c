#include "header.h"
#include <stdio.h>
#include "header.h"
#include <stdio.h>

void redo_move(Game_state *game){
    if(game->current_move_index >= game->move_count - 1){
        printf("No moves to redo.\n");
        return;
    }
    game->current_move_index++;
    move *m = &game->moves[game->current_move_index];
    
    // Save the piece at destination before moving
    piece dest_piece = game->board[m->to_row][m->to_column];
    
    // Move the piece
    piece *from = &game->board[m->from_row][m->from_column];
    piece *to = &game->board[m->to_row][m->to_column];
    piece moved_piece = *from;
    
    *to = moved_piece;
    
    if(m->promotion != Empty){
        to->type = m->promotion;
    }
    to->has_moved = true;
    
    from->type = Empty;
    from->color = none;
    from->has_moved = false;
    
    // Handle castling
    if(moved_piece.type == King && abs(m->from_column - m->to_column) == 2){
        bool king_side = (m->to_column > m->from_column);
        if(king_side){ 
            int rook_from_col = 7;
            int rook_to_col = 5;
            game->board[m->from_row][rook_to_col] = game->board[m->from_row][rook_from_col];
            game->board[m->from_row][rook_to_col].has_moved = true;
            game->board[m->from_row][rook_from_col] = (piece){Empty, none, false};
        }
        else{ 
            int rook_from_col = 0;
            int rook_to_col = 3;
            game->board[m->from_row][rook_to_col] = game->board[m->from_row][rook_from_col];
            game->board[m->from_row][rook_to_col].has_moved = true;
            game->board[m->from_row][rook_from_col]= (piece){Empty, none, false};
        }
    }
    
    // Handle en passant 
    if(moved_piece.type == Pawn &&  m->captured_piece.type != Empty && dest_piece.type == Empty &&m->from_column != m->to_column){
        int captured_row = m->from_row;  
        int captured_col = m->to_column; 
        game->board[captured_row][captured_col]=(piece){Empty,none,false};
    }
    
    // Handle captured piece
    if(m->captured_piece.type != Empty && dest_piece.type != Empty){
        char ch = piece_to_char(m->captured_piece);
        
        // Add to capturing player's list
        if(m->captured_piece.color == Black){ 
            if(game->white_captureCount < 16){
                game->white_captured[game->white_captureCount++] = ch;
                game->white_captured[game->white_captureCount] = '\0';
            }
        }
        else if(m->captured_piece.color == White){
            if(game->black_captureCount < 16){
                game->black_captured[game->black_captureCount++] = ch;
                game->black_captured[game->black_captureCount] = '\0';
            }
        }
    }
    switch_player(game);
}