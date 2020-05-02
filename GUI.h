#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>

#endif

using namespace std;

void Main_Menu(){
  system("CLS");

}

void Clear_Screen(){
  if (system("CLS")){
    system("clear");  
  }
}

void Gameboard(string &username){
  cout << "adventurer: " << username << endl;
  cout << "score: " << endl;
  cout << endl;
}
