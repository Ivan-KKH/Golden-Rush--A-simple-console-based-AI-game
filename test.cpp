#include<iostream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
  for (int i = 0; i< 20;i++){
  char a[4] = {'u','d','l','r'};

  int rnd = rand() % 4;
  cout << a[rnd] << endl;
}

}
