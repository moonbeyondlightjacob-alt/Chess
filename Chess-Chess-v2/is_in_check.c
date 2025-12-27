#include "header.h"

static bool in_bounds(int r, int c)
{
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}
bool is_in_check(Game_state *game, Color color) {
    int king_row = -1, king_col = -1;
    
 
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (game->board[r][c].type == King && 
                game->board[r][c].color == color) {
                king_row = r;
                king_col = c;
                break;
            }
        }
        if (king_row != -1) break;
    }
    
    if (king_row == -1) return false;

    Color enemy = (color == White) ? Black : White;
    
    if(color == White){
        if (in_bounds(king_row - 1, king_col - 1)) {
            piece p = game->board[king_row - 1][king_col - 1];
            if (p.type == Pawn && p.color == Black) return true;
        }
        if (in_bounds(king_row - 1, king_col + 1)) {
            piece p = game->board[king_row - 1][king_col + 1];
            if (p.type == Pawn && p.color == Black) return true;
        }
    } 
    else{
        if(in_bounds(king_row + 1, king_col - 1)){
            piece p = game->board[king_row + 1][king_col - 1];
            if (p.type == Pawn && p.color == White) return true;
        }
        if(in_bounds(king_row + 1, king_col + 1)){
            piece p = game->board[king_row + 1][king_col + 1];
            if (p.type == Pawn && p.color == White) return true;
        }
    }

    
    int knight_moves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    
    for (int i = 0; i < 8; i++) {
        int r = king_row + knight_moves[i][0];
        int c = king_col + knight_moves[i][1];
        if (in_bounds(r, c)) {
            piece p = game->board[r][c];
            if (p.type == Knight && p.color == enemy) return true;
        }
    }
    
    int rook_dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < 4; i++) {
        int r = king_row + rook_dirs[i][0];
        int c = king_col + rook_dirs[i][1];
        
        while (in_bounds(r, c)) {
            piece p = game->board[r][c];
            if (p.type != Empty) {
                if (p.color == enemy && (p.type == Rook || p.type == Queen)) {
                    return true;
                }
                break; 
            }
            r += rook_dirs[i][0];
            c += rook_dirs[i][1];
        }
    }
    
    int bishop_dirs[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    for (int i = 0; i < 4; i++) {
        int r = king_row + bishop_dirs[i][0];
        int c = king_col + bishop_dirs[i][1];
        
        while (in_bounds(r, c)) {
            piece p = game->board[r][c];
            if (p.type != Empty) {
                if (p.color == enemy && (p.type == Bishop || p.type == Queen)) {
                    return true;
                }
                break; 
            }
            r += bishop_dirs[i][0];
            c += bishop_dirs[i][1];
        }
    }

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            
            int r = king_row + dr;
            int c = king_col + dc;
            
            if (in_bounds(r, c)) {
                piece p = game->board[r][c];
                if (p.type == King && p.color == enemy) return true;
            }
        }
    }
    return false;
}