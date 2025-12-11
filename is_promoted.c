bool in_promotion(Game_state  *game, Color color){
    if(color == White){
        for(int from_column=0; from_column < 8; from_column++ ){
                if(game->board[6][from_column].color == color && game->board[6][from_column].type== Pawn){
                    for(int to_column=0; to_column<8; ++to_column ){
                        if(is_valid_move(game, 6, from_column, 7, to_column))
                            return true;
                    }
                }
            
        }
    }

       if(color == Black){
        for(int from_column=0; from_column < 8; from_column++ ){
                if(game->board[1][from_column].color == color && game->board[1][from_column].type== Pawn){
                    for(int to_column=0; to_column<8; ++to_column ){
                        if(is_valid_move(game, 1, from_column, 0, to_column))
                            return true;
                    }
                }
            
        }
    }
return false;
}