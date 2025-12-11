bool is_valid_move(Game_state *game, int from_row, int from_column, int to_row, int to_column){
    piece Piece = game->board[from_row][from_column];

    switch(Piece.type){
        case Pawn:
            int step= Piece.color == White? -1 : 1;
            if(from_column==to_column){
                if(to_row == from_row+step && game->board[to_row][to_column].type==Empty){
                    return true;
                if(Piece.color==White){
                    if(from_row==6 && to_row= from_row+2*step &&  game->board[to_row][to_column].type==Empty && game->board[from_row + step][to_column].type==Empty){
                        return true;
                    }
                }
                if(Piece.color==Black){
                       if(from_row==1 && to_row= from_row+2*step &&  game->board[to_row][to_column].type==Empty && game->board[from_row + step][to_column].type==Empty){
                        return true;
                        }

                }
                
                }
            }
        else if(abs(from_column-to_column)==1 && to_row=from_row +step){
            if(game->board[to_row][to_column].color != Piece.color && game->board[to_row][to_column].type!=Empty)
                return true;
        } 
        return false;
        break;
    
        
    case King:
        if(abs(from_row-to_row)==1 && abs(from_column-to_column)==1 ){
            if(game->board[to_row][to_column].type==Empty)
                return true;
            else if(game->board[to_row][to_column].type!= Empty || game->board[to_row][to_column].color != Piece.color)
                return true;
        }
        return false;
        break;
    
    case Knight:
        
    }
}