#include<iostream>
#include<iomanip>
#include<conio.h>
#include "Player_Movement_control.h"
using namespace std;
int main()
{
     char move;
     while (true) {
       move = Player_Movement_control();
       cout << move << endl;
     }
}
