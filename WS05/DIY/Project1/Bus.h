/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.h
// Version 1.0
// Date	2023/02.15
// Author Sae-mi Park
// Description
// Tests the Bus module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>

using namespace std;

namespace sdds {

	const double PriceOfBusTicket = 125.34;

	class Bus {
		int m_numOfSeat;
		int m_numOfPassenger;

		void drawBus(int seats, int noOfPassengers, ostream& ostr) const;
		void outOfService();

		//number of seats must be a coefficient of 2 >> (numOfSeat %2 == 0)
		//number of seats must be between 10 and 40 (inclusively) >> 10 <= numOfSeat <= 40
		//the number of passengers should be between 0 and the number of seats. >> 0 <= numOfPassenger <= numOfSeat

	public:
		
		Bus(int seat = 20, int passengers = 0);

		operator bool() const; 
		operator int() const;
		operator double() const;

		bool operator++();
		bool operator++(int);

		bool operator--();
		bool operator--(int);
		
		Bus& operator+=(Bus& right);
		Bus& operator+=(int value);

		Bus& operator=(int value);
		bool operator==(const Bus& right) const;

		ostream& display(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);
	};

	int operator+(int left, const Bus& right);
	
	ostream& operator<<(ostream& ostr, const Bus& right);
	istream& operator>>(istream& istr, Bus& right);
}

#endif