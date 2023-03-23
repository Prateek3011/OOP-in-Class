/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Animation.h
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

#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H

#include <iostream>
#include "Video.h"
#include "Media.h"

namespace sdds
{
	class Animation : public Video {
		int m_dimension;

	public:

		Animation();
		Animation(int length, int dimension);

		void setEmpty();
		bool isEmpty() const;

		void load(std::istream& istr);
		std::ostream& play(std::ostream& ostr) const;
		
		/*std::ostream& play(std::ostream& ostr);
		std::istream& load(std::istream& istr);*/
	};

}

#endif