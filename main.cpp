// CPSC-350-01 Assignment 4
// main.cpp
// Test driver to check template queue functionality working with Student class (temporary; replace when needed!).
// Logan Welsh
// 04/18/2020

#include <iostream>
#include <string>
#include "GenQueue.cpp"
#include "Student.h"

using namespace std;

int main(int argc, char** argv) {	
	
	
	// Instantiate a Student queue.
	GenQueue<Student> *gq = new GenQueue<Student>();

	// Throw some Students into the queue.
	gq->enqueue(Student(1, 5));	// Student A
	gq->enqueue(Student(1, 10));	// Student B
	gq->enqueue(Student(3, 4));	// Student C

	// Test dequeueing functionality.
	Student testA = gq->dequeue();	// Dequeue A.
	cout << testA.getWinT() << endl;
	
	Student testB = gq->dequeue();	// Dequeue B.
	cout << testB.getWinT() << endl;
	
	cout << testA.getWinT() << endl;	// Check that we still have copy of A after dequeueing.


	
	// Clean up.
	delete gq;
	
	return 0;
}
