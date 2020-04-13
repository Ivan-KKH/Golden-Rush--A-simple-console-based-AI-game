#ifndef DISPLAY_GAMERULE_H_
#define DISPLAY_GAMERULE_H_

#include <fstream>
#include <iostream>
#include <string>

#endif

using namespace std;

void Display_Gamerule() {
  string s;
  ifstream fin;
  fin.open("gamerule.txt");
  if (fin.fail()) {
    cout << "failed to open gamerule" << endl;
  }
  ifstream fin;
  while (getline(fin,s)) {
    cout << s << endl;
  }
  close fin;
}
