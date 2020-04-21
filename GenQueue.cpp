// CPSC-350-01 Assignment 4
// DLL.cpp
// Template class for a doubly-linked-list-based queue.
// Macy Werner (modified by Logan Welsh)
// 04/18/2020

#include <iostream>
#include "DLL.cpp"

template <class T>
class GenQueue{

public:
  GenQueue(); //default constructor
  ~GenQueue();

  //core functions
  void enqueue(T d); //enqueue (at the rear)
  T dequeue(); //denqueue (at the front)

  //aux functions
  T peek();
  bool isEmpty();
  int getSize();

  DLL<T> *D;


};


template <class T>
GenQueue<T>::GenQueue(){
  //default constructor
  D = new DLL<T>();
}

template <class T>
GenQueue<T>::~GenQueue(){
  delete D;
}

template <class T>
void GenQueue<T>::enqueue(T d){
  D->insertBack(d);
}

template <class T>
T GenQueue<T>::dequeue(){
  return D->removeFront();
}

template <class T>
T GenQueue<T>::peek(){
  return D->peek(0);
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return D->isEmpty();
}

template <class T>
int GenQueue<T>::getSize(){
  return D->getSize();
}
