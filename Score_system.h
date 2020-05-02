#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

#include <iostream>

#endif

using namespace std;

void score_system(){
  for (int i=0; i < number_of_resources; ++i){
    if (player.x == resource[i].x && player.y == resource[i].y){

      if (resource[i] == "diamond"){
          p1.score += 100;
      }
      else if (resource[i] == "gold"){
          p1.score += 50;
      }
      else if (resource[i] == "silver"){
          p1.score += 20;
      }
      else if (resource[i] == "bronze"){
          p1.score += 10;
      }

    }    
  }
}
