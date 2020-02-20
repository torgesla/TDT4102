//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "rw_file.h"
#include "emnekatalog.h"
#include "r_struct_file.h"

//------------------------------------------------------------------------------'

/* class Animal{

	public:
		Animal(int vekt) : vekt{vekt}{}
		virtual void enFunksjon() = 0;
	private:
		int vekt;
};

class Dyr : public Animal{
	public:
		Dyr(int vekt) : Animal(vekt) {}

}; */

// C++ programs start by executing the function main
int main()
{
	// write_input_to_file();
	// linjenummer();
	// countSymbols();

	//testAddSubjects();
	//testTemps();
	//readWholeFile();
	drawGraph();
	//system("pause");
	keep_window_open();
}

//------------------------------------------------------------------------------
