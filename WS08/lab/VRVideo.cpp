/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	VRVideo.cpp
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
#include <cstring>
#include <string>
//#include "Media.h"
//#include "Video.h"
#include "VRVideo.h"
//#include "Animation.h"
using namespace std;

namespace sdds {

	VRVideo::VRVideo() {
		setEmpty();
	}
	VRVideo::VRVideo(int length, const char* equipment) : Video(length) {
	    setEmpty();

		if (equipment != nullptr && equipment[0] != '\0' && length > -1)
		{
			m_equipment = new char[strlen(equipment) + 1];
			strcpy(m_equipment, equipment);
		}
		else
		{
			setEmpty();
		}
	}
	VRVideo::~VRVideo() {
		delete[] m_equipment;
		m_equipment = nullptr;
	}

	void VRVideo::setEmpty() {
		m_equipment = nullptr;
	}

	void VRVideo::load(std::istream& istr) {
		char temp[10000];
		Video::load(istr);
		
		istr.getline(temp, 1000);
			//>> temp;
		//istr.ignore(1000, '\n');

		if (m_equipment != nullptr)
		{
			delete[] m_equipment;
			m_equipment = nullptr;
		}

		if (temp[0] != '\0')
		{
			m_equipment = new char[strlen(temp) + 1];
			strcpy(m_equipment, temp);
		}
		else
		{
			setEmpty();
		}
		
	}

	bool VRVideo::isEmpty() const {
		return (m_equipment == nullptr || m_equipment[0] == '\0' || Video::get() == 0);
	}

	std::ostream& VRVideo::play(std::ostream& ostr) const {
		if (!isEmpty())
		{
			ostr << "VRVideo requires " << m_equipment << endl;
			ostr << "Video Length = " << Video::get();
		}
		return ostr;
	}

}