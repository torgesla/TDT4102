//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	srand(time(NULL));
	/*testCallByValue();
	testCallByReference();
	testVectorSorting();*/

	/* 	Student student1;
	student1.name = "Torgeir";
	student1.age = 24;
	student1.studyProgram = "ML";
	printStudent(student1); */

	//testString();
	//readInputToString(5, 'A', 'D');
	playMastermind();

	//------------------------------------------------------------------------------
}