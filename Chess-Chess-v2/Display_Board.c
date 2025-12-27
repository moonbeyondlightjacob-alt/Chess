#include <stdio.h>
#include <stdbool.h>
#include "header.h"

void display_board(const Game_state  *game){
    char display[10][10]={{' ','A','B','C','D','E','F','G','H',' '},
                        {'8',' ',' ',' ',' ',' ',' ',' ',' ','8'},
                        {'7',' ',' ',' ',' ',' ',' ',' ',' ','7'},
                        {'6',' ',' ',' ',' ',' ',' ',' ',' ','6'},
                        {'5',' ',' ',' ',' ',' ',' ',' ',' ','5'},
                        {'4',' ',' ',' ',' ',' ',' ',' ',' ','4'},
                        {'3',' ',' ',' ',' ',' ',' ',' ',' ','3'},
                        {'2',' ',' ',' ',' ',' ',' ',' ',' ','2'},
                        {'1',' ',' ',' ',' ',' ',' ',' ',' ','1'},
                        {' ','A','B','C','D','E','F','G','H',' '} 
                     };

                     for(int i=0; i<8; ++i){
                        for(int j=0; j<8; j++){
                            piece Piece = game -> board[i][j];
                            if(Piece.type !=Empty){
                                display[i+1][j+1]= piece_to_char(Piece);

                            }
                               else{
                                display[i+1][j+1] = ( (i+j)%2==0 ) ? '-' : '.';
                            }
                        }

                     }
if(game->current_Player==White){
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; j++){
        printf("%c ", display[i][j]);
        if((i==0 && j==9) || (i==8 && j==9)){
            printf("\n");
        }
        }
    printf("\n");
    }

    printf("\n\n");
}
else{
      for(int i=0; i<10; ++i){
        for(int j=0; j<10; j++){
            printf("%c ", display[9-i][9-j]);
            if((i==0 && j==9) || (i==8 && j==9)){
                printf("\n");
            }
        }
    printf("\n");
    }

    printf("\n\n");

}
}




