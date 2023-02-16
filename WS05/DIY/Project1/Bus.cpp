/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#include "Bus.h"

using namespace std;

namespace sdds {

	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}

	Bus::Bus(int seat, int passengers) {
		if (seat % 2 == 0 && seat >= 10 && seat <= 40 && passengers >= 0 && passengers <= seat)
		{
			m_numOfSeat = seat;
			m_numOfPassenger = passengers;
		}
		else
		{
			outOfService();
		}
	}

	void Bus::outOfService() {
		m_numOfSeat = -1;
		m_numOfPassenger = -1;
	}

	ostream& Bus::display(ostream& ostr) const {
		if (m_numOfSeat >= 10 && m_numOfSeat <= 40 && m_numOfSeat % 2 == 0 && m_numOfPassenger >=0 && m_numOfPassenger <= m_numOfSeat)
		{
			drawBus(m_numOfSeat, m_numOfPassenger, ostr);
			cout << "Total Fare Price: ";
			cout << fixed;
			cout.precision(2);
			cout <<operator double() << endl;
		}
		else
		{
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	istream& Bus::read(istream& istr)
	{
		if (true)
		{
			cin >> m_numOfSeat;
			cin.ignore(10000, ',');

			cin >> m_numOfPassenger;
			cin.ignore(10000, '\n');	

		}
		else
		{
			outOfService();
		}
		return istr;
	}

	Bus::operator bool() const {
		return(m_numOfSeat > 0);
	}

	Bus::operator int() const {
		return (operator bool() ? m_numOfPassenger : -1);
	}

	Bus::operator double() const {
		double fare;
		if (m_numOfPassenger < 0)
		{
			fare = 1.0;
		}
		else
		{
			fare = operator int()* PriceOfBusTicket;
		}
		return fare;
	}

	bool Bus::operator++(){
		bool increase = false;
			if (m_numOfPassenger == m_numOfSeat)
			{
				increase = false;
			}
			else 
			{
				if (m_numOfSeat < 10 && m_numOfSeat > 40 && m_numOfSeat % 2 != 0)
				{
					increase = false;
				}
				else
				{
					increase = true;
					++m_numOfPassenger;
				}
			}
		return increase;

	}

	bool Bus::operator++(int) {
		bool increase = false;
		if (m_numOfPassenger == m_numOfSeat)
		{
			increase = false;
		}
		else
		{
			if (m_numOfSeat < 10 && m_numOfSeat > 40 && m_numOfSeat % 2 != 0)
			{
				increase = false;
			}
			else
			{
				increase = true;
				++m_numOfPassenger;
			}
		}
		return increase;

	}

	bool Bus::operator--() {
		bool reduce = false;
			if (m_numOfPassenger == 0)
			{
				reduce = false;
			}
			else
			{
				if (m_numOfSeat < 10 && m_numOfSeat > 40 && m_numOfSeat % 2 != 0)
				{
					reduce = false;
				}
				else
				{
					reduce = true;
					m_numOfPassenger--;
				}
			}
		return reduce;
	}

	bool Bus::operator--(int) {
		bool reduce;
			if (m_numOfPassenger == 0)
			{
				reduce = false;
			}
			else
			{
				if (m_numOfSeat < 10 && m_numOfSeat > 40 && m_numOfSeat % 2 != 0)
				{
					reduce = false;
				}
				else
				{
					reduce = true;
					m_numOfPassenger--;
				}
			}
		return reduce;
	}

	bool Bus::operator==(const Bus& right) const
	{
		bool same = false;
			if (operator bool() && this->m_numOfPassenger == right.m_numOfPassenger)
			{
				same = true;
			}
			else 
			{
				same = false;
			}
		return same;
	}

	int operator+(int left, const Bus& right)
	{
		int passengers;
			if (right.operator bool())
			{
				passengers = left + right.operator int();
			}
			else
			{
				passengers = left;
			}
		return passengers;
	}

	Bus& Bus::operator=(int value)
	{
		if (m_numOfSeat >= 10 && m_numOfSeat <= 40 && m_numOfSeat % 2 == 0 && m_numOfPassenger >= 0 && m_numOfPassenger <= m_numOfSeat)
		{
			m_numOfPassenger = value;

			if (m_numOfPassenger > m_numOfSeat)
			{
				outOfService();
			}
		}
		return *this;
	}

	Bus& Bus::operator+=(int value)
	{
		if (m_numOfSeat >= 10 && m_numOfSeat <= 40 && m_numOfSeat % 2 == 0 && m_numOfPassenger >= 0 && m_numOfPassenger <= m_numOfSeat)
		{
			m_numOfPassenger += value;

				if (m_numOfPassenger > m_numOfSeat)
				{
					outOfService();
				}
		}
		return *this;
	}

	Bus& Bus::operator+=(Bus& right)
	{
		int capacity = m_numOfSeat - m_numOfPassenger;
			if (capacity > 0) 
			{
				m_numOfPassenger = m_numOfSeat; 
				right.m_numOfPassenger -= capacity;
			}
			else 
			{
				m_numOfPassenger += right.m_numOfPassenger;
			}
		return *this;
	}


	ostream& operator<<(ostream& ostr, const Bus& right)
	{
		right.display(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Bus& right)
	{
		right.read(istr);
		return istr;
	}
}