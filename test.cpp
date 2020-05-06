#include <iostream>    //std:;cout, std::endl
#include <iomanip>     //std::setfill, std:: setw

using namespace std;

int main() {
  cout << scientific << 23000000000000 << endl;
  cout << fixed << setprecision(2) << 10.003 << endl;

}
