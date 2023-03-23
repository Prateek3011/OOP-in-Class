/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Media.h
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

#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H

#include <iostream>
using namespace std;
namespace sdds
{
	class Media 
	{
	public:		
		virtual ~Media();
		virtual std::ostream& play(std::ostream& ostr) const = 0;
		virtual void load(std::istream& istr) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const Media& media);
	std::istream& operator>>(std::istream& istr, Media& media);
}

#endif