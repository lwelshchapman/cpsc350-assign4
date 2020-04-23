#include <iostream>
#include <fstream>
#include <string>

#include "GenQueue.cpp"
#include "Student.h"
#include "Window.h"

using namespace std;

class Simulation{
	public:
		Simulation(string filename);
		~Simulation();

		void readFile(string filename);
		void tickClock();
		void printLine();
		
		string getWaits();
		string getIdles();
		/*
		double getWaitMean();
		int getWaitMedian();
		int getLongestWait();
		int getWaitsGrTen();
		double getMeanWinIdle();
		int getLongestWinIdle();
		int getWinIdleGrFive();
		*/
		void analysis();
		
		GenQueue<Student> *line;
		DLL<int> *waitTimes;
		DLL<int> *idleTimes;
		Window *win;
		int time;

};
