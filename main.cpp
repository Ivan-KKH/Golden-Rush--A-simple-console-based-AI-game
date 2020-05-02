#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Create_Gameboard.h"
#include "Display_Gameboard.h"

using namespace std;

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

int main() {
  int board_size = 0,difficulty;
  string username_1,username_2;

  while (board_size < 5 ||board_size > 25) { //To repeatedly request the size of gameboard until it reaches the acceptable range(5-25)
    cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
    cin >> board_size;
    if (board_size < 5||board_size > 25)
      cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
  }                                                                //end

  char** board = new char*[board_size+2];    //to create the board array
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];

  srand(time(NULL));       //to randomize the number of resources on the board
  int number_of_resources = (0.2*board_size * board_size + 1);
  number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;

  struct coord {
    int x,y;
    char type;
  };
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
  struct player { //create a player structure
    int x,y,score;
  };
  player p1,p2;
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
  board[p1.y + 1][p2.x + 1] = '1';
  board[p2.y + 1][p2.x + 1] = '2';
  Display_Gameboard(board, board_size);
  system("PAUSE");
  Display_Gamerule();
  delete [] board;
  return 0;
}
