#include <iostream>
#include "DLinkedList.h"
using namespace std;

class GenQueue{
public:
  GenQueue(); //default constructor
  //GenQueue(int maxSize); //overloaded constructor
  ~GenQueue();

  //core functions
  void insert(int d); //enqueue (at the rear)
  int remove(); //denqueue (at the front)

  //aux functions
  //int peek();
  bool isEmpty();
  int getSize();

  //vars
  //int front; //aka head
  //int rear; // aka tail
  int size;

  DLinkedList* D;
//  ListNode* front;
  //ListNode* back;

  //ListNode* head;
  //ListNode* tail;

};
