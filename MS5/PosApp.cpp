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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include "PosApp.h"
#include "POS.h"
#include "Item.h"
#include "Utils.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Bill.h"

using namespace std;

namespace sdds {

	void PosApp::setEmpty() {
		m_filename = nullptr;
		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			Iptr[i] = nullptr;
		}
		nptr = 0;
	}

	PosApp::PosApp() {
		setEmpty();
	}

	PosApp::PosApp(const char* File) {
		setEmpty();
		delete[] m_filename;
		m_filename = new char[strlen(File) + 1];
		strcpy(m_filename, File);
	}

	PosApp::~PosApp() {
		delete[] m_filename;
		m_filename = nullptr;

		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			delete Iptr[i];
			Iptr[i] = nullptr;
		}
	}

	void PosApp::run() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Loading Items" << endl;
		//cout << "Loading data from " << m_filename << endl;
		loadRecs();
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
			cout << "5- POS" << endl;
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
		double total = 0.0;
	
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Listing Items" << endl;

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
		
		//loadRecs();
		bubble(Iptr, nptr);
		
		for (int i = 0; i < nptr; i++) {
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);
			cout << i + 1 << " | ";
			cout.unsetf(ios::right);
			Iptr[i]->write(cout);
			total += Iptr[i]->cost() * Iptr[i]->quantity();
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "                               Total Asset: $  |";
		cout.setf(ios::right);
		cout.width(14);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << total << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl << endl;
		cout.unsetf(ios::right);

	}
	void PosApp::addItem() {
		bool done = false;
		char typeInput;
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Adding Item to the store" << endl;
		if (nptr == MAX_NO_ITEMS)
		{
			cout << "Inventory Full!";
		}
		else
		{
			Iptr[nptr] = nullptr;


			while (!done)
			{
				cout << "Is the Item perishable? (Y)es/(N)o: ";
				cin >> typeInput;
				cin.ignore();
				if (typeInput == 'y' || typeInput == 'Y')
				{
					Iptr[nptr] = new Perishable();
					Iptr[nptr]->displayType(1);
					Iptr[nptr]->read(cin);
					nptr++;
					done = true;
				}
				else if (typeInput == 'n' || typeInput == 'N')
				{
					Iptr[nptr] = new NonPerishable();
					Iptr[nptr]->displayType(1);
					Iptr[nptr]->read(cin);
					nptr++;
					done = true;
				}
				else
				{
					cin.clear();
					done = false;
				}
			}
			/*if (Iptr[nptr]->isEmpty())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << Iptr[nptr] << ", try agian..." << endl;
			}*/
		}
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> DONE!" << endl;
	}

	int PosApp::selectItem() {
		int rowNum = 0;
		bool valid = false;

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Item Selection by row number"<<endl;
		
		cin.ignore(10000, '\n');
		pause();

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Listing Items" << endl;

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

		bubble(Iptr, nptr);

		for (int i = 0; i < nptr; i++) {
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);
			cout << i + 1 << " | ";
			cout.unsetf(ios::right);
			Iptr[i]->write(cout);
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "Enter the row number: ";
		while (!valid)
		{
			cin >> rowNum;

			if (!cin)
			{
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				valid = false;
			}
			else
			{
				if (rowNum < 1 || rowNum > nptr)
				{
					cout << "[1<=value<=26], retry: Enter the row number: ";
					cin.clear();
					cin.ignore(1000, '\n');
					valid = false;
				}
				else
				{
					valid = true;
				}
			}
			cin.clear();
		}
		return rowNum;
	}

	void PosApp::removeItem() {
		int selectNum = 0;

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Remove Item" << endl;

		selectNum = selectItem() - 1; // rownum | index = -1
		Iptr[selectNum]->displayType(2);
		cout << "Removing...." << endl;
		Iptr[selectNum]->write(cout);

		delete Iptr[selectNum];

		for (int i = selectNum; i < nptr; i++)
		{
			Iptr[i] = Iptr[i+1];
		}
		nptr -= 1;
		delete Iptr[nptr];
		Iptr[nptr] = nullptr;

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> DONE!" << endl;
		
	}
	void PosApp::stockItem() {
		int selectNum = 0, quntity = 0;
		bool valid = false;
		
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Select an item to stock" << endl;

		selectNum = selectItem() - 1; // rownum | index = -1
		Iptr[selectNum]->displayType(2);
		cout << "Selected Item:" << endl;
		Iptr[selectNum]->write(cout);

		cout << "Enter quantity to add: ";
		while (!valid)
		{
			cin >> quntity;

			if (!cin)
			{
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				valid = false;
			}
			else
			{
				if (quntity < 1 || quntity > 69)
				{
					cout << "[1<=value<=69], retry: Enter quantity to add: ";
					cin.clear();
					cin.ignore(1000, '\n');
					valid = false;
				}
				else
				{
					valid = true;
				}
			}
			cin.clear();
		}
		Iptr[selectNum]->operator+=(quntity);

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> DONE!" << endl;
	}
	void PosApp::POS() {
		char input[1000];
		bool done = false;
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Starting Point of Sale" << endl;

		Bill nowBill;

		cin.ignore(10000, '\n');
		while (!done)
		{
			cout << "Enter SKU or <ENTER> only to end sale..." << endl;
			cout << "> ";
			
			cin.getline(input, MAX_SKU_LEN+1);

			if (input[0] != '\0')
			{
				Item* found = &search(input);
				//*Iptr = &search(input);
				
				if (found == nullptr)
				{
					cout << "!!!!! Item Not Found !!!!!" << endl;
					done = false;
				}
				else
				{
					if (found->quantity() > 0)
					{
						found->operator-=(1);
						found->displayType(2);
						found->write(cout);
						cout << endl;

						cout << ">>>>> Added to bill" << endl;
						nowBill.add(found);
						cout << ">>>>> Total: " << nowBill.total() << endl;

						done = false;
					}
					else
					{

						cout << "Item out of stock" << endl;

						done = false;
					}
				}
			}
			else
			{
				done = true;
				//cin.clear();
			}
		}
		nowBill.print(cout);
		cout.unsetf(ios::right);
	}

	Item& PosApp::search(const char* sku) {

		for (int i = 0; i < nptr; i++)
		{
			if (Iptr[i]->operator==(sku))
			{
				if (Iptr[i]->quantity() >= 0)
				{
					//Iptr[i]->operator-=(1);
					return *Iptr[i];
				}
			}
		}
		return *Iptr[nptr];
	}

	void PosApp::saveRecs() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Saving Data" << endl;
		//cout << "Saving data in " << m_filename << endl;
		ofstream output(m_filename);
		output.setf(ios::fixed);
		output.precision(2);

		if (!output.fail())
		{
			for (int i = 0; i < nptr; i++)
			{
				Iptr[i]->save(output);
			}
		}
		cout << "Goodbye!" << endl;
	}
	void PosApp::loadRecs() {
		ifstream input(m_filename);
		if (!input) {
			ofstream file(m_filename);
			file.close();
			input.open(m_filename);
		}
		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			Iptr[i] = nullptr;
		}
		nptr = 0;
		if (!input.fail())
		{
			for (int i = 0;  input.good() && i < MAX_NO_ITEMS; i++) {
				char itemType;
				input >> itemType;
				input.ignore();
				
				if (itemType == 'N') 
				{
					Iptr[i] = new NonPerishable();
					Iptr[i]->load(input);
					Iptr[i]->displayType(1);
				}
				else
				{
					Iptr[i] = new Perishable();
					Iptr[i]->load(input);
					Iptr[i]->displayType(1);
				}

				if (!Iptr[i]->isEmpty())
				{
					nptr++;
				}
				else
				{
					delete Iptr[i];
					Iptr[i] = nullptr;
					i = MAX_NO_ITEMS;
				}
			}
			input.close();
		}
	}
}