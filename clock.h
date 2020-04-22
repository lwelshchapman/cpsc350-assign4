#include <iostream>

using namespace std;

class Clock{
public:
  Clock();
  ~Clock();

  int time;

  int tick();
  int getTime();


};
