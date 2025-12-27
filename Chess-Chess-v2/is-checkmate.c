#include <stdio.h>
#include <stdbool.h>
#include "header.h"

bool is_checkmate(Game_state  *game, Color color){
    if(!(is_in_check(game, color)))
        return false;

    for(int from_row=0; from_row < 8; from_row++ ){
        for(int from_column=0; from_column < 8; from_column++ ){
            if(game->board[from_row][from_column].color==color){
                for(int to_row=0; to_row < 8; to_row++ ){
                    for(int to_column=0; to_column < 8; to_column++ ){
                        if (from_row == to_row && from_column == to_column) 
                            continue;
                    
                        if(is_valid_move(game, from_row, from_column, to_row, to_column)){
                                piece captured = game->board[to_row][to_column];
                                piece moving = game->board[from_row][from_column];
                                game->board[to_row][to_column] = moving;
                                game->board[from_row][from_column] = (piece){Empty, none, false};
                                
                                
                                bool still_checked = (is_in_check(game, color));

                                game->board[from_row][from_column] = moving;
                                game->board[to_row][to_column] = captured;

                                if(!still_checked){
                                    return false;

                                }
       
                        }

                    }
                }

            }
        }
    }
    
return true;
    
}