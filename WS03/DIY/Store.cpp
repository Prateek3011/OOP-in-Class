//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 1, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Store.h"
#include "Toys.h"

using namespace std;

namespace sdds {


	//Setting store name and number of toys
	//store name shold be less than MAX_SNAME
	void Store::setStore(const char* sName, int no) {

		m_noOfToys = no;

		if (sName != nullptr && sName[0] != '\0')
		{
			strcpy(m_sName, sName);
			m_addToys = 0;
		}
		else
		{
			setEmpty();
		}

	}

	//add list of the toys as m_noOfToys
	void Store::setToys(const char* tname, int sku, double price, int age) {

		m_toy[m_addToys].addToys(tname, sku, price, age);
		m_addToys++;

	}


	void Store::display() const {


		cout.fill('*');
		cout.width(60);
		cout << "*" << endl;


		cout.width(4);
		cout << m_sName;

		cout.width(4);
		cout << endl;

		cout.width(60);
		cout << "*" << endl;
		cout.fill(' ');
		cout << "list of the toys" << endl;

		cout.width(30);
		cout.setf(ios::right);
		cout << "SKU";

		cout.width(10);
		cout << "Age";

		cout.width(11);
		cout << "Price";

		cout.width(10);
		cout << "Sale";
		cout << endl;


		for (int i = 0; i < m_noOfToys; i++)
		{
		
			if (!m_toy[i].checkValid())
			{
				cout << "Toy[" << i + 1 << "] :" << "Invalid Toy" << endl;
			}
			else
			{
				cout << "Toy[" << i + 1 << "] :";
				m_toy[i].display();
			}
		}
	}


	void Store::find(int sku) {
		bool found = false;

		for (int i = 0; !found && i < m_noOfToys; i++)
		{
			found = m_toy[i].skumatch(sku);
			if (found) {
				
				m_toy[i].calSale();
				m_toy[i].isSale(found);
			}
		}
	}

	void Store::setEmpty() {

		for (int i = 0; i < MAX_SNAME; i++)
		{
			m_sName[i] = '\0';
		}

		m_noOfToys = 0;
		m_addToys = 0;
		
		for (int i = 0; i < MAX_NUM_TOYS; i++)
		{
			m_toy[i].isEmpty();
		}
	}

	
}
