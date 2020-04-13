#ifndef PLAYER_MOVEMENT_CONTROL_H_
#define PLAYER_MOVEMENT_CONTROL_H_

#include <iostream>
#include <conio.h>

#endif

using namespace std;

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ESCAPE 27

char Player_Movement_Control() {
    char charInput;
    charInput = _getch();
    int intInput = charInput;
    switch (charInput) {
      case ARROW_UP:
          return 'u';
          break;
      case ARROW_DOWN:
          return 'd';
          break;
      case ARROW_LEFT:
          return 'l';
          break;
      case ARROW_RIGHT:
          return 'r';
          break;
      case 'w':
        return 'u';
        break;
      case 'a':
        return 'l';
        break;
      case 's':
        return 'd';
        break;
      case 'd':
        return 'r';
        break;
      }
      charInput = _getch();
      intInput = charInput;
    }
}
