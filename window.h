#include <iostream>
#include <cstdlib>
#include "Student.h"

using namespace std;

class Window{
public:
  Window();
  Window(int x);
  ~Window();

  int assignWindow(Student student);
  void windowDecrease();
  bool isFull();

  int numOfWindows;

  int *window;

private:
  void initWindows(int x);
};
