// Final Project Milestone 1
// Student POS App Mockup tester
// Version 1.0
// Date	2023-03-05
// Author	Sae-mi Park
// Description
// This program test the student implementation of the PosApp class
// for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include <iostream>
namespace sdds {
	class PosApp {
		char* m_filename;



	public:
		void setEmpty();

		PosApp();
		PosApp(const char* file);
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
	};

}

#endif // !SDDS_POSAPP_H_
