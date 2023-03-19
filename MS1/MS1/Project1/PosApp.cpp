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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include "PosApp.h"
using namespace std;

namespace sdds {

	void PosApp::setEmpty() {
		m_filename = nullptr;
	}

	PosApp::PosApp() {
		m_filename = nullptr;
	}

	PosApp::PosApp(const char* file) {
		setEmpty();
		delete[] m_filename;
		m_filename = new char[strlen(file) + 1];
		strcpy(m_filename, file);

	}

	PosApp::~PosApp() {
		delete[] m_filename;
		m_filename = nullptr;
	}

	void PosApp::run() {
		cout << ">>>> Loading Items..........................................................." << endl;
		cout << "Loading data from " << m_filename << endl;
		menu();
	}

	void PosApp::menu() {
		int input;
		bool done = false, exit = false;

		while (!exit)
		{
			cout << "The Sene-Store" << endl;
			cout << "1- List items" << endl;
			cout << "2- Add item" << endl;
			cout << "3- Remove item" << endl;
			cout << "4- Stock item" << endl;
			cout << "5- Point of Sale" << endl;
			cout << "0- exit program" << endl;
			cout << "> ";

			done = false;
			while (!done)
			{
				cin >> input;

				if (!cin)
				{
					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(100000, '\n');
					done = false;
					exit = false;
				}
				else
				{
					if (input < 0 || input > 5)
					{
						cout << "[0<=value<=5], retry: > ";
						cin.clear();
						cin.ignore(100000, '\n');
						done = false;
						exit = false;
					}
					else
					{
						switch (input)
						{
						case 1:
							listItems();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							//exit = false;
							break;

						case 2:
							addItem();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 3:
							removeItem();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 4:
							stockItem();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 5:
							POS();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 0:
							saveRecs();
							
							cin.clear();
							cin.ignore(100000, '\n');
							exit = true;
							break;
						}
						done = true;
					}
				}
			}
		}

	}
	void PosApp::listItems() {
		cout << ">>>> Listing Items..........................................................." << endl;
		cout << "Running listItems()" << endl;
	}
	void PosApp::addItem() {
		cout << ">>>> Adding Item to the store................................................" << endl;
		cout << "Running addItem()" << endl;
	}
	void PosApp::removeItem() {
		cout << ">>>> Remove Item............................................................." << endl;
		cout << "Running removeItem()" << endl;
	}
	void PosApp::stockItem() {
		cout << ">>>> Select an item to stock................................................." << endl;
		cout << "Running stockItem()" << endl;
	}
	void PosApp::POS() {
		cout << ">>>> Starting Point of Sale.................................................." << endl;
		cout << "Running POS()" << endl;
	}
	void PosApp::saveRecs() {
		cout << ">>>> Saving Data............................................................." << endl;
		cout << "Saving data in " << m_filename << endl;
		cout << "Goodbye!" << endl;
	}
	void PosApp::loadRecs() {

	}

}