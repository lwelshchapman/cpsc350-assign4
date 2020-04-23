#include "Simulation.h"

Simulation::Simulation(string filename){
	time = 0;
	line = new GenQueue<Student>();
	waitTimes = new DLL<int>();
	idleTimes = new DLL<int>();
	readFile(filename);
}

Simulation::~Simulation(){
	delete line;
	delete win;
	delete waitTimes;
	delete idleTimes;
}

void Simulation::readFile(string filename){
	// Open the file input stream.
	ifstream inFS;
	inFS.open(filename);

	if(!inFS.is_open()){ // If file cannot be opened, throw exception
		//cout<< "could not open file "<< filename<<endl;
		inFS.close();
		throw -1; // Throw exception: Unable to open input file!
	}
	
	
	// Get data from the input file.
	string inStr = "0";
	if(!inFS.eof()) {	// Get number of windows.
		getline(inFS, inStr);
		win = new Window(stoi(inStr));
	}
	
	int atTime = -1;
	int stuLeft = 0;
	int newNum = 0;
	while(!inFS.eof()){	// Get individual students.
		getline(inFS, inStr);
		
		if(inStr != "") {	// Ignore empty lines
	
			newNum = stoi(inStr);
			
			if(newNum < 0) {
				throw -2;	// Throw exception: Invalid number in input! (A value was less than zero)
			}
		
			if(atTime == -1) {	// This line denotes an arrival time!
				atTime = newNum;
			}
			
			else if(stuLeft == 0) {	// This line denotes a number of students!
				stuLeft = newNum;
			}
			
			else {	// This line denotes a student's window time!
				line->enqueue(Student(atTime, newNum));
				stuLeft--;
				if(stuLeft == 0) {	// Reset, look for new arrival time and number of students.
					atTime = -1;
				}
			}
			
		}
	}
	
	inFS.close();

	if((atTime != -1) || (stuLeft != 0)) {
		throw -3;	// Throw exception: Input ended early! (Declared larger number of students than were given window times)
	}
	
}

void Simulation::tickClock() {
	
	// Debug report
	/*
	cout << "Time: " << time << endl;
	cout << time << ' ' << line->peek().getArrT() << endl;
	cout << win->isFull() << endl;
	*/
	
	// Update windows, a minute has passed
	win->windowDecrease();
	
	// Check for events happening at this minute
	while(!(win->isFull()) && !(line->isEmpty()) && (line->peek().getArrT() <= time)) {
		//cout << "boing" << endl;
		Student first = line->dequeue();
		waitTimes->insertBack(time - first.getArrT());
		int windowIdle = win->assignWindow(first);
		idleTimes->insertBack(windowIdle);
	}
	
	// Increment the time for the next loop
	time++;
}

void Simulation::printLine() {
	for(int i = 0; i < line->getSize(); ++i) {
		cout << line->D->peek(i).toString() << endl;
	}
}

string Simulation::getWaits() {
	string waits = "";
	for(int i = 0; i < waitTimes->getSize(); ++i) {
		waits += to_string(waitTimes->peek(i)) + " ";
	}
	return waits;
}

string Simulation::getIdles() {
	string idles = "";
	for(int i = 0; i < idleTimes->getSize(); ++i) {
		idles += to_string(idleTimes->peek(i)) + " ";
	}
	return idles;
}


void Simulation::analysis() {
	
	// Wait time analysis
	int waitSum = 0;
	double waitMean = 0.0;
	int waitMedian = 0;
	int longestWait = 0;
	int waitsGrTen = 0;

	for(int i = 0; i < waitTimes->getSize(); ++i) {
		// Sum (for mean)
		waitSum += waitTimes->peek(i);
		
		// Median
		//TODO!!!
		
		// Longest
		if(waitTimes->peek(i) > longestWait) {
			longestWait = waitTimes->peek(i);
		}
		
		// Greater than 10
		if(waitTimes->peek(i) > 10) {
			waitsGrTen++;
		}
	}
	waitMean = waitSum / static_cast<double>(waitTimes->getSize());
	
	
	
	// Idle time analysis
	int idleSum = 0;
	double idleMean = 0.0;
	int longestIdle = 0;
	int idleGrFive = 0;
	
	for(int i = 0; i < idleTimes->getSize(); ++i) {
		// Sum (for mean)
		idleSum += idleTimes->peek(i);

		// Longest
		if(idleTimes->peek(i) > longestIdle) {
			longestIdle = idleTimes->peek(i);
		}
		
		// Greater than 10
		if(idleTimes->peek(i) > 10) {
			idleGrFive++;
		}
	}
	idleMean = idleSum / static_cast<double>(idleTimes->getSize());


	// Print report
	cout << "Mean Wait: " << waitMean << endl;
	cout << "Median Wait: " << waitMedian << endl;
	cout << "Longest Wait: " << longestWait << endl;
	cout << "Waits > 10 min: " << waitsGrTen << endl;
	
	cout << "Mean Idle: " << idleMean << endl;
	cout << "Longest Idle: " << longestIdle << endl;
	cout << "Idle > 5 min: " << idleGrFive << endl;
	
}
