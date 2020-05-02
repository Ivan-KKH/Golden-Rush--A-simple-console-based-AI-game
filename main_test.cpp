#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Difficulty.h"
#include "Username.h"
#include "GUI.h"
#include "Display_Gameboard.h"

using namespace std;

struct Player{
  int x, y;
  int score;
  string username;
};

Player p1;

int main(){

  string input_difficulty;
  string username;
  bool select_difficulty = true;

  cout << "Please input username: ";
  getline(cin, username);
  p1.username = username;

  while (select_difficulty){
    cout << "Select difficulty: easy / hard" << endl;
    cin >> input_difficulty;
    if (input_difficulty == "easy"){
      cout << "easy mode selected" << endl;
      Easy_mode();
      break;
    }
    else if  (input_difficulty == "hard"){
      cout << "hard mode selected" << endl;
      Hard_mode();
      break;
    }
    else{
      cout << "invalid input, please select again." << endl;
    }
  }
  // cout << Display_Username(username) << endl;

  // Display_Gameboard(board, board_size);
  // Clear_Screen();
  // Gameboard(username);
  // Main_Menu();
  return 0;
}
