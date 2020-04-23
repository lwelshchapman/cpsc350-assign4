#include "Clock.h"

Clock::Clock(){
  time = 0;
}

Clock::~Clock(){
  time = 0;
}

int Clock::tick(){
++time;
}

int Clock::getTime() {
	return time;
}
