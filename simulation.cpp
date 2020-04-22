#include "simulation.h"

Simulation::Simulation(){
}

Simulation::~Simulation(){

}

void Simulation::readFile(string fileName){
  ifstream inFS;
  inFS.open(filename);

  if(!inFS.is_open()){ //if file cannot be opened end program
    cout<< "could not open file "<< filename<<endl;
    return 1; //break program
  }
  while(!inFS.eof()){
    getline(inFS, line);
    DLinkedList* file = new DLinkedList();

    file->insertBack(line);
  }

  int windows = file->front;
  Window* window = new Window(windows);

  file->removeFront();


}
