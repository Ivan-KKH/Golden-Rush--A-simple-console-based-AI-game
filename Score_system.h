#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

#include <iostream>

#endif

using namespace std;

void Score_system(player player,coord  resource,int number_of_resources){
  for (int i=0; i < number_of_resources; i++){
    if (player.x == resource[i].x && player.y == resource[i].y){

      if (resource[i].type == 'd'){
          player.score += 100;
      }
      else if (resource[i].type == 'g'){
          p1ayer.score += 50;
      }
      else if (resource[i].type == 's'){
          p1ayer.score += 20;
      }
      else if (resource[i].type == 'b'){
          p1ayer.score += 10;
      }
      resource[i].x = -1;
      resource[i].y = -1;
      resource[i].type = '\0';
    }
  }
}
