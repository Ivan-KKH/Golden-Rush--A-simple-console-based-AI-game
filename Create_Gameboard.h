#ifndef CREATE_GAMEBOARD_H_
#define CREATE_GAMEBOARD_H_

#include <iostream>

#endif

using namespace std;

void Create_Gameboard(char** board, int board_size){ //to create a gameboard of size n x n
  for (int i = 0; i < board_size + 2;i++) {
    for (int j = 0;j < board_size + 2;j++) {
      if (i == 0||i == board_size + 1)
          board[i][j] = 'x';
      else if (j == 0||j == board_size +1)
          board[i][j] = 'x';
      else
        board[i][j] = ' ';
    }
  }
}
