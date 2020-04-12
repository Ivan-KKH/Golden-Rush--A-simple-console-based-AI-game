#include <conio.h>
#include <iostream>
#include "Player_Movement_Control.h"
using namespace std;

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ESCAPE 27

int main(){
  Player_Movement_Control();
}
void Player_Movement_Control() {
    char charInput;
    charInput = _getch();
    int intInput = charInput;
    while (intInput != ESCAPE) {
        switch (intInput) {
        case ARROW_UP:
            cout << "up" << endl;
            break;
        case ARROW_DOWN:
            cout << "down" << endl;
            break;
        case ARROW_LEFT:
            cout << "left" << endl;
            break;
        case ARROW_RIGHT:
            cout << "right" << endl;
            break;
        }
        charInput = _getch();
        intInput = charInput;

    }
}
