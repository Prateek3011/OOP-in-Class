/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Video.cpp
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
//#include "Media.h"
#include "Video.h"
//#include "VRVideo.h"
//#include "Animation.h"
using namespace std;

namespace sdds {

	int Video::get() const {
		return m_length;
	}
	Video::Video() {
		setEmpty();
	}
	Video::Video(int length) {
		if (length < 0)
		{
			setEmpty();
		}
		else
		{
			m_length = length;
		}
	}
	/*Video::Video(const Video& src)	{

	}*/

	void Video::setEmpty() {
		m_length = 0;
	}

	/*Video& Video::operator=(const Video& src){

	}*/

	void Video::load(std::istream& istr) {
		istr >> m_length;
		istr.ignore(10000, ',');
	}

	Video::~Video() {

	}
}