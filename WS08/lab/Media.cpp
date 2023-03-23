/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Media.cpp
// Version 1.0
// Date	   Mar 20, 2023
// Author	Sae-mi Park
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2023-03-19      Revision, correction
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Media.h"
//#include "Video.h"
//#include "VRVideo.h"
//#include "Animation.h"
using namespace std;

namespace sdds {
	Media::~Media() {

	}

	/*std::ostream& Media::play(std::ostream& ostr)const {
		return ostr;
	}

	void Media::load(std::istream& istr) {
		
	}*/

	std::ostream& operator<<(std::ostream& ostr, const Media& media) {
		return media.play(ostr);
	}

	std::istream& operator>>(std::istream& istr, Media& media) {
		media.load(istr);
		return istr;
	}
}