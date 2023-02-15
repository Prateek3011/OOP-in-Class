//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 13, 2023


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#include "Bus.h"

using namespace std;

namespace sdds {

	voiddrawBus(int seats, int noOfPassengers, ostream& ostr) const {
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





	Bus::Bus() {
		numOfSeat = 20;
		numOfPassenger = 0;
	}


}