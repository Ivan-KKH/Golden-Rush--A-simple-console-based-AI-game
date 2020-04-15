#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int board_size = 5;
  srand(time(NULL));       //to randomize the number of resources on the board
  int number_of_resources = (0.2*board_size * board_size + 1);
  number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;
  struct coordinate {
    int x,y;
  };

  coordinate resource[number_of_resources];
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
    }
  }
}
