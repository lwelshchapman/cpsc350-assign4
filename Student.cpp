// CPSC-350-01 Assignment 4
// Student.cpp
// Definition of Student class for registrar simulation.
// Logan Welsh
// 04/18/2020

#include "Student.h"

Student::Student() {
	init(0, 0);
}

Student::Student(int arrivalTime, int windowTime) {
	init(arrivalTime, windowTime);
}

Student::~Student() {
	
}

void Student::init(int arrivalTime, int windowTime) {
	setArrivalTime(arrivalTime);
	setWindowTime(windowTime);
}



void Student::setArrivalTime(int arrivalTime) {
	this->arrivalTime = (arrivalTime >= 0) ? arrivalTime : 0;
}

void Student::setWindowTime(int windowTime) {
	this->windowTime = (windowTime >= 0) ? windowTime : 0;
}



int Student::getArrivalTime() {
	return windowTime;
}

int Student::getWindowTime() {
	return windowTime;
}