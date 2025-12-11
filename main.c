#include <stdio.h>
#include <stdbool.h>

 typedef enum {
    Empty=0,
    King,
    Rock,
    Queen,
    Bishop,
    Knight,
    Pawn
}piece_type;

typedef enum{
    none=0,
    White,
    Black
}Color;

typedef struct{
    piece_type type;
    Color color;
    bool has_moved;
}piece;

typedef struct{
    int from_row, from_column;
    int to_row, to_column;
    piece captured_piece;
    piece_type promotion;
    bool was_firstmove;
}move;


typedef struct {
    piece board[8][8];
    Color current_Player;
    move moves[1000];
    int move_count;
    int current_move_index;
    char white_captured[16];
    char black_captured[16];
    int white_captureCount;
    int black_captureCount;
    bool check;
    bool checkmate;
    bool stalemate;
} Game_state;


int main(
    
)
