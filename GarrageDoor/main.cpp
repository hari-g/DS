#include <iostream>
#include "garragedoor.h"


using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    GarrageDoor gd;
  //  gd.CycleComplete();
    cout << gd.printState();
    return 0;
}
