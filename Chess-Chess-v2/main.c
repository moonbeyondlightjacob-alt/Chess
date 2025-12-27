#include <stdio.h>
#include <stdbool.h>
#include "header.h"
#include <string.h>

int main(){
    Game_state game;
    bool on_going = true;
    char input[20];

start_game(&game);
printf("****************************************************\n");
printf("              Welcome to chess\n");
printf("****************************************************\n");

    while(on_going && !game.checkmate && !game.stalemate){
        display_board(&game);
        piece_taken(&game);

        int from_row , from_column, to_row, to_column;
        piece_type promotion = Empty;
        char p;
        
        printf("%s turn\n\n", game.current_Player==White ? "White": "Black");
        printf("Enter your move (like the form A2A4)\n");
        fgets(input, 20, stdin);
        printf("\n");

        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "undo")==0){
            undo_move(&game);
            continue;
        }

        
        else if(strcmp(input, "redo")==0){
            redo_move(&game);
            continue;
        }

        else if (strncmp(input, "save", 4) == 0) {
            char filename[50];

            if (sscanf(input, "save %49s", filename) == 1) {
                save_game(&game, filename);
            } else {
                printf("Usage: save <filename>\n");
            }
            continue;
        }
        else if (strncmp(input, "load", 4) == 0) {
            char filename[50];

            if (sscanf(input, "load %49s", filename) == 1) {
                if (load_game(&game, filename)) {
                    printf("Game loaded successfully from %s\n", filename);
                } else {
                    printf("Failed to load game from %s\n", filename);
                }
            } else {
                printf("Usage: load <filename>\n");
            }
            continue;
        }
        else if(strcmp(input, "exit") == 0){
            on_going = false;
            continue;
        }

        read_move(&from_row, &from_column, &to_row, &to_column, input);
        
    if(in_promotion(&game, to_row, to_column, from_row, from_column)){
        printf("Your Pawn will be promoted!!\n");
        printf("Please! Choose between (Q,R,N,B)\n");
        scanf(" %c", &p);
        getchar();
    
    switch(p){
        case 'Q':
        case 'q':
            promotion = Queen;
             break;
        case 'R':
        case 'r':
            promotion = Rook;
             break;
        case 'N':
        case 'n':
            promotion = Knight;
             break;
        case 'B':
        case 'b':
            promotion = Bishop;
            break;
        default: 
            promotion = Queen;
            break;
    }
    }

        if(!move_piece(&game, from_row, from_column, to_row, to_column, promotion)){
            continue;
        }


Color rival = game.current_Player==White ? Black: White;
        if(is_in_check(&game, rival)){
            game.check = true;
            if(is_checkmate(&game,rival)){
                game.checkmate = true;
                printf("Checkmate!! %s wins\n", game.current_Player==White ? "White": "Black");
                break;
            }
            else{
                printf("%s is on Check\n",  game.current_Player==White ? "Black": "White");
            }

        }
    
        if(is_stalemate(&game, rival)){
            printf("Stalemate \n");
            game.stalemate = true;
            break;
        } 

        switch_player(&game);
    }

    display_board(&game);
    piece_taken(&game);
    if(!on_going){
        return 0;
    }
printf("**********************************************************\n");
    if(game.checkmate || game.stalemate){
        printf("               GAME OVER    \n");
    }
printf("**********************************************************");
getchar();
 
}
    

