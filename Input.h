#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include <string>

#endif

using namespace std;

// create a player structure
struct player {
  int x,y,score,win = 0;
  string username;
};
player p1,p2;

// create a coordinate structure for gameboard
struct coord {
  int x,y;
  char type;
};

// get number of players, username, difficulty
void nop_username_difficulty(string &nop, string &username, string &difficulty, int &number_of_player){

  bool select = true;
  while (select){
    cout << "How many player?(1/2)" << endl;
    getline(cin,nop);
    if (nop == "1") {
      number_of_player = 1;
      while (select){
        cout << "You are player 1" << endl;
        cout << "Please select the difficulty: easy / hard" << endl;
        cin >> difficulty;
        if (difficulty == "easy") {
          cout << "easy mode selected" << endl;
          select = false;
        }
        else if  (difficulty == "hard") {
          cout << "hard mode selected" << endl;
          select = false;
        }
        else
          cout << "invalid input, please select again." << endl;
        cout << "Please input username:";
        while (username == "")
          getline(cin, username);
      }
      p1.username = username;
      p2.username = "bot";
    }
    else if (nop == "2") {
      number_of_player = 2;
      cout << "Please input username of player 1: ";
      getline(cin, username);
      p1.username = username;
      cout << "Please input username of player 2: ";
      getline(cin, username);
      p2.username = username;
      select = false;
    }
    else
      cout << "Invalid input, please enter 1/2 again" << endl;
    }
}


// create boardsize from user input (input)
void boardsize(int &board_size){
  while (board_size < 5 ||board_size > 25) {
    cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
    cin >> board_size;
    if (board_size < 5||board_size > 25)
      cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
  }
}
