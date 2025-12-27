#include "header.h"

bool castleing(Game_state *game, int from_row, int from_column, int to_row, int to_column){
    piece king = game->board[from_row][from_column];
    if(king.type != King) return false;
    if(king.has_moved) return false;
    
    bool king_side = false;
    bool queen_side = false;
    
    if(king.color == White){
        if(from_row == 7 && from_column == 4){  
            if(to_row == 7 && to_column == 6){  
                king_side = true;
            }
             else if(to_row == 7 && to_column == 2){
                queen_side = true;
            } 
            else{
                return false;  
            }
        }
    }
    else if(king.color == Black) {
        if(from_row == 0 && from_column == 4){ 
            if(to_row == 0 && to_column == 6){  
                king_side = true;
            }
            else if(to_row == 0 && to_column == 2){  
                queen_side = true;
            } 
            else{
                return false;  
            }
        }
    }
    int rook_from_column;
    piece rook;
    
    if(king_side) {
        rook_from_column = 7; 
    } 
    else if(queen_side){
        rook_from_column = 0;  
    }
    else {
        return false;
    }
    
    rook = game->board[from_row][rook_from_column];
    if(rook.type != Rook || rook.color != king.color || rook.has_moved){
        return false;
    }
    
    if(king_side){
       
        if(game->board[from_row][5].type != Empty || game->board[from_row][6].type != Empty) {
            return false;
        }
    } 
    else if(queen_side){      
        if(game->board[from_row][1].type != Empty || 
           game->board[from_row][2].type != Empty || 
           game->board[from_row][3].type != Empty){
            return false;
        }
    }
    if(is_in_check(game, king.color)){
        return false;
    }
    
    int intermediate_column1, intermediate_column2;
      if(king_side){
        intermediate_column1 = 5;  
        intermediate_column2 = 6;  
    } 
    else{ 
        intermediate_column1 = 3;  
        intermediate_column2 = 2;  
    }
    
    Game_state temp_state = *game;
    temp_state.board[from_row][intermediate_column1] = king;
    temp_state.board[from_row][from_column] = (piece){Empty, none, false};
    if(is_in_check(&temp_state, king.color)){
        return false;
    }
    
    temp_state.board[from_row][intermediate_column1] = (piece){Empty, none, false};
    temp_state.board[from_row][intermediate_column2] = king;
    if(is_in_check(&temp_state, king.color)){
        return false;
    }
    return true;
}