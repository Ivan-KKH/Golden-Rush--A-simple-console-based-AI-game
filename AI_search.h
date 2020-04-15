#include <stdio.h>

#define PLAYER_1 "\xe2\x98\xba"
#define PLAYER_2 "\xe2\x98\xbb"
#define DIAMOND_1 "\xe2\x99\xa6"
#define GOLD "\xE2\x9B\x83"

int print_symbol() {
    printf("\x1b[96m\xe2\x99\xa6\n");
    printf("\x1b[93m\xE2\x9B\x83\n");
    printf("\x1b[37m\xE2\x9B\x83\n");
    printf("\x1b[33m\xE2\x9B\x83\n");
    printf("\x1b[0m");
}

void easy_mode(){ // to implement the move of computer with easy mode

}

void Hard_mode(){ // to implement the move of computer with hard mode

}
