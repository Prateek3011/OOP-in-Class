/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Video.h
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

#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H

#include <iostream>
#include "Media.h"

namespace sdds
{
	class Video : public Media 
	{
		int m_length;
	protected:
		int get() const;	
	public:
		Video();
		Video(int length);
		~Video();

		Video(const Video& src) = delete;
		Video& operator=(const Video& src) = delete;

		void setEmpty();
		void load(std::istream& istr);
	};
}

#endif