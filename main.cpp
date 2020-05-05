#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Create_Gameboard.h"
#include "Display_Gameboard.h"
#include "GUI.h"

using namespace std;

struct player { //create a player structure
  int x,y,score;
  string username;
};
player p1,p2;

struct coord {
  int x,y;
  char type;
};

bool Check_endgame(coord * resource,int number_of_resources){
  for (int i = 0; i < number_of_resources;i++)
    if (resource[i].type != '\0')
      return false;
  return true;
}

bool Movement_valid(char player_movement, player &p1,player &p2, int who_move, int board_size, char** board){   //cannot overlap with another player, cannot step out of boundary, and update the board if valid
  int new_p1_x, new_p1_y, new_p2_x, new_p2_y;
  if ( who_move == 1){
    if (player_movement == 'w') {
      new_p1_y = p1.y-1;
      new_p1_x = p1.x;
    }
    if (player_movement == 's') {
      new_p1_y = p1.y+1;
      new_p1_x = p1.x;
    }
    if (player_movement == 'a') {
      new_p1_x = p1.x-1;
      new_p1_y = p1.y;
    }
    if (player_movement == 'd') {
      new_p1_x = p1.x+1;
      new_p1_y = p1.y;
    }
    if (new_p1_x < 0 || new_p1_x >= board_size || new_p1_y < 0 || new_p1_y >= board_size||(new_p1_x == p2.x&&new_p1_y == p2.y))
      return false;
    else{
      board[p1.y+1][p1.x+1] = '\0';
      board[new_p1_y+1][new_p1_x+1] = '1';
      p1.y = new_p1_y;
      p1.x = new_p1_x;
    }
    return true;
  }
    if ( who_move == 2){
      if (player_movement == 'w') {
        new_p2_y = p2.y-1;
        new_p2_x = p2.x;
      }
      if (player_movement == 's') {
        new_p2_y = p2.y+1;
        new_p2_x = p2.x;
      }
      if (player_movement == 'a') {
        new_p2_x = p2.x-1;
        new_p2_y = p2.y;
      }
      if (player_movement == 'd') {
        new_p2_x = p2.x+1;
        new_p2_y = p2.y;
      }
    if (new_p2_x < 0 || new_p2_x >= board_size || new_p2_y < 0 || new_p2_y >= board_size||(new_p2_x == p1.x&&new_p2_y == p1.y))
      return false;
      else{
        board[p2.y + 1][p2.x + 1] = '\0';
        board[new_p1_y +1][new_p1_x +1] = '2';
        p2.y = new_p2_y;
        p2.x = new_p2_x;
      }
      return true;
  }
}



void Display_Gamerule() {          //to display the gamerule
  string s;
  ifstream fin;
  fin.open("gamerule.txt");
  if (fin.fail()) {
    cout << "failed to open gamerule" << endl;
  }
  while (getline(fin,s))
    cout << s << endl;
  fin.close();
}                                                                       //end

char easy_mode(){ // to implement the move of computer with easy mode
  int decision = rand() % 4;
  if (decision == 0)
    return 'l';
  else if (decision == 1)
    return 'r';
  else if (decision == 2)
    return 'u';
  else if (decision == 3)
    return 'd';
}

char hard_mode(){
  return '0';
}


int main() {
  int board_size = 0,difficulty;
  // string username_1,username_2;

  string input_difficulty;
  bool select_difficulty = true;
  string username;
  cout << "Please input username: "; // get username
  getline(cin, username);
  p1.username = username;

  while (select_difficulty){
    cout << "Select difficulty: easy / hard" << endl;
    cin >> input_difficulty;
    if (input_difficulty == "easy"){
      cout << "easy mode selected" << endl;
      // easy_mode();
      break;
    }
    else if  (input_difficulty == "hard"){
      cout << "hard mode selected" << endl;
      // hard_mode();
      break;
    }
    else{
      cout << "invalid input, please select again." << endl;
    }
  }

  Clear_Screen();

  while (board_size < 5 ||board_size > 25) { //To repeatedly request the size of gameboard until it reaches the acceptable range(5-25)
    cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
    cin >> board_size;
    if (board_size < 5||board_size > 25)
      cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
  }

  Clear_Screen();

  char** board = new char*[board_size+2];    //to create the board array
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];

  srand(time(NULL));       //to randomize the number of resources on the board
  int number_of_resources = (0.2*board_size * board_size + 1);
  number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;

  coord* resource = new coord[number_of_resources];
  int type_generator = rand() % 10;
  for (int i = 0; i < number_of_resources;i++) {
    int found = true;
    while (found == true) {
      resource[i].x = rand() % board_size;
      resource[i].y = rand() % board_size;
      type_generator = rand() % 10;
      if (type_generator == 0)
        resource[i].type = 'D';
      else if (type_generator <= 2)
        resource[i].type = 'G';
      else if (type_generator <= 5)
        resource[i].type = 'S';
      else
        resource[i].type = 'B';
      found = false;
      for (int j = 0;j <= i - 1;j++)
        if (resource[i].x == resource[j].x && resource[i].y == resource[j].y)
          found = true;
        }
      }
  Create_Gameboard(board, board_size);
  cout << number_of_resources << endl;
  for (int i = 0;i < number_of_resources;i++) {
    cout << resource[i].x << " " << resource[i].y << " " << resource[i].type << endl;
    board[resource[i].y + 1][resource[i].x + 1] = resource[i].type;
  }

  int found = true;
  while (found == true) {
    found = false;
    p1.x = rand() % board_size;
    p1.y = rand() % board_size;
    p2.x = rand() % board_size;
    p2.y = rand() % board_size;
    if (p1.x == p2.x && p1.y == p2.y)
      found = true;
    else {
      for (int i = 0; i < number_of_resources; i++) {
        if (p1.x == resource[i].x && p1.y == resource[i].y)
          found = true;
        if (p2.x == resource[i].x && p2.y == resource[i].y)
            found = true;
      }
    }
  }
  board[p1.y + 1][p1.x + 1] = '1';
  board[p2.y + 1][p2.x + 1] = '2';
  char player_movement;
  while (Check_endgame(resource,number_of_resources) == false) {
    Display_Gameboard(board, board_size);
    cout << "please enter your movement (w/a/s/d)" << endl;
    cin >> player_movement;
    while (Movement_valid(player_movement,p1,p2,1,board_size,board) == false) {
      cout << "invalid movement, please choose again!" << endl;
      cin >> player_movement;
    }
    for (int i=0; i < number_of_resources; i++){
      if (p1.x == resource[i].x && p1.y == resource[i].y) {
        resource[i].x = -1;
        resource[i].y = -1;
        resource[i].type = '\0';
      }
      }

    }
    Display_Gameboard(board,board_size);
  system("PAUSE");
  delete [] board;
  delete [] resource;
  return 0;
}
