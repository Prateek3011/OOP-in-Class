/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/14/2023
// Author:	Sae-mi Park
// File:	Fish.h
// 
// 
// Version: 0.3 - Update based on initial feedback 
// 
// Description: Test program
////////////////////////////////////////////////////////
#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include <iostream>
#include "Pet.h"

namespace sdds
{
	class Fish : public Pet {


	public:
		Fish();
		Fish(const char* name, int age = 0, double incrBaseCharge = 0);
		void feed();
		void reSpawn();
		void operator++ (int num);			// Increment 1 Day
		Fish& operator=(const Fish& rhs);



	};
	std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif