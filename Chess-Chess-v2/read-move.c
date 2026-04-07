#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void read_move(int* from_row, int* from_column, int* to_row, int* to_column, char input[]){
    *from_row=-1;
    *from_column=-1;
    *to_row=-1;
    *to_column=-1;
    
if(strlen(input)>5) return;
    

    switch(input[0]){
        case 'A': case 'a':
            *from_column = 0;
            break;
        case 'B': case'b':
            *from_column = 1;
            break;
        case 'C':case 'c':
            *from_column = 2;
            break;
        case 'D': case 'd':
            *from_column = 3;
            break;
        case 'E':case 'e':
            *from_column = 4;
            break;
        case 'F': case 'f':
            *from_column = 5;
            break;
        case 'G': case 'g':
            *from_column = 6;
            break;
        case 'H': case 'h':
            *from_column = 7;
            break;        
    }

        switch(input[1]){
        case '1':
            *from_row = 7;
            break;
        case '2':
            *from_row = 6;
            break;
        case '3':
            *from_row = 5;
            break;
        case '4':
            *from_row = 4;
            break;
        case '5':
            *from_row = 3;
            break;
        case '6':
            *from_row = 2;
            break;
        case '7':
            *from_row = 1;
            break;
        case '8':
            *from_row = 0;
            break;        
    }

        switch(input[2]){
        case 'A': case 'a':
            *to_column = 0;
            break;
        case 'B': case 'b':
            *to_column = 1;
            break;
        case 'C': case 'c':
            *to_column = 2;
            break;
        case 'D': case 'd':
            *to_column = 3;
            break;
        case 'E': case 'e': 
            *to_column = 4;
            break;
        case 'F': case 'f':
            *to_column = 5;
            break;
        case 'G': case 'g':
            *to_column = 6;
            break;
        case 'H': case 'h':
            *to_column = 7;
            break;        
    }

       switch(input[3]){
        case '1':
            *to_row = 7;
            break;
        case '2':
            *to_row = 6;
            break;
        case '3':
            *to_row = 5;
            break;
        case '4':
            *to_row = 4;
            break;
        case '5':
            *to_row = 3;
            break;
        case '6':
            *to_row = 2;
            break;
        case '7':
            *to_row = 1;
            break;
        case '8':
            *to_row = 0;
            break;        
    }


}