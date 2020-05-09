#ifndef PROCESS_H_
#define PROCESS_H_

#include <iostream>

#endif

using namespace std;

void Clear_Screen(){
    system("clear");
}


//to create a gameboard of size n x n (process)
void Create_Gameboard(char** board, int board_size){
  for (int i = 0; i < board_size + 2;i++) {
    for (int j = 0;j < board_size + 2;j++) {
      if (i == 0||i == board_size + 1)
          board[i][j] = 'x';
      else if (j == 0||j == board_size +1)
          board[i][j] = 'x';
      else
        board[i][j] = ' ';
    }
  }
}

// to display the whole gameboard whenever needed (process)
void Display_Gameboard(char** board,int board_size, int p1_score,int p2_score, string p1_name,string p2_name){
  cout << left << setw(10) <<p1_name<< right << setw(20)  << p2_name << endl;
  cout << left << setw(10) << p1_score << right << setw(20) << p2_score << endl;
  for (int i = 0; i < board_size + 2;i++) {
    for (int j = 0;j < board_size + 2;j++) {
      if (board[i][j] == 'D')
        cout << "[" << "\x1b[96;107m\xe2\x99\xa6" << "\x1b[30;107m]";
      else if (board[i][j] == 'G')
        cout  << "[" << "\x1b[93;107m\xe2\x99\x95" << "\x1b[30;107m]";
      else if (board[i][j] == 'S')
        cout  << "[" << "\x1b[37;107m\xe2\x99\x95" << "\x1b[30;107m]";
      else if (board[i][j] == 'B')
        cout  << "[" << "\x1b[31;107m\xe2\x99\x95" << "\x1b[30;107m]";
      else if (board[i][j] == '1')
        cout  << "[" << "\xe2\x98\xba" << "\x1b[30;107m]";
      else if (board[i][j] == '2')
        cout  << "[" << "\xe2\x98\xbb" << "\x1b[30;107m]";
      else
        cout  << "[" << board[i][j] << "\x1b[30;107m]";
    }
    cout << endl;
  }
}

// determine who go first (process)
int who_go_first(string p1_name,string p2_name){
  int gen = rand() % 2;
  if (gen == 0) {
    cout << p1_name << " goes first" << endl;
    return 0;
  }
  else {
    cout << p2_name << " goes first" << endl;
    return 1;
  }
}

// to implement the move of computer with easy mode (process)
char easy_mode(){
  int decision = rand() % 4;
  if (decision == 0)
    return 'w';
  else if (decision == 1)
    return 'a';
  else if (decision == 2)
    return 's';
  else if (decision == 3)
    return 'd';
}

// calculate score (process)
int convert_score(char type) {
  if (type == 'D')
      return 100;
  else if (type == 'G')
      return 50;
  else if (type == 'S')
      return 20;
  else if (type == 'B')
      return 10;
}


//to allocate the coordinates of resources onto the gameboard
void allocate_resources(coord* resource, int number_of_resources, int board_size){
  // coord* resource = new coord[number_of_resources];
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
}

// assign resources on the gameboard
void assign_resources(int number_of_resources, coord *resource, char **board){
  for (int i = 0;i < number_of_resources;i++) {
    board[resource[i].y + 1][resource[i].x + 1] = resource[i].type;
  }
}

// To allocate players into the board
void allocate_player(int board_size, char** board, int number_of_resources , coord* resource, player &p1,player &p2, int * points) {
  int manhatten_distance, point = 0;
  for (int i = 0; i < board_size * board_size; i++) {
      points[i] = -1;
      if (board[(i/board_size) + 1][i%board_size + 1] == ' '){
        point = 0;
        for (int j = 0; j < number_of_resources; j++) {
          if (resource[j].type != '\0') {
            manhatten_distance = abs(resource[j].x - (i%board_size)) + abs(resource[j].y - (i/board_size));
            point = point + convert_score(resource[j].type)/manhatten_distance;
          }
        }
        points[i] = point;
      }
    }
  int least_difference = abs(points[1] - points[0]),location_1 = 0,location_2 = 1;
  for (int i = 0; i < board_size * board_size ; i++) {
    for (int j = i + 1; j < board_size * board_size; j++) {
      if (points[i] != -1 &&points[j] != -1) {
        if (abs(points[i] - points[j]) <= least_difference) {
          least_difference = abs(points[i] - points[j]);
          location_1 = i;
          location_2 = j;
        }
      }
    }
  }
  p1.x = location_1%board_size;
  p1.y = location_1/board_size;
  p2.x = location_2%board_size;
  p2.y = location_2/board_size;
  board[location_1/board_size + 1][location_1%board_size + 1] = '1';
  board[location_2/board_size + 1][location_2%board_size + 1] = '2';
  delete[] points;
}

// check if the game ends
bool Check_endgame(coord *resource,int number_of_resources){
  for (int i = 0; i < number_of_resources;i++)
    if (resource[i].type != '\0')
      return false;
  return true;
}

// check if the movement is valid
bool Movement_valid(char player_movement, player &p1,player &p2, int who_move, int board_size, char** board){
  int new_p1_x, new_p1_y, new_p2_x, new_p2_y;
  if ( who_move == 0){
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
      board[p1.y+1][p1.x+1] = ' ';
      board[new_p1_y+1][new_p1_x+1] = '1';
      p1.y = new_p1_y;
      p1.x = new_p1_x;
    }
    return true;
  }
  if ( who_move == 1){
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
      board[p2.y + 1][p2.x + 1] = ' ';
      board[new_p2_y +1][new_p2_x +1] = '2';
      p2.y = new_p2_y;
      p2.x = new_p2_x;
    }
    return true;
  }
}

//to calculate the next resource to be collected by the bot in hard mode
int target_resource_hard_mode(coord* resource, int number_of_resources, player&p1, player&p2, char** board,int board_size){
  double manhatten_distance;
  double point = 0;
  double* point_arr = new double[number_of_resources];
  for (int i = 0;i < number_of_resources; i++) {
    if (resource[i].type != '\0') {
      manhatten_distance = abs(resource[i].x - p2.x) + abs(resource[i].y - p2.y);
      point += (convert_score(resource[i].type)/manhatten_distance) * (number_of_resources - 1);
      for (int j = 0;j < number_of_resources; j++) {
        if (j != i && resource[j].type != '\0') {
            manhatten_distance = abs(resource[j].x - resource[i].x) + abs(resource[j].y - resource[i].y);
            point += convert_score(resource[j].type)/manhatten_distance;
        }
      }
    }
    else point_arr[i] = -1;
    point_arr[i] = point;
    point = 0;
  }
  double max_point = point_arr[0];
  int max_point_index = 0;
  for (int i = 0;i < number_of_resources; i++) {
    if (point_arr[i] > max_point) {
      max_point = point_arr[i];
      max_point_index = i;
    }
  }
  delete [] point_arr;
  return max_point_index;
}

bool check_step_valid(char player_movement, player &moving_one,player &another_player, int board_size, char** board) {
  int new_moving_one_x, new_moving_one_y;
  if (player_movement == 'w') {
    new_moving_one_y = moving_one.y-1;
    new_moving_one_x = moving_one.x;
  }
  if (player_movement == 's') {
    new_moving_one_y = moving_one.y+1;
    new_moving_one_x = moving_one.x;
  }
  if (player_movement == 'a') {
    new_moving_one_x = moving_one.x-1;
    new_moving_one_y = moving_one.y;
  }
  if (player_movement == 'd') {
    new_moving_one_x = moving_one.x+1;
    new_moving_one_y = moving_one.y;
  }
  if (new_moving_one_x < 0 || new_moving_one_x >= board_size || new_moving_one_y < 0 || new_moving_one_y >= board_size||(new_moving_one_x == another_player.x&&new_moving_one_y == another_player.y))
    return false;
  return true;
}

char hard_mode_move(int target_resource, coord* resource, player&p1, player&p2,char**board,int board_size) {
  char vertical_move = '\0', horizontal_move = '\0';
  if (resource[target_resource].x < p2.x)
     horizontal_move = 'a';
  else if (resource[target_resource].x > p2.x)
     horizontal_move = 'd';
  if (resource[target_resource].y < p2.y)
    vertical_move = 'w';
  else if (resource[target_resource].y > p2.y)
    vertical_move = 's';
  if (vertical_move != '\0' && horizontal_move != '\0') {
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0)
      return horizontal_move;
    else return vertical_move;
  }
  else if (vertical_move == '\0') {
    if (check_step_valid(horizontal_move,p2,p1,board_size,board))
      return horizontal_move;
    else
      return 'w';
  }
  else if (horizontal_move == '\0') {
    if (check_step_valid(vertical_move,p2,p1,board_size,board))
      return vertical_move;
    else
      return 'd';
  }
}


void process(coord *resource, int number_of_resources, player &p1, player &p2, char **board, int board_size, int number_of_player, string difficulty,int * p1_round_score,int* p2_round_score){
  char player_movement;
  int turn = who_go_first(p1.username,p2.username),target_resource;
  cout << "Initial gameboard" << endl << endl;
  Display_Gameboard(board,board_size,*p1_round_score,*p2_round_score,p1.username,p2.username);
  cout << endl;
  cout << "please press <enter> to continue" << endl;
  cin.get();
  Clear_Screen();
  target_resource = target_resource_hard_mode(resource,number_of_resources,p1,p2,board,board_size);
  while (Check_endgame(resource,number_of_resources) == false) {
    if (turn == 0) {
      cout << p1.username  << " " << "\xe2\x98\xba" << " turn" << endl << endl;
    }
    else  {
      cout << p2.username  << " " << "\xe2\x98\xbb" << " turn" << endl << endl;
    }

    if (number_of_player == 1 && turn == 1) {}
    else
      Display_Gameboard(board,board_size,*p1_round_score,*p2_round_score,p1.username,p2.username);
    if (turn == 0) {
      cout << "please enter your movement (w/a/s/d)" << endl;
      cin >> player_movement;
    }
    else if (turn == 1 && number_of_player == 1) {
      if (difficulty == "easy")
        player_movement = easy_mode();
      if (difficulty == "hard")
        player_movement = hard_mode_move(target_resource,resource,p1,p2,board,board_size);
      cout << "player " << turn + 1 << " turn , please wait " << endl << endl;
    }
    else {
      cout << "please enter your movement (w/a/s/d)" << endl;
      cin >> player_movement;
    }
    while (Movement_valid(player_movement,p1,p2,turn,board_size,board) == false) {
      if (turn == 0) {
        cin >> player_movement;
        cout << "invalid movement, please choose again!" << endl;
      }
      else if (turn == 1 && number_of_player == 1) {
        if (difficulty == "easy") {
          player_movement = easy_mode();
        }
        if (difficulty == "hard")
          player_movement = hard_mode_move(target_resource,resource,p1,p2,board,board_size);
      }
      else {
        cout << "please enter your movement (w/a/s/d)" << endl;
        cin >> player_movement;
      }
    }
    for (int i=0; i < number_of_resources; i++){
      if (p1.x == resource[i].x && p1.y == resource[i].y) {
        p1.score += convert_score(resource[i].type);
        *p1_round_score += convert_score(resource[i].type);
        resource[i].x = - 1;
        resource[i].y = - 1;
        resource[i].type = '\0';
        if (i == target_resource)
          target_resource = target_resource_hard_mode(resource,number_of_resources,p1,p2,board,board_size);
      }
      if (p2.x == resource[i].x && p2.y == resource[i].y) {
        p2.score += convert_score(resource[i].type);
        *p2_round_score += convert_score(resource[i].type);
        resource[i].x = - 1;
        resource[i].y = - 1;
        resource[i].type = '\0';
        target_resource = target_resource_hard_mode(resource,number_of_resources,p1,p2,board,board_size);
      }
    }
    turn = abs(turn - 1); // need cstdlib
    Clear_Screen();
  }
}
