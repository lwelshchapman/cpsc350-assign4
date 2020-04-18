// CPSC-350-01 Assignment 4
// main.cpp
// Test driver to check doubly-linked list functionality (temporary; replace when needed!).
// Logan Welsh
// 04/18/2020

#include <iostream>
#include <string>
#include "DLL.cpp"

using namespace std;

int main(int argc, char** argv) {
	
	DoublyLinkedList<string> *dll = new DoublyLinkedList<string>();

	dll->insertFront("Sup fella?");
	dll->insertBack("Get cheesed.");
	dll->insertFront("Good evening, sportsfans!");
	
	dll->printList();

	delete dll;	
	
	return 0;
}
