// Final Project Milestone 2
// 
// Version 1.0
// Date	2023-03- 15
// Author	Sae-mi Park
// Description
// This program test the student implementation of the Error and
// the Date class for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
	struct Error {

		char* m_errMsg;

	public:

		Error();
		Error(const char* errMsg);
		~Error();

		void clear();
		void setEmpty();
		
		operator bool() const;

		Error& operator=(const Error& src);
		Error(const Error& src);

		std::ostream& display(std::ostream& ostr = std::cout) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Error& num);
}
#endif