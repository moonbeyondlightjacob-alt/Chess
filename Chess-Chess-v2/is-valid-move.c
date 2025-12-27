#include "header.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_valid_move(Game_state *game, int from_row, int from_column, int to_row, int to_column){
    piece Piece = game->board[from_row][from_column];
    if((from_column==to_column) && (from_row==to_row))
        return false;
    if(from_row<0 || from_column<0 || to_row<0 || to_column<0){
    return false;
}

    switch(Piece.type){
        case Pawn: {
            int step= Piece.color == White? -1 : 1;
            if(en_passant(game,from_row,from_column,to_row,to_column)){
                return true;
            }
            else if(from_column==to_column){
                if(to_row == from_row+step && game->board[to_row][to_column].type==Empty){
                    return true;
                }
                if(Piece.color==White){
                    if( from_row==6 && to_row == from_row+2*step &&  game->board[to_row][to_column].type==Empty && game->board[from_row + step][to_column].type==Empty){
                        return true;
                    }
                
                }
                if(Piece.color==Black){
                       if(from_row==1 && to_row== from_row+2*step &&  game->board[to_row][to_column].type==Empty && game->board[from_row + step][to_column].type==Empty){
                        return true;
                        }

                }
                
                
            }
        else if(abs(from_column-to_column)==1 && to_row== (from_row +step)){
            if(game->board[to_row][to_column].color != Piece.color && game->board[to_row][to_column].type!=Empty)
                return true;
        } 
       
        return false;
        }
        
    case King:
        if(abs(from_column - to_column) == 2 && from_row == to_row){
            if(castleing(game, from_row, from_column, to_row, to_column)){
            return true;
            }
        }

        if(abs(from_row-to_row)==1 && abs(from_column-to_column)==1){
            if(game->board[to_row][to_column].type==Empty)
                return true;
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                return true;
        }
        else if(abs(from_row-to_row)==1 && from_column-to_column ==0){
            if(game->board[to_row][to_column].type==Empty)
                return true;
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                return true;
        }
        else if(abs(from_column-to_column)==1 && from_row-to_row==0){
            if(game->board[to_row][to_column].type==Empty)
                return true;
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                return true;
        }
        return false;
        
    
    case Knight:
        if((abs(from_row-to_row)==2 && abs(from_column-to_column)==1) || (abs(from_row-to_row)==1 && abs(from_column-to_column)==2)){
            if(game->board[to_row][to_column].type==Empty)
                return true;
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                return true;
        }
        return false;
        

    case Bishop:
        if(abs(from_row-to_row)==abs(from_column-to_column)){
            if(game->board[to_row][to_column].type==Empty)
                return is_path_clear(game, from_row, from_column, to_row, to_column);
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                 return is_path_clear(game, from_row, from_column, to_row, to_column);
        }
        return false;
        

    case Queen:
        if(abs(from_row-to_row)==abs(from_column-to_column)){
            if(game->board[to_row][to_column].type==Empty)
                return is_path_clear(game, from_row, from_column, to_row, to_column);
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                 return is_path_clear(game, from_row, from_column, to_row, to_column);
        }

        else if(from_row==to_row || from_column==to_column){
            if(game->board[to_row][to_column].type==Empty)
                return is_path_clear(game, from_row, from_column, to_row, to_column);
            else if(game->board[to_row][to_column].type != Empty && game->board[to_row][to_column].color != Piece.color)
                 return is_path_clear(game, from_row, from_column, to_row, to_column);
        }
        return false;
        

    case Rook:
        if(from_row==to_row || from_column==to_column){
            if(game->board[to_row][to_column].type==Empty)
                return is_path_clear(game, from_row, from_column, to_row, to_column);
            else if(game->board[to_row][to_column].type!= Empty && game->board[to_row][to_column].color != Piece.color)
                 return is_path_clear(game, from_row, from_column, to_row, to_column);
        }
        return false;
        break;
    default:
        return false;
        
    }
    return false;
}
