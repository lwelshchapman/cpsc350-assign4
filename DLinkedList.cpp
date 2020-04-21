///implementation file (.cpp) for my NaiveList
#include "DLinkedList.h"
//#include "doublyLinkedList.cpp"

DLinkedList::DLinkedList(){
  //empty list
  size = 0;
  front = NULL;
  //front = new ListNode;
  //back = new ListNode;
  //front ->next = back;
  //back ->prev = front;

}

DLinkedList::~DLinkedList(){
  while(!isEmpty()){
    removeFront();
  }
  delete front;
  delete back;
}

unsigned int DLinkedList::getSize(){
  return size;
}

bool DLinkedList::isEmpty(){
  return (size == 0);
  //return (front->next == back);
}

void DLinkedList::printList(){
  ListNode *curr = front;

  while(curr != NULL){
    cout << curr->data <<endl;
    curr = curr ->next;
  }
}

void DLinkedList::insertFront(int d){

  ListNode *node = new ListNode(d);
  //check if isEmpty
  if(isEmpty()){
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

void DLinkedList::insertBack(int d){

  ListNode *node = new ListNode(d);
  //check if isEmpty
  if(isEmpty()){
    front = node;
  }else{
    //not empty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

int DLinkedList::removeFront(){

  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}


int DLinkedList::search(int val){
  int position = -1;
  ListNode *curr = front;

  while (curr != NULL){
    //interate and attempt to find the value
    position++;

    if(curr->data == val){
      break;
    }
    else{
      curr = curr->next;
    }
  }if(curr == NULL) {
    position = -1;//we did not find the value
  }
  return position;
}

int DLinkedList::removeAtPos(int pos){

  //error checking
  int idx = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  //now let's loop until position
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
  }
  //we found the position of the node to be deleted
  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;

}

int DLinkedList::removeValue(int value){
  ListNode* curr = front;

  while(curr->data != value){
    curr = curr-> next;

    if(curr == NULL){
      return -1;
    }
  }
  if (curr == front){
    front = curr->next;
  }
  else{
    curr->prev->next = curr->next;
  }

  if(curr == back){
    back = curr->prev;
  }
  else{
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}
