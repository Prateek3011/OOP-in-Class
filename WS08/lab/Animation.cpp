/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Animation.cpp
// Version 1.0
// Date	   fMar 20, 2023
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
//#include "Media.h"
//#include "Video.h"
//#include "VRVideo.h"
#include "Animation.h"
using namespace std;

namespace sdds {

	Animation::Animation() {
		setEmpty();
	}
	Animation::Animation(int length, int dimension) : Video(length) {
		if (dimension == 2 || dimension == 3)
		{
			m_dimension = dimension;
		}
		else
		{
			setEmpty();
		}
	}
	void Animation::setEmpty() {
		m_dimension = 0;
	}
	void Animation::load(std::istream& istr) {
		int temp = 0;
		Video::load(istr);
		istr >> temp;
		istr.ignore(10000, '\n');
		
		if (temp == 2 || temp == 3)
		{
			m_dimension = temp;
		}
		else
		{
			setEmpty();
		}
	}
	bool Animation::isEmpty() const {
		return (Video::get() == 0 ||( m_dimension != 2 && m_dimension != 3));
	}
	std::ostream& Animation::play(std::ostream& ostr) const {
		if (!isEmpty())
		{
			ostr << "Animation is in " << m_dimension << "-D" << endl;
			ostr << "Video Length = " << Video::get();
		}
		return ostr;
	}
}