//ListNode implementation file (.cpp)
#include "doublyLinkedList.h"

ListNode::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;
}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode(){
  //figure it out
}
