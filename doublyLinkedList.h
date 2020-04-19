///header (.h) file for my single linked list
#include <iostream>
using namespace std;

//typedef int Data;
class ListNode{
public:
  int data;
  ListNode* next;
  ListNode* prev;

  friend class DoubleLinkedList;

  ListNode(); //default constructor
  ListNode(int d); //overloaded constructor
  ~ListNode();

};
