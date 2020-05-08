
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

#define PLAYER_1 "\xe2\x98\xba"
#define PLAYER_2 "\xe2\x98\xbb"
#define DIAMOND_1 "\xe2\x99\xa6"
#define GOLD "\xE2\x9B\x83"


int print_symbol() {
    printf("\x1b[96m\xe2\x99\xa6\n");
    printf("\x1b[93m\xE2\x9B\x83\n");
    printf("\x1b[37m\xE2\x9B\x83\n");
    printf("\x1b[33m\xE2\x9B\x83\n");
    printf("\x1b[0m");
    return 0;
}

int main() {
  Display_Gamerule();
  cout << endl;
  int board_size = 0,number_of_player;
  string difficulty,nop,username = "";

  nop_username_difficulty(nop, username, difficulty, number_of_player);

  Clear_Screen();

  boardsize(board_size);

  Clear_Screen();

  char** board = new char*[board_size+2];    //to create the board array
  for (int i = 0;i < board_size + 2;i++)
    board[i] = new char[board_size+2];

  srand(time(NULL));     //to randomize the number of resources on the board

  coord* resource;
  int* points;

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

    process(resource, number_of_resources, p1, p2, board, board_size, number_of_player, difficulty, &p1_round_score,&p2_round_score);

    Show_round_winner(p1_round_score,p2_round_score,p1,p2);

    cout << "please press <enter> to continue" << endl;
    cin.clear();
    cin.ignore(255,'\n');
    cin.get();


    Clear_Screen();
}
  if (p1.score > p2.score)
    cout << p1.username << " wins the game!" << endl;
  else if (p2.score > p1.score)
    cout << p2.username << " wins the game!" << endl;
  else
    cout << "the game is a draw!" << endl;
  cout << "please press <enter> to continue" << endl;
  // cin.clear();
  // cin.ignore(255,'\n');
  // cin.get();
  Print_leaderboard(p1, board_size);
  delete [] resource;
  delete [] points;
  delete [] board;
  return 0;
}
