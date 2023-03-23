/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	VRVideo.h
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

#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H

#include <iostream>
#include "Video.h"
#include "Media.h"

namespace sdds
{
	class VRVideo : public Video {
		char* m_equipment;

	public:
		VRVideo();
		VRVideo(int length, const char* equipment);
		~VRVideo();

		void setEmpty();
		bool isEmpty() const;

		void load(std::istream& istr);
		std::ostream& play(std::ostream& ostr) const;
	};

}

#endif