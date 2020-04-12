#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Player_Movement_Control.h"
using namespace std;


int main() {
  int board_size, difficulty;
  string username_1,username_2,s;
  ifstream fin;
  fin.open("gamerule.txt");
  if (fin.fail()) {
    cout << "failed to open gamerule" << endl;

  }
  while (getline(fin,s)) {
    cout << s << endl;
  }
  cin >> username_1;
  system("CLS");
  Player_Movement_Control();
  return 0;
}
