#include <iostream>
#include "Student.cpp"

using namespace std;

class Window{
public:
  Window();
  Window(int x);
  ~Window();

  bool assignWindow(Student* student);
  void windowDecrease();
  bool isFull();

  int numOfWindows;

  int *window;

};
