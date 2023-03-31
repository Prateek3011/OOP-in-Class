/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.h
// Version 1.0
// Date	Winter of 2023
// Author	Sae-mi Park
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include <iostream>
#include "Person.h"
using namespace std;

namespace sdds {
	class Contact : public Person {
		char* m_address{};
		char* m_city{};
		char m_province[2];
		char m_postCode[6];

	public :
		Contact();
		~Contact();

		Contact(const Contact& src);
		Contact& operator=(const Contact& src);

		void setEmpty();

		operator bool()const;
		void operator~();

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

	};


}
#endif