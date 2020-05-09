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

// to show the winner of the round
void Show_round_winner(int p1_score,int p2_score, player&p1,player&p2) {
  if (p1_score > p2_score) {
      cout << endl << p1.username <<  " wins this round" << endl;
      p1.win++;
  }
  else if (p2_score > p1_score) {
      cout << endl << p2.username << " wins this round" << endl;
      p2.win++;
  }
  else
    cout << endl << "This round is a draw." << endl << endl;
  cout << "Cumulated score(including this round): " << endl << endl;
  cout << p1.username <<": " << p1.score << endl;
  cout << p2.username << ": " << p2.score << endl;
}
