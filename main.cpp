
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>


using namespace std;

void Get_user_button(){
  cout << "Press any button to continue" << endl;
  cin.get();
}

void Clear_Screen(){
  if (system("CLS")){
    system("clear");
  }
}

// create a player structure
struct player {
  int x,y,score;
  string username;
};
player p1,p2;

// create a coordinate structure for gameboard
struct coord {
  int x,y;
  char type;
};


// void nop_username_difficulty(string &nop, string &username, string &difficulty, int &number_of_player){
//
//   bool select = true;
//   while (select){
//     cout << "How many player?(1/2)" << endl;
//     getline(cin,nop);
//     if (nop == "1") {
//       number_of_player = 1;
//       while (select){
//         cout << "You are player 1" << endl;
//         cout << "Please select the difficulty: easy / hard" << endl;
//         cin >> difficulty;
//         if (difficulty == "easy") {
//           cout << "easy mode selected" << endl;
//           select = false;
//         }
//         else if  (difficulty == "hard") {
//           cout << "hard mode selected" << endl;
//           select = false;
//         }
//         else
//           cout << "invalid input, please select again." << endl;
//         cout << "Please input username:";
//         while (username == "")
//           getline(cin, username);
//       }
//       p1.username = username;
//       p2.username = "bot";
//     }
//     else if (nop == "2") {
//       number_of_player = 2;
//       cout << "Please input username of player 1: ";
//       getline(cin, username);
//       p1.username = username;
//       cout << "Please input username of player 2: ";
//       getline(cin, username);
//       p2.username = username;
//       select = false;
//     }
//     else
//       cout << "Invalid input, please enter 1/2 again" << endl;
//     }
// }
//
// // create boardsize
// void boardsize(int &board_size){
//   while (board_size < 5 ||board_size > 25) {
//     cout << "Please enter a number n(5-25) to determine the size n x n board" << endl;
//     cin >> board_size;
//     if (board_size < 5||board_size > 25)
//       cout << "The range for the board size is 5x5 to 25x25, please enter the size again" << endl;
//   }
// }
//
// //to create a gameboard of size n x n
// void Create_Gameboard(char** board, int board_size){
//   for (int i = 0; i < board_size + 2;i++) {
//     for (int j = 0;j < board_size + 2;j++) {
//       if (i == 0||i == board_size + 1)
//           board[i][j] = 'x';
//       else if (j == 0||j == board_size +1)
//           board[i][j] = 'x';
//       else
//         board[i][j] = ' ';
//     }
//   }
// }
//
//  // to display the whole gameboard whenever needed
// void Display_Gameboard(char** board,int board_size, int p1_score,int p2_score, string p1_name,string p2_name){
//   cout << left << setw(10) <<p1_name<< right << setw(20)  << p2_name << endl;
//   cout << left << setw(10) << p1_score << right << setw(20) << p2_score << endl;
//   for (int i = 0; i < board_size + 2;i++) {
//     for (int j = 0;j < board_size + 2;j++) {
//       cout << "[" << board[i][j] << "]";
//     }
//     cout << endl;
//   }
// }
//
// //to allocate the coordinates of resources onto the gameboard
// void allocate_resources(coord* resource, int number_of_resources, int board_size){
//   // coord* resource = new coord[number_of_resources];
//   int type_generator = rand() % 10;
//   for (int i = 0; i < number_of_resources;i++) {
//     int found = true;
//     while (found == true) {
//       resource[i].x = rand() % board_size;
//       resource[i].y = rand() % board_size;
//       type_generator = rand() % 10;
//       if (type_generator == 0)
//         resource[i].type = 'D';
//       else if (type_generator <= 2)
//         resource[i].type = 'G';
//       else if (type_generator <= 5)
//         resource[i].type = 'S';
//       else
//         resource[i].type = 'B';
//       found = false;
//       for (int j = 0;j <= i - 1;j++)
//         if (resource[i].x == resource[j].x && resource[i].y == resource[j].y)
//           found = true;
//       }
//     }
// }
//
// // assign resources on the gameboard
// void assign_resources(int number_of_resources, coord *resource, char **board){
//   for (int i = 0;i < number_of_resources;i++) {
//     //cout << resource[i].x << " " << resource[i].y << " " << resource[i].type << endl;
//     board[resource[i].y + 1][resource[i].x + 1] = resource[i].type;
//   }
// }
//
// // check conflict between players and assign_resources
// void check_conflict_player_resources(player &p1, player &p2, coord *resource, int &number_of_resources, int &board_size, char **board){
//   int found = true;
//   while (found == true) {
//     found = false;
//     p1.x = rand() % board_size;
//     p1.y = rand() % board_size;
//     p2.x = rand() % board_size;
//     p2.y = rand() % board_size;
//     if (p1.x == p2.x && p1.y == p2.y)
//       found = true;
//     else {
//       for (int i = 0; i < number_of_resources; i++) {
//         if (p1.x == resource[i].x && p1.y == resource[i].y)
//           found = true;
//         if (p2.x == resource[i].x && p2.y == resource[i].y)
//             found = true;
//       }
//     }
//   }
//   board[p1.y + 1][p1.x + 1] = '1';
//   board[p2.y + 1][p2.x + 1] = '2';
// }
//
// // check if the game ends
// bool Check_endgame(coord *resource,int number_of_resources){
//   for (int i = 0; i < number_of_resources;i++)
//     if (resource[i].type != '\0')
//       return false;
//   return true;
// }
//
// // check if the movement is valid
// bool Movement_valid(char player_movement, player &p1,player &p2, int who_move, int board_size, char** board){
//   int new_p1_x, new_p1_y, new_p2_x, new_p2_y;
//   if ( who_move == 0){
//     if (player_movement == 'w') {
//       new_p1_y = p1.y-1;
//       new_p1_x = p1.x;
//     }
//     if (player_movement == 's') {
//       new_p1_y = p1.y+1;
//       new_p1_x = p1.x;
//     }
//     if (player_movement == 'a') {
//       new_p1_x = p1.x-1;
//       new_p1_y = p1.y;
//     }
//     if (player_movement == 'd') {
//       new_p1_x = p1.x+1;
//       new_p1_y = p1.y;
//     }
//     if (new_p1_x < 0 || new_p1_x >= board_size || new_p1_y < 0 || new_p1_y >= board_size||(new_p1_x == p2.x&&new_p1_y == p2.y))
//       return false;
//     else{
//       board[p1.y+1][p1.x+1] = ' ';
//       board[new_p1_y+1][new_p1_x+1] = '1';
//       p1.y = new_p1_y;
//       p1.x = new_p1_x;
//     }
//     return true;
//   }
//   if ( who_move == 1){
//     if (player_movement == 'w') {
//       new_p2_y = p2.y-1;
//       new_p2_x = p2.x;
//     }
//     if (player_movement == 's') {
//       new_p2_y = p2.y+1;
//       new_p2_x = p2.x;
//     }
//     if (player_movement == 'a') {
//       new_p2_x = p2.x-1;
//       new_p2_y = p2.y;
//     }
//     if (player_movement == 'd') {
//       new_p2_x = p2.x+1;
//       new_p2_y = p2.y;
//     }
//     if (new_p2_x < 0 || new_p2_x >= board_size || new_p2_y < 0 || new_p2_y >= board_size||(new_p2_x == p1.x&&new_p2_y == p1.y))
//       return false;
//     else{
//       board[p2.y + 1][p2.x + 1] = ' ';
//       board[new_p2_y +1][new_p2_x +1] = '2';
//       p2.y = new_p2_y;
//       p2.x = new_p2_x;
//     }
//     return true;
//   }
// }
//
// // determine who go first
// int who_go_first(){
//   int gen = rand() % 2;
//   if (gen == 0) {
//     cout << "player 1 go first" << endl;
//     return 0;
//   }
//   else {
//     cout << "player 2 go first" << endl;
//     return 1;
//   }
// }
//
// // to implement the move of computer with easy mode
// char easy_mode(){
//   int decision = rand() % 4;
//   if (decision == 0)
//     return 'w';
//   else if (decision == 1)
//     return 'a';
//   else if (decision == 2)
//     return 's';
//   else if (decision == 3)
//     return 'd';
// }
//
// int convert_score(char type) {
//   if (type == 'D')
//       return 100;
//   else if (type == 'G')
//       return 50;
//   else if (type == 'S')
//       return 20;
//   else if (type == 'B')
//       return 10;
// }
//
// int target_resource_hard_mode(coord* resource, int number_of_resources, player&p1, player&p2, char** board,int board_size){
//   double manhatten_distance;
//   double point = 0;
//   double* point_arr = new double[number_of_resources];
//   for (int i = 0;i < number_of_resources; i++) {
//     if (resource[i].type != '\0') {
//       manhatten_distance = abs(resource[i].x - p2.x) + abs(resource[i].y - p2.y);
//       point += convert_score(resource[i].type)/manhatten_distance;
//       for (int j = 0;j < number_of_resources; j++) {
//         if (j != i && resource[j].type != '\0') {
//             manhatten_distance = abs(resource[j].x - resource[i].x) + abs(resource[j].y - resource[i].y);
//             point += convert_score(resource[j].type)/manhatten_distance;
//         }
//       }
//     }
//     else point_arr[i] = -1;
//     point_arr[i] = point;
//     point = 0;
//   }
//   double max_point = point_arr[0];
//   int max_point_index = 0;
//   for (int i = 0;i < number_of_resources; i++) {
//     if (point_arr[i] > max_point) {
//       max_point = point_arr[i];
//       max_point_index = i;
//     }
//   }
//   delete [] point_arr;
//   return max_point_index;
// }
//
// bool check_step_valid(char player_movement, player &moving_one,player &another_player, int board_size, char** board) {
//   int new_moving_one_x, new_moving_one_y;
//   if (player_movement == 'w') {
//     new_moving_one_y = moving_one.y-1;
//     new_moving_one_x = moving_one.x;
//   }
//   if (player_movement == 's') {
//     new_moving_one_y = moving_one.y+1;
//     new_moving_one_x = moving_one.x;
//   }
//   if (player_movement == 'a') {
//     new_moving_one_x = moving_one.x-1;
//     new_moving_one_y = moving_one.y;
//   }
//   if (player_movement == 'd') {
//     new_moving_one_x = moving_one.x+1;
//     new_moving_one_y = moving_one.y;
//   }
//   if (new_moving_one_x < 0 || new_moving_one_x >= board_size || new_moving_one_y < 0 || new_moving_one_y >= board_size||(new_moving_one_x == another_player.x&&new_moving_one_y == another_player.y))
//     return false;
//   return true;
// }
//
// char hard_mode_move(int target_resource, coord* resource, player&p1, player&p2,char**board,int board_size) {
//   char vertical_move = '\0', horizontal_move = '\0';
//   if (resource[target_resource].x < p2.x)
//      horizontal_move = 'a';
//   else if (resource[target_resource].x > p2.x)
//      horizontal_move = 'd';
//   if (resource[target_resource].y < p2.y)
//     vertical_move = 'w';
//   else if (resource[target_resource].y > p2.y)
//     vertical_move = 's';
//   if (vertical_move != '\0' && horizontal_move != '\0') {
//     srand(time(NULL));
//     int random = rand() % 2;
//     if (random == 0)
//       return horizontal_move;
//     else return vertical_move;
//   }
//   else if (vertical_move == '\0') {
//     if (check_step_valid(horizontal_move,p2,p1,board_size,board))
//       return horizontal_move;
//     else
//       return 'w';
//   }
//   else if (horizontal_move == '\0') {
//     if (check_step_valid(vertical_move,p2,p1,board_size,board))
//       return vertical_move;
//     else
//       return 'd';
//   }
// }
//
// void process(coord *resource, int number_of_resources, player &p1, player &p2, char **board, int board_size, int number_of_player, string difficulty){
//   char player_movement;
//   int turn = who_go_first(),target_resource;
//   cout << "Initial gameboard" << endl << endl;
//   Display_Gameboard(board,board_size,p1.score,p2.score,p1.username,p2.username);
//   cout << endl;
//   cout << "Press any key to continue" << endl;
//   getch();
//   Clear_Screen;
//   target_resource = target_resource_hard_mode(resource,number_of_resources,p1,p2,board,board_size);
//   cout << "current target resource = " << resource[target_resource].x << " "<<  resource[target_resource].y << " ";
//   while (Check_endgame(resource,number_of_resources) == false) {
//     cout << "player " << turn + 1 << " turn" << endl << endl;
//     if (number_of_player == 1 && turn == 1) {}
//     else
//       Display_Gameboard(board,board_size,p1.score,p2.score,p1.username,p2.username);
//     if (turn == 0) {
//       cout << "please enter your movement (w/a/s/d)" << endl;
//       cin >> player_movement;
//     }
//     else if (turn == 1 && number_of_player == 1) {
//       if (difficulty == "easy")
//         player_movement = easy_mode();
//       if (difficulty == "hard")
//         player_movement = hard_mode_move(target_resource,resource,p1,p2,board,board_size);
//       cout << "player " << turn + 1 << " turn " << endl << endl;
//     }
//     else {
//       cout << "please enter your movement (w/a/s/d)" << endl;
//       cin >> player_movement;
//     }
//     while (Movement_valid(player_movement,p1,p2,turn,board_size,board) == false) {
//       if (turn == 0) {
//         cin >> player_movement;
//         cout << "invalid movement, please choose again!" << endl;
//       }
//       else if (turn == 1 && number_of_player == 1) {
//         if (difficulty == "easy") {
//           player_movement = easy_mode();
//         }
//         if (difficulty == "hard")
//           player_movement = hard_mode_move(target_resource,resource,p1,p2,board,board_size);
//       }
//       else {
//         cout << "please enter your movement (w/a/s/d)" << endl;
//         cin >> player_movement;
//       }
//     }
//     for (int i=0; i < number_of_resources; i++){
//       if (p1.x == resource[i].x && p1.y == resource[i].y) {
//         p1.score += convert_score(resource[i].type);
//         resource[i].x = - 1;
//         resource[i].y = - 1;
//         resource[i].type = '\0';
//       }
//       if (p2.x == resource[i].x && p2.y == resource[i].y) {
//         p2.score += convert_score(resource[i].type);
//         resource[i].x = - 1;
//         resource[i].y = - 1;
//         resource[i].type = '\0';
//       }
//     }
//     target_resource = target_resource_hard_mode(resource,number_of_resources,p1,p2,board,board_size);
//     turn = abs(turn - 1); // need cstdlib
//     Clear_Screen();
//     cout << "current target resource = " << resource[target_resource].x << " "<<  resource[target_resource].y << " " << resource[target_resource].type << endl;
//   }
// }
//
// // to display the gamerule
// void Display_Gamerule() {
//   string s;
//   ifstream fin;
//   fin.open("gamerule.txt");
//   if (fin.fail()) {
//     cout << "failed to open gamerule" << endl;
//   }
//   while (getline(fin,s))
//     cout << s << endl;
//   fin.close();
// }

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

  srand(time(NULL));       //to randomize the number of resources on the board
  int number_of_resources = (0.2*board_size * board_size + 1);
  number_of_resources = rand() % number_of_resources + board_size * board_size * 0.2;

  coord* resource = new coord[number_of_resources]; //to allocate the resources onto the gameboard

  allocate_resources(resource, number_of_resources, board_size);

  Create_Gameboard(board, board_size);

  assign_resources(number_of_resources, resource, board);

  check_conflict_player_resources(p1, p2, resource, number_of_resources, board_size, board);

  process(resource, number_of_resources, p1, p2, board, board_size, number_of_player, difficulty);

  Display_Gameboard(board,board_size,p1.score,p2.score,p1.username,p2.username);

  cout << p1.score << " " << p2.score << endl;

  // system("PAUSE");
  cout << "press any key to continue" << endl;
  cin.get();

  delete [] board;
  delete [] resource;

  return 0;
}
