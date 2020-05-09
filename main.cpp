
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Input.h"
#include "Process.h"
#include "Output.h"
#include "Leaderboard.h"


using namespace std;

int main() {
  Display_Gamerule();
  cout << endl;
  int board_size = 0,number_of_player;
  string difficulty,nop,username = "";

  nop_username_difficulty(nop, username, difficulty, number_of_player);

  Clear_Screen();

  boardsize(board_size);

  cout << "\x1b[30;107m";

  Clear_Screen();

  char** board = new char*[board_size+2];    //to create the board array
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];

  cin.get();

  srand(time(NULL));     //to randomize the number of resources on the board

  while (p1.win < 2&&p2.win <2) {
    int p1_round_score = 0,p2_round_score = 0;

    int number_of_resources = (0.2*board_size * board_size + 1);
    number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;

    coord* resource = new coord[number_of_resources]; //to allocate the resources onto the gameboard

    allocate_resources(resource, number_of_resources, board_size);

    Create_Gameboard(board, board_size);

    assign_resources(number_of_resources, resource, board);

    int* points = new int [board_size * board_size];

    allocate_player(board_size,board, number_of_resources , resource, p1, p2, points);

    Clear_Screen();

    process(resource, number_of_resources, p1, p2, board, board_size, number_of_player, difficulty, &p1_round_score,&p2_round_score);

    Display_Gameboard(board,board_size,p1_round_score,p2_round_score,p1.username,p2.username);

    cout << endl << "please press <enter> to continue" << endl;

    cin.clear();
    cin.ignore(255,'\n');
    cin.get();
    Clear_Screen();

    Show_round_winner(p1_round_score,p2_round_score,p1,p2);

    cout << endl << "please press <enter> to continue" << endl;
    cin.get();
    Clear_Screen();
    delete [] resource;
    delete [] points;
}
  if (p1.score > p2.score)
    cout << p1.username << " wins the game!" << endl;
  else if (p2.score > p1.score)
    cout << p2.username << " wins the game!" << endl;
  else
    cout << "the game is a draw!" << endl;
  cout << "Do you want to check the Leaderboard?(y/n)" << endl;
  char check;
  check = cin.get();
  if (check == 'y')
    Print_leaderboard(p1, board_size);
  cout << "thank you for playing! Have a nice day : )" << endl;
  delete [] board;
  return 0;
}
