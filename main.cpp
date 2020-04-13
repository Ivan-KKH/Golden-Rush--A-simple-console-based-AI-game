#include <iostream>
#include <stdlib.h>
#include "Create_Gameboard.h"
#include "Display_Gameboard.h"
#include "Display_Gamerule.h"
using namespace std;


int main() {
  int board_size = 0,difficulty;
  string username_1,username_2;
  while (board_size < 5 ||board_size > 25) { //To repeatedly request the size of gameboard until it reaches the acceptable range(5-25)
    cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
    cin >> board_size;
    if (board_size < 5||board_size > 25)
      cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
  }
  cin >> board_size;
  char** board = new char*[board_size+2];
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];
  Create_Gameboard(board, board_size);
  cin >> username_1;
  system("CLS");
  return 0;
}
