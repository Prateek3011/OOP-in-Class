//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 22, 2023

/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "GPAlist.h"
#include "GPA.h"

using namespace sdds;

int main() {
	if(gpaQuery("std.csv")) {
		std::cout << "This should have failed!" << std::endl;
	} 
	else {
		std::cout << "failed!, this is the correct exectution" << std::endl;
	}

	if(!gpaQuery("students.csv")) {
		std::cout << "This should have worked, fix the problem!" << std::endl;
	}
	
	std::cout << "Goodbye!" << std::endl;
	return 0;
	}
