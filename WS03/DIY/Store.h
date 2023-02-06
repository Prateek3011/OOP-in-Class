//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 1, 2023

#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_
#include "Toys.h"

namespace sdds {

	const int MAX_NUM_TOYS = 10;
	const int MAX_SNAME = 31;

	class Store {
		char m_sName[MAX_SNAME];
		int m_noOfToys;
		int m_addToys;
		Toys m_toy[MAX_NUM_TOYS];

	public:
		
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		void setEmpty();
		
	};

}
#endif