#ifndef LEADERBOARD_H_
#define LEADERBOARD_H_


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#endif

using namespace std;


void Print_leaderboard(player &p1, int board_size){

  int n=21, m=3;
  vector <vector<string>> usernames(n);
  vector <vector<int>> scores(n);

  int nop=1;
  // int board_size;
  int score;
  // int p1_score=15;
  string username;
  // string p1.username="Ivan";
  string x;

  // cout << "input boardsize: ";
  // cin >> board_size;

// read from previous leaderboard to update highest score -----
  ifstream fin;
  fin.open("Leaderboard.txt");

  if ( fin.fail() ){
    cout << "Error in reading file!" << endl;
    exit(1);
  }


  for (int i=0; i<n; i++){

    if ( (board_size-5) == i){
      for (int j=0; j<m; j++){
        fin >> score >> username;
        if (p1.score > score && j==0){
          int temp_score = score;
          string temp_username = username;
          usernames[i].push_back(p1.username);
          scores[i].push_back(p1.score);

          usernames[i].push_back(temp_username);
          scores[i].push_back(temp_score);

          fin >> score >> username;
          usernames[i].push_back(username);
          scores[i].push_back(score);

          fin >> score >> username;
          cout << endl;
          break;
        }
        else if (p1.score > score && j==1){
          int temp_score = score;
          string temp_username = username;
          usernames[i].push_back(p1.username);
          scores[i].push_back(p1.score);

          usernames[i].push_back(temp_username);
          scores[i].push_back(temp_score);

          fin >> score >> username;
          cout << endl;
          break;
        }
        else if (p1.score > score && j==1){
          usernames[i].push_back(p1.username);
          scores[i].push_back(p1.score);

          fin >> score >> username;
          cout << endl;
          break;
        }
        else {
          usernames[i].push_back(username);
          scores[i].push_back(score);
        }
        cout << endl;
      } //end of for loop
    }

    else{
      for (int j=0; j<m; j++){
        fin >> score >> username;
        usernames[i].push_back(username);
        scores[i].push_back(score);
      }
    }
  }

  cout << "-----------ALL-TIME LEADERBOARD----------" << endl;
  cout << "(Only show top 3 adventurers in each n x n gameboard)" << endl;
  cout << "\n";
  for (int i=0; i<n; i++){
    cout << i+5 << '-' << i+5 << " gameboard ranking" << endl;
    cout << setw(12) << "Adventurer";
    cout << setw(12) << "Score" << endl;
    for (int j=0; j<m; j++){
      cout << j+1 << "  "<< setw(10) << usernames[i][j] ;
      cout << setw(10) << scores[i][j];
      cout << endl;
    }
    cout << "\n";
    cout << "\n";
  }

  fin.close();



// write to file for newest leaderboard update-----
  ofstream fout;
  fout.open("Leaderboard.txt");

  if ( fout.fail() ){
    cout << "Error in writing file!" << endl;
    exit(1);
  }

// update leaderboard.txt
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      fout << scores[i][j] << "\t";
      fout << usernames[i][j] << "\t";
    }
    fout << endl;
  }
  fout.close();


}
