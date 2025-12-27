compile_command = gcc
flags = -Wall -Wextra -std=c11 -g

game = chess

files = main.c \
       move-piece.c \
       is-valid-move.c \
       castleing.c \
       is_in_check.c \
       undo_move.c \
       redo_move.c \
       switch_player.c \
       save_game.c \
       load_game.c \
       piece_taken.c \
       Display_Board.c \
       start-game.c \
       en-passant.c \
       is_path_clear.c \
       is_promoted.c \
       is_stalemate.c \
       is-checkmate.c \
       piece_to_char.c \
       read-move.c 
       

objects = $(files:.c=.o)

all: $(game)

$(game): $(objects)
	$(compile_command) $(flags) $(objects) -o $(game)

%.o: %.c header.h
	$(compile_command) $(flags) -c $< -o $@

clean:
	rm -f $(objects) $(game)

.PHONY: all clean
