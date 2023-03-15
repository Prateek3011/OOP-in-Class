/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/14/2023
// Author:	Sae-mi Park
// File:	Fish.cpp
// 
// 
// Version: 0.3 - Update based on initial feedback 
// 
// Description: Test program
////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Fish.h"

using namespace std;

namespace sdds
{
	Fish::Fish() {
		//setEmpty();
	}
	Fish::Fish(const char* name, int age, double incrBaseCharge) : Pet(name, age, incrBaseCharge) {
		//Pet::Pet(name, age, incrBaseCharge);
	}
	void Fish::feed() {
		double feedingFee = 0.0;

		Pet::feed();
		if (isAlive())
		{
			feedingFee += 0.10;
			addCharge(feedingFee);
		}
	}
	void Fish::reSpawn() {
		double respawnFee = 0.0;
		Pet::reSpawn();
		respawnFee += 0.50;
		addCharge(respawnFee);

	}
	void Fish::operator++ (int num) {
		double healthDelta = 0;

		if (isAlive())
		{
			healthDelta += 0.20 * (getFeeds() - 1);
		}
		applyHealthDelta(healthDelta);
		Pet::operator++ (num);
	}
	Fish& Fish::operator=(const Fish& rhs) {
		double cloningFee = 0.0;
		cloningFee = 2 * 2.0;

		Pet::operator=(rhs);
		addCharge(cloningFee);

		return *this;
	}



	std::ostream& operator<<(std::ostream& os, Fish& fish)
	{
		os << "** Generic Fish **" << endl;
		return fish.outputData(os);
	}
}