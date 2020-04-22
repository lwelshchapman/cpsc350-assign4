#include "window.h"

Window::Window(){
  window = new int[0];
  numOfWindows = 0;
}

Window::Window(int x){
  window = new int[x];
  numOfWindows = x;

}

bool Window::assignWindow(Student* student){
  int timeNeeded = student->getArrivalTime();

  if(isFull()){
    return false;
  }

  for(int i = 0; i <= numOfWindows; ++i){
    if(window[i] == 0){
      window[i] = timeNeeded;
      break;
      return true;
    }
    else{
      continue;
    }
  }
}

void Window::windowDecrease(){
  for(int i = 0; i == numOfWindows; ++i){
    if(window[i] > 0){
      --window[i];
    }
    else{
      continue;
    }
  }
}

bool Window::isFull(){
  int closed = 0;
  for(int i = 0; i <= numOfWindows; ++i){
    if(window != 0){
      ++closed;
    }
  }
  if(closed == numOfWindows){
    return false;
  }
  else{
    return true;
  }
}
