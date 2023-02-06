//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 1, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Toys.h"
//#include "Store.h"

using namespace std;

namespace sdds {
	

	void Toys::addToys(const char* tname, int sku, double price, int age) {
		

		string str1(to_string(sku));

		if (tname != nullptr && tname[0] != '\0' && str1.size() == 8)
		{
			strcpy(m_tname, tname);
			m_sku = sku;
			m_age = age;
			m_price = price;
			m_onSale = false;
		}
		else
		{
			isEmpty();
		}
	}


	void Toys::isSale(bool sale) {
		m_onSale = sale;
	}


	void Toys::calSale() {
		m_price = m_price*0.8;
	}


	void Toys::display() const {
		
		cout.width(15);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout << m_tname;
		
		cout.unsetf(ios::left);
		cout.width(10);
		cout << m_sku;
		
		cout.width(6);
		cout << m_age;
		
		cout.setf(ios::fixed);
		cout.width(12);
		cout.precision(2);
		cout << m_price;
		
		if (m_onSale == true)
		{
			cout.width(10);
			cout <<"On Sale";
			cout << " ";
		}
		else{
			cout.width(8);
			cout << " ";
		}
		cout << endl;
	}


	bool Toys::skumatch(int sku) {
		bool found = true;

		if (m_sku == sku)
		{
			found = true;
		}
		else
		{
			found = false;
		}
		return found;
	}
	

	bool Toys::checkValid()const {
		
		return (m_sku != 0) ? true : false;
	}

	void Toys::isEmpty() {
		for (int i = 0; i < MAX_TNAME; i++)
		{
			m_tname[i] = '\0';
		}

		m_sku = 0;
		m_age = 0;
		m_price = 0.0;
		m_onSale = false;
	}

}