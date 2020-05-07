#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int main()
{
  int board_size = 10;
  double ** points = new  double* [board_size];
  for (int i = 0; i < 3;i++)
    points[i] = new double[3];
  for (int i = 0;i < 3; i++)
    for (int j = 0; j <3;j++) {
      points[j][i] = i + j;
      cout << points[j][i] << " ";
    }
    cout << endl;
}

for (int i = 0; i < board_size ; i++) {
  for (int j = 0; j < board_size ; j++) {
    if (board[j + 1][i + 1] == ' '){
      point = 0;
      for (int k = 0; k < number_of_resources; k++) {
        if (resource[k].type != '\0') {
          manhatten_distance = abs(resource[k].x -i) + abs(resource[k].y - j);
          point = point + convert_score(resource[k].type)/manhatten_distance;
        }
      }
      points[j][i] = point;
    }
  }
}
for (int i = 0; i < board_size ; i++) {
  for (int j = 0; j < board_size ; j++) {
    cout << points[j][i] << " ";
  }
  cout << endl;
}
cout << "Hi" << endl;
