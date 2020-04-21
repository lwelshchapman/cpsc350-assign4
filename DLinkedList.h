////header file for DoubleLinkedList
#include "doublyLinkedList.h"


class DLinkedList{
private:
  /*ListNode* front;
  ListNode* back;
  unsigned int size;*/

public:
  DLinkedList();
  ~DLinkedList();

  void insertFront(int data);
  void insertBack(int data);
  int removeFront();
  int removeBack();
  int search(int val); // will return position of node depends
  int removeAtPos(int pos);
  int removeValue(int value);

  unsigned int getSize();
  bool isEmpty();
  void printList();

  ListNode* front;
  ListNode* back;
  unsigned int size;

};
