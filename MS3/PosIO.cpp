// Final Project 
// Student PosIO cpp 
// Version 1.0
// Date	2023-03-26
// Author	Sae-mi Park
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "PosIO.h"

using namespace std;
namespace sdds {
	PosIO::~PosIO() {
	}
	std::ostream& operator<<(std::ostream& ostr, const PosIO& io) {
		return io.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, PosIO& io) {
		return io.read(istr);
	}
	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& io) {
		return io.save(ofstr);
	}
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& io) {
		return io.load(ifstr);
	}
}