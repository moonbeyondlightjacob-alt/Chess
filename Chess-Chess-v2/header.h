#ifndef header_h
#define header_h
#include <stdbool.h>
#include <stdlib.h>

 typedef enum {
    Empty=0,
    King,
    Rook,
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


void start_game(Game_state  *game);
void display_board(const Game_state  *game);
bool is_checkmate(Game_state  *game, Color color);
bool is_stalemate(Game_state  *game, Color color);
bool in_promotion(Game_state  *game,int to_row, int to_column,int from_row, int from_column);
bool is_valid_move(Game_state *game, int from_row, int from_column, int to_row, int to_column);
bool is_path_clear(Game_state *game, int from_row, int from_column, int to_row, int to_column);
bool move_piece(Game_state *game, int from_row, int from_column, int to_row, int to_column, piece_type promotion);
char piece_to_char(piece Piece);
bool en_passant(Game_state *game, int from_row, int from_column, int to_row, int to_column);
bool castleing(Game_state *game, int from_row, int from_column, int to_row, int to_column);
void read_move(int* from_row, int* from_column, int* to_row, int* to_column, char input[]);
void save_game(const Game_state *game, const char *filename);
bool load_game(Game_state *game, const char *filename);
void piece_taken(Game_state *game);  
void redo_move(Game_state *game);
void switch_player(Game_state *game);
bool is_in_check(Game_state  *game, Color color); 
void undo_move(Game_state *game);

#endif