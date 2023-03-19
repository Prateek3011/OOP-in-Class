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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "POS.h"
#include "Error.h"
#include "Utils.h"
using namespace std;

namespace sdds{

	Error::Error() {
		setEmpty();
	}

	Error::Error(const char* errMsg) {
		setEmpty();
	 	delete[]  m_errMsg;

		m_errMsg = new char[strlen(errMsg) + 1];
		strcpy(m_errMsg, errMsg);
	}

	Error::~Error() {
		delete[]  m_errMsg;
		m_errMsg = nullptr;
	}

	void Error::clear() {
		delete[]  m_errMsg;
		setEmpty();
	}

	void Error::setEmpty() {
		m_errMsg = nullptr;
	}

	Error::operator bool() const
	{
		return (m_errMsg != nullptr);
	}

	Error& Error::operator=(const Error& src) {
		if (this != &src)
		{
			delete[] m_errMsg;

			if (src.m_errMsg != nullptr)
			{
				m_errMsg = new char[strlen(src.m_errMsg) + 1];
				strcpy(m_errMsg, src.m_errMsg);
			}
			else
			{
				m_errMsg = nullptr;
			}
		}
		return *this;
	}
	Error::Error(const Error& src) {
		setEmpty();
		*this = src;
	}

	std::ostream& Error::display(std::ostream& ostr) const {
		
		if (m_errMsg != nullptr)
		{
			ostr << m_errMsg;
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Error& num) {
		return num.display(ostr);
	}
}