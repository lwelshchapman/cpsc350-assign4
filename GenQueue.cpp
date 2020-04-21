#include "GenQueue.h"


GenQueue::GenQueue(){
  //default constructor
  //implement this
  /*myQueue = new char[128];
  mSize = 128;
  front = 0;
  rear = -1;
  numElements = 0;*/
  *D;
  size = 0;
  D->front = NULL;
  D->back = NULL;
}

/*GenQueue::GenQueue(int maxSize){
  myQueue = new char[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}*/

GenQueue::~GenQueue(){
  //no brackets
  delete D;
}

void GenQueue::insert(int d){
  //add error checking, make sure its not full before you add
  ++size;
  ListNode *node = new ListNode(d);
  node->data = d;
  node->next=NULL;
  if (D->front == NULL){
    D->front = node;
  }
  else{
    D->back->next = node;
    D->back = node;
  }
  //myQueue[++rear] = d;
  //++numElements;
}

int GenQueue::remove(){
  //error checking, make sure its not empty
  if (D->front == NULL){
    //Queue is empty
  }
  --size;
  ListNode *curr = D->front; // from https://www.daniweb.com/programming/software-development/threads/459537/c-object-oriented-queue-using-double-linked-list
  D->front = D->front->next;
  delete curr;
  /*int i = '\0'; //good practice
  i = myQueue[front];
  ++front;
  --numElements;
  return i;*/
}

/*char GenQueue::peek(){
  return myQueue[front];
}*/

bool GenQueue::isEmpty(){
  return (size == 0);
}

int GenQueue::getSize(){
  return size;
}
