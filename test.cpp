#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;
int main()
{
     int v = 7 ;
     int* pointer = &v ;
     // use *pointer
     cout << *pointer;
     delete pointer ; // undefined behaviour
}
