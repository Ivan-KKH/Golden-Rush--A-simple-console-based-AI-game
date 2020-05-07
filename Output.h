#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <iostream>

#endif

using namespace std;

// to display the gamerule (output)
void Display_Gamerule() {
  string s;
  ifstream fin;
  fin.open("gamerule.txt");
  if (fin.fail()) {
    cout << "failed to open gamerule" << endl;
  }
  while (getline(fin,s))
    cout << s << endl;
  fin.close();
}
