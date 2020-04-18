// CPSC-350-01 Assignment 4
// Student.h
// Declaration of Student class for registrar simulation.
// Logan Welsh
// 04/18/2020

class Student {
	
	public:
		Student();
		Student(int arrivalTime, int windowTime);
		~Student();
		
		void setArrivalTime(int arrivalTime);
		void setWindowTime(int windowTime);
		
		int getArrivalTime();
		int getWindowTime();
	
	
	
	private:
		int arrivalTime;
		int windowTime;
	
		void init(int arrivalTime, int windowTime);
	
};