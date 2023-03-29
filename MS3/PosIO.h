// Final Project 
// Student PosIO.h
// Version 1.0
// Date	2023-03-26
// Author	Sae-mi Park
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds {
	class PosIO {

	public:
		virtual ~PosIO();
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const PosIO& io);
	std::istream& operator>>(std::istream& istr, PosIO& io);
	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& io);
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& io);
}
#endif