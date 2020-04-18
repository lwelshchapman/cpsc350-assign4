// CPSC-350-01 Assignment 4
// DLL.cpp
// Template class for a simple doubly-linked list.
// Logan Welsh
// 04/18/2020

#include "ListNode.cpp"
#include <iostream>

template <class T>
class DoublyLinkedList {
	
	private:
		ListNode<T> *front;	// Pointer to front (first node in list)
		ListNode<T> *back;	// Pointer to back (last node in list)
		unsigned int size;	// Total number of nodes currently in the list; updated whenever nodes are added/removed

	public:
		DoublyLinkedList();	// Default constructor
		~DoublyLinkedList();	// Destructor
		
		void insertFront(T data);
		void insertBack(T data);
		T removeFront();
		T remove(T val);	// Removes node with specified VALUE; NOT at POSITION
		T removeBack();
		int search(int val);	// Return value or position of node (depending on implementation; typically returns position)
		int removeAtPos(int pos);
		int insertAtPos(int pos);	// Optional; very similar to removeAtPos
		int get(int pos);	// CUSTOM; might rename to "peek"

		unsigned int getSize();
		bool isEmpty();
		void printList();

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	// Empty list
	size = 0;
	front = NULL;
	back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {	// !!
	// Up to us to implement
	// Look at removeFront!!
	
	delete front;
	
}


template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
	return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList() {
	ListNode<T> *curr = front;	// Doesn't need to be deleted; did not specify "new"; kept on stack, deleted when out of scope
	int count = 0;
	
	while(curr != NULL) {
		std::cout << count << ": " << curr->data << std::endl;
		curr = curr->next;
		count++;
	}
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d) {
	ListNode<T> *node = new ListNode<T>(d);
	// Check if empty
	if(isEmpty()) {
		back = node;
	}
	else {
		front->prev = node;
		node->next = front;
	}
	front = node;
	size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
	ListNode<T> *node = new ListNode<T>(d);
	// Check if empty
	if(isEmpty()) {
		front = node;
	}
	else {
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront() {
	// Check if list is empty
	if(isEmpty()) {
		return -1;	// Might need to return -1
	}

	ListNode<T> *temp = front;


	if(front->next == NULL) {
		// Only one item in list
		back = NULL;
	}
	else {
		// More than one node in list
		front->next->prev = NULL;
	}
	front = front->next;

	temp->next = NULL;
	int tmp = temp->data;
	delete temp;
	size--;
	return tmp;
}

// Need to find the value in the list before we can delete
// This function does NOT take in a position as a parameter
template <class T>
T DoublyLinkedList<T>::remove(T val) {
	ListNode<T> *curr = front;

	while(curr->data != val) {
		// Keep iterating until we find our value
		curr = curr->next;

		if(curr == NULL) {
			return NULL;	// Return NULL if the value does not exist in the list
		}
	}

	// Found value, proceed to delete
	if(curr == front) {
		// Check if node to be deleted is the front
		front = curr->next;
	}
	else {
		// Node to be deleted is not the front or back
		curr->prev->next = curr->next;
	}

	if(curr == back) {
		back = curr->prev;
	}
	else {
		// Node to be deleted is not the front or back, it's inbetween
		curr->next->prev = curr->prev;
	}

	curr->next = NULL;
	curr->prev = NULL;
	T tmp = curr->data;
	delete curr;
	size--;
	return tmp;
}

template <class T>
int DoublyLinkedList<T>::search(int val) {

}


template <class T>
int DoublyLinkedList<T>::removeAtPos(int pos) {

}



