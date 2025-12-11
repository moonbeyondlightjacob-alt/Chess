bool is_path_clear(Game_state *game, int from_row, int from_column, int to_row, int to_column){
    if(game->board[from_row][from_column].type==Knight){
        return true;
    }
    int row_steps,column_steps;
    if(to_row > from_row){
        row_steps = 1;
    else if(to_row > from_row)
        row_steps = -1;
    else    row_steps = 0;
    }       

    if(to_column > from_column){
        column_steps = 1;
    else if(to_column < from_column)
        column_steps = -1;   
    else      column_steps = 0;   
    }

    int current_row= from_row + row_steps;
    int current_column= from_column + column_steps;

    while(current_row !=to_row || current_column != to_column){
        if(game->board[current_row][current_column].type!=Empty){
            return false;
        }
        current_row += row_steps;
        current_column += column_steps;
    }

    return true;
        
}