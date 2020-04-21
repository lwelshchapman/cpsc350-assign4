// CPSC-350-01 Assignment 4
// main.cpp
// Test driver to check template queue functionality (temporary; replace when needed!).
// Logan Welsh
// 04/18/2020

#include <iostream>
#include <string>
#include "GenQueue.cpp"

using namespace std;

int main(int argc, char** argv) {
	
	// Instantiate a queue.
	GenQueue<int> *gq = new GenQueue<int>();
	
	// Throw some values into the queue and check the top.
	cout << "Enqueueing 42." << endl;
	gq->enqueue(42);
	cout << "Peek: " << "\n\t" << gq->peek() << endl;
	
	cout << "Enqueueing 117." << endl;
	gq->enqueue(117);
	cout << "Peek: " << "\n\t" << gq->peek() << endl;
	
	// Dequeue the values.
	try {
		cout << "Dequeue: " << "\n\t" << gq->dequeue() << endl;
	}
	catch (int e) {
		cout << "Uh oh: " << e << endl;
	}

	try {
		cout << "Dequeue: " << "\n\t" << gq->dequeue() << endl;
	}
	catch (int e) {
		cout << "Uh oh: " << e << endl;
	}	
	
	try {	// This one intentionally fails to show that the exception-handling works.
		cout << "Dequeue: " << "\n\t" << gq->dequeue() << endl;
	}
	catch (int e) {
		cout << "Tried to dequeue from an empty queue!" << endl;
	}	

	// Clean up.
	delete gq;
	
	return 0;
}
