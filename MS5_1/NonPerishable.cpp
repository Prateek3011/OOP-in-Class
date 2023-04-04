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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "NonPerishable.h"
using namespace std;

namespace sdds {
	
	char NonPerishable::itemType()const {
		return 'N';
	}

	std::ostream& NonPerishable::write(std::ostream& ostr) const {
		Item::write(ostr);
		if (*this)
		{
			if (m_displayType == 1)
			{
				ostr << "     N / A   |";
			}
			else
			{
				ostr << "=============^" << endl;
			}
	    }
		return ostr;
	}
}