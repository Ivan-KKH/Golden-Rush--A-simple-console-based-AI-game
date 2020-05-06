#ifndef DISPLAY_GAMEBOARD_H_
#define DISPLAY_GAMEBOARD_H_

#include <iostream>
#include <iomanip>

#endif

using namespace std;

void Display_Gameboard(char** board,int board_size, int p1_score,int p2_score, string p1_name,string p2_name){ // to display the whole gameboard whenever needed
  cout << left << setw(10) <<p1_name<< right << setw(20)  << p2_name << endl;
  cout << left << setw(10) << p1_score << right << setw(20) << p2_score << endl;
  for (int i = 0; i < board_size + 2;i++) {
    for (int j = 0;j < board_size + 2;j++) {
      cout << "[" << board[i][j] << "]";
    }
    cout << endl;
  }
}
