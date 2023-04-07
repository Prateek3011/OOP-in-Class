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

#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include <iostream>
#include "Item.h"

namespace sdds {
	class NonPerishable : public Item {
		
	public:
		char itemType()const;

		std::ostream& write(std::ostream& ostr) const;

	};
}
#endif