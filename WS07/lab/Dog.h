/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/14/2023
// Author:	Sae-mi Park
// File:	Dog.h
// 
// 
// Version: 0.3 - Update based on initial feedback 
// 
// Description: Test program
////////////////////////////////////////////////////////
#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include <iostream>
#include "Pet.h"

namespace sdds
{
	class Dog : public Pet {
		int m_numWalks;

	public:
		Dog();
		Dog(int numWalk);
		Dog(const char* name, int age = 0, double incrBaseCharge = 0);
		void feed();
		void reSpawn();
		void walk();
		int getWalks();
		void operator++ (int num);
		Dog& operator=(const Dog& rhs);



	};
	std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif