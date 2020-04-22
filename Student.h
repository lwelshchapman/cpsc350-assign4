// CPSC-350-01 Assignment 4
// Student.h
// Declaration of Student class for registrar simulation.
// Logan Welsh
// 04/18/2020

class Student {
	
	public:
		// Constructors:
		Student();
		Student(int arrT, int winT);
		Student(const Student &other);
		~Student();
		
		// Mutators:
		void setArrT(int arrT);
		void setWinT(int winT);
		
		// Accessors:
		int getArrT();
		int getWinT();
	
		// Auxiliary functions:
		Student* clone();
	
	private:
		// Member variables:
		int arrT;	// Arrival time
		int winT;	// Time needed at the window
	
		// Internal functions:
		void init(int arrT, int winT);
	
};