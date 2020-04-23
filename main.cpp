// CPSC-350-01 Assignment 4
// main.cpp
// Main driver for Registrar simulation.
// Logan Welsh
// 04/18/2020

#include <iostream>
#include <string>
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv) {	
	
	try {
		Simulation *sim = new Simulation("test.in");
		
		//sim->printLine();
		
		while(!sim->line->isEmpty()) {
			sim->tickClock();
		}
		cout << "Waits: " << sim->getWaits() << endl;
		cout << "Idles: " << sim->getIdles() << endl;
		sim->analysis();
		
		delete sim;
	}
	catch(int e) {
		cout << "Exception occurred: " << e << endl;
	}
	
	return 0;
}
