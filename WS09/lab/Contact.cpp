/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.cpp
// Version 1.0
// Data	Winter of 2023
// Author	Sae-mi Park
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include "Contact.h"
#include "Tools.h"
#include "Person.h"

using namespace std;

namespace sdds {

	Contact::Contact(){
		setEmpty();
	}
	Contact::~Contact() {
		delete[] m_address;
		m_address = nullptr;

		delete[] m_city;
		m_city = nullptr;
	}

	Contact::Contact(const Contact& src){
		Person::operator~();
		setEmpty();
		if (this != &src)
		{
			Person::operator=(src);
			delete[] m_address;
			delete[] m_city;

			if (src.m_address != nullptr && src.m_city)
			{
				m_address = new char[strLen(src.m_address) + 1];
				strCpy(m_address, src.m_address);
				m_city = new char[strLen(src.m_city) + 1];
				strCpy(m_city, src.m_city);
				strCpy(m_province, src.m_province);
				strCpy(m_postCode, src.m_postCode);
			}
			else
			{
				m_address = nullptr;
				m_city = nullptr;
			}
		}
	}
	Contact& Contact::operator=(const Contact& src) {
		Person::operator~();
		Person::operator=(src);
		delete[] m_address;
		delete[] m_city;
		if (src.m_address != nullptr && src.m_city)
		{
			m_address = new char[strLen(src.m_address) + 1];
			strCpy(m_address, src.m_address);
			m_city = new char[strLen(src.m_city) + 1];
			strCpy(m_city, src.m_city);

			strCpy(m_province, src.m_province);
			strCpy(m_postCode, src.m_postCode);
		}
		return *this;
	}

	void Contact::setEmpty() {
		m_address = nullptr;
		m_city = nullptr;
		m_province[2] = { '\0' };
		m_postCode[6] = { '\0' };
	}
	
	Contact::operator bool()const {
		return m_address && m_address[0] && m_city && m_city[0];
	}

	void Contact::operator~() {
		delete[] m_address;
		delete[] m_city;
		m_address = m_city  = nullptr;
	}

	std::istream& Contact::read(std::istream& istr) {
		string str = "";
		Person::operator~();
		if (!istr.fail())
		{
			//~*this;
			Person::read(istr);
			m_address = dynRead(istr, ',');
			m_city = dynRead(istr, ',');
		
			istr.getline(m_province,3,',');
			istr.getline(m_postCode,7, '\n');			
		}
		if (istr.fail()) ~*this;
		return istr;
	}
	std::ostream& Contact::write(std::ostream& ostr) const {
		string str;
		if (m_address != nullptr && m_address[0] != '\0' && m_city != nullptr && m_city[0] != '\0')
		{
			Person::write(ostr) << endl;
			ostr << m_address << endl;
			ostr << m_city << " " << m_province[0] << m_province[1] << endl; // need correction
			
			str = m_postCode;
			str = str.insert(3, " ");
			ostr << str << endl;
		}
		return ostr;
	}
	
}