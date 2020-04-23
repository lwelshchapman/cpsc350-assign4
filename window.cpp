#include "Window.h"

Window::Window(){
  initWindows(0);
}

Window::Window(int x){
  initWindows(x);
}

Window::~Window() {
	delete window;
}

void Window::initWindows(int x) {
	numOfWindows = x;
	window = new int[numOfWindows];
	for(int i = 0; i < numOfWindows; ++i) {
		window[i] = 0;
	}
}

int Window::assignWindow(Student student){	// Returns the amount of time the window was idle
  //int timeNeeded = student.getWinT();

  for(int i = 0; i < numOfWindows; ++i){
    if(window[i] <= 0){
	  int temp = abs(window[i]);
      window[i] = student.getWinT();
      return temp;
    }
  }
  return -1;
}

void Window::windowDecrease(){
  for(int i = 0; i < numOfWindows; ++i){
    window[i]--;
  }
}

bool Window::isFull(){
  int closed = 0;
  for(int i = 0; i < numOfWindows; ++i){
	//cout << "Window report: " << i << ' ' << window
    if(window[i] > 0){
      ++closed;
    }
  }
  return (closed == numOfWindows);
}
