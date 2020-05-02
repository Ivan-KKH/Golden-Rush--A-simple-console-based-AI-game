#include <iostream>
#include <stdlib.h>
#include <cstdlib>
<<<<<<< HEAD

using namespace std;

struct Player(){
  int x, y, score;
  string username;

}

int main(){
  // system("CLS");
  string u;
  cin >> u;
  if (system("CLS")) system("clear");
=======
#include <ctime>
#include <string>
#include <fstream>
#include "Create_Gameboard.h"
#include "Display_Gameboard.h"

using namespace std;

void Display_Gamerule() {                  //to display the gamerule
  string s;
  ifstream fin;
  fin.open("gamerule.txt");
  if (fin.fail()) {
    cout << "failed to open gamerule" << endl;
  }
  while (getline(fin,s))
    cout << s << endl;
  fin.close();
}                                           //end

int main() {
  int board_size = 0,difficulty;
  string username_1,username_2;

  while (board_size < 5 ||board_size > 25) { //To repeatedly request the size of gameboard until it reaches the acceptable range(5-25)
    cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
    cin >> board_size;
    if (board_size < 5||board_size > 25)
      cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
  }                                           //end

  char** board = new char*[board_size+2];    //to create the board array
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];    // end

  srand(time(NULL));       //to randomize the number of resources on the board
  int number_of_resources = (0.2*board_size * board_size + 1);
  number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;                                                      //End

  struct coord {
    int x,y,type;
  };
  coord resource[number_of_resources];
  resource[0].x = rand() % (board_size + 1); //to allocate the resources onto the map
  resource[0].y = rand() % (board_size + 1);
  for (int i = 1; i < number_of_resources;i++) {
    int found = true;
    while (found == true) {
      resource[i].x = rand() % (board_size + 1);
      resource[i].y = rand() % (board_size + 1);
      found = false;
      for (int j = 0;j <= i - 1;j++)
        if (resource[i].x == resource[j].x && resource[i].y == resource[j].y)
          found = true;
    }   // resources
  }                                                      //end

  Create_Gameboard(board, board_size);
  Display_Gameboard(board, board_size);
  system("PAUSE");
  Display_Gamerule();
  delete [] board;
>>>>>>> a99dffc8634520cc0e0f05cfcb4c8716f0863968
  return 0;
}
