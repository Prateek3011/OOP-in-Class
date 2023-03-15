/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	03/14/2023
// Author:	Sae-mi Park
// File:	Dog.cpp
// 
// 
// Version: 0.3 - Update based on initial feedback 
// 
// Description: Test program
////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Dog.h"

using namespace std;

namespace sdds
{
	Dog::Dog() {
		m_numWalks = 0;
	}
	Dog::Dog(int numWalk) {
		m_numWalks = numWalk;
	}
	Dog::Dog(const char* name, int age, double incrBaseCharge) : Pet(name, age, incrBaseCharge) {
		m_numWalks = 0;
	}
	void Dog::feed() {
		double feedingFee = 0.0;

		Pet::feed();
		if (isAlive())
		{
			feedingFee += 0.25;
			addCharge(feedingFee);
		}
	}
	void Dog::reSpawn() {
		double respawnFee = 0.0;
		Pet::reSpawn();
		respawnFee += 1.00;
		addCharge(respawnFee);
		m_numWalks = 0;
	}
	void Dog::walk() {
		if (isAlive())
		{
			m_numWalks++;
		}

	}
	int Dog::getWalks() {
		return m_numWalks;
	}

	void Dog::operator++ (int num) {
		double healthDelta = 0;

		if (isAlive())
		{
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (getWalks() - 2);
		}
		applyHealthDelta(healthDelta);
		m_numWalks = 0;
		Pet::operator++ (num);
	}
	Dog& Dog::operator=(const Dog& rhs) {
		double cloningFee = 0.0;
		cloningFee = 2 * 4.0;

		Pet::operator=(rhs);
		addCharge(cloningFee);

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, Dog& dog) {
		os << "** Generic Dog **" << endl;
		os << "   Walks: " << dog.getWalks() << endl;
		return dog.outputData(os);
	}
}