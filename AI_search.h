#ifndef AI_SEARCH_H_
#define AI_SEARCH_H_

#include <ctime>
#include <stdio.h>
#include <stdlib>

#endif

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

char easy_mode(){ // to implement the move of computer with easy mode
  srand(time(NULL));
  int decision = rand % 4;
  if (decision == 0)
    return 'l';
  else if (decision == 1)
    return 'r';
  else if (decision == 2)
    return 'u';
  else if (decision == 3)
    return 'd';
}

char hard_mode(){ // to implement the move of computer with hard mode

}
