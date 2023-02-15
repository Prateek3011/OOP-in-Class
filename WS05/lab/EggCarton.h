/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.h
// Version 1.0
// Date	2023/02/13
// Author Sae-mi Park
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>

using namespace std;

namespace sdds {

	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

	class EggCarton {
		int m_cartonSize;
		int m_eggNum;
		bool m_eggSize;

		ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const;
		void setBroken();

	public:

		//defalt value // essential front , back side can be eleminate
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

		istream& read(istream& istr = cin);
		ostream& display(ostream& ostr = cout) const;

		EggCarton& operator++(); //prefix
		EggCarton operator++(int); //postfix

		EggCarton& operator--(); //prefix
		EggCarton operator--(int); //postfix

		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		
		EggCarton& operator=(int value);

		bool operator==(const EggCarton& right) const;

		operator bool() const; //not return
		operator int() const;
		operator double() const;

	};
		int operator+(int left, const EggCarton& right);

		ostream& operator<<(ostream& ostr, const EggCarton& right);
		istream& operator>>(istream& istr, EggCarton& right);
}
#endif
