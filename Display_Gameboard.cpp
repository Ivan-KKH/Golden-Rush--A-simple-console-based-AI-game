#include <iostream>
#include "Display_Gameboard.h"
using namespace std;

void Display_Gameboard(char board[][],int board_size){
  for (int i = 0; i < board_size + 2;i++) {
    for (int j = 0;j < board_size + 2;j++) {
      cout << "[" << board[i][j] << "]";
    }
    cout << endl;
  }
}
