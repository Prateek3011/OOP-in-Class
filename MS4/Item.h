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

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include <fstream>
#include "POS.h"
#include "Error.h"
#include "PosIO.h"
using namespace std;

namespace sdds {
	class Item : public PosIO {
		char m_SKU[MAX_SKU_LEN];
		char* m_Name;
		double m_price;
		bool m_Taxed;
		int m_Quantity;

	protected:
		int m_displayType;
		struct Error m_ErrorState;

	public:
		Item();
		~Item();

		Item(const Item& src);
		Item& operator=(const Item& src);

		bool operator==(const char* sku) const;
		bool operator>(const Item& item) const;
		int operator+=(int qnty);
		int operator-=(int qnty);
		operator bool() const;

		Item& displayType(int type);
		double cost()const;
		int quantity()const;
		Item& clear();

		void setEmpty();
		bool isEmpty() const;

		virtual char itemType()const = 0;

		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);

		std::ostream& bprint(std::ostream& ostr) const;
	};
	double operator+=(double& cost, const Item& item);
}
#endif