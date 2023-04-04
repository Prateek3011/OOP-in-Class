// Final Project 
// Milestone 4
// Perishable and NonPerishable Tester
// Version 1.0
// Date	2023-03-30
// Author	Sae-mi PArk
// Description
// This program test the student implementation of Milestone 4
// for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>

namespace sdds {

	int daysOfMonth(int year, int month);
	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
	void bubble(struct Item* data[], int size);
}
#endif