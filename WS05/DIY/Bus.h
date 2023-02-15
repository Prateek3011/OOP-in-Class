//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 13, 2023

#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>

using namespace std;

namespace sdds {

	const double PriceOfBusTicket = 125.34;

	class Bus {
		int numOfSeat;
		int numOfPassenger;

		void drawBus(int seats, int noOfPassengers, ostream& ostr) const;

		//number of seats must be a coefficient of 2 >> (numOfSeat %2 == 0)
		//number of seats must be between 10 and 40 (inclusively) >> 10 <= numOfSeat <= 40
		//the number of passengers should be between 0 and the number of seats. >> 0 <= numOfPassenger <= numOfSeat
	public:

		Bus();
	};
}

#endif