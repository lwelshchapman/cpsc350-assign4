// CPSC-350-01 Assignment 4
// Student.cpp
// Definition of Student class for registrar simulation.
// Logan Welsh
// 04/18/2020

#include "Student.h"

// Constructors:
Student::Student() {
	init(0, 0);
}

Student::Student(int arrT, int winT) {
	init(arrT, winT);
}

Student::Student(const Student &other) {
	init(other.arrT, other.winT);
}

Student::~Student() {
	// Nothing to see here!
}



// Mutators:
void Student::setArrT(int arrT) {	// Prevents negative arrival times without annoying "unsigned" keyword.
	this->arrT = (arrT >= 0) ? arrT : 0;
}

void Student::setWinT(int winT) {	// Prevents negative window times without annoying "unsigned" keyword.
	this->winT = (winT >= 0) ? winT : 0;
}



<<<<<<< HEAD
// Accessors:
int Student::getArrT() {
	return arrT;
}

int Student::getWinT() {
	return winT;
}



// Auxiliary functions:
Student* Student::clone() {
	return new Student(getArrT(), getWinT());
}



// Internal functions:
void Student::init(int arrT, int winT) {
	setArrT(arrT);
	setWinT(winT);
}

