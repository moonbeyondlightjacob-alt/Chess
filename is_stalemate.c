bool is_stalemate(Game_state  *game, Color color){
      if(is_in_check(game, color))
        return false;


         for(int from_row=0; from_row < 8; from_row++ ){
            for(int from_column=0; from_column < 8; from_column++ ){
                piece current_piece = game->board[from_row][from_column];
                if(current_piece.type ==Empty || current_piece.color!=color )continue;

                if(game->board[from_row][from_column].color == color){
                    for(int to_row=0; to_row < 8; to_row++ ){
                        for(int to_column=0; to_column < 8; to_column++ ){
                            if (from_row == to_row && from_column == to_column) 
                                continue;
                    
                            if(is_valid_move(game, from_row, from_column, to_row, to_column)){
                                return false;
                            }
                        }

                    }    
                }
            }
         }
return true;
}        