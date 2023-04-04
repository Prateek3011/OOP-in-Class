// Final Project Milestone 1
// Student POS App Mockup tester
// Version 2.0
// Date	2023-04-02
// Author	Sae-mi Park
// Description
// This program test the student implementation of the PosApp class
// for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "POS.h"
#include "Item.h"
#include "NonPerishable.h"
#include "Perishable.h"

#include <iostream>
namespace sdds {
	class PosApp {
		int nptr;
		char* m_filename;
		Item* Iptr[MAX_NO_ITEMS];
		
	public:
		void setEmpty();

		PosApp();
		PosApp(const char* File);
		~PosApp();

		void run();
		void menu();

		void listItems();
		void addItem();
		void removeItem();
		void stockItem();
		void POS();
		void saveRecs();
		void loadRecs();
		//std::ifstream& loadRecs(std::ifstream& ifstr);
	};

}

#endif // !SDDS_POSAPP_H_
