/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.cpp
// Version 1.0
// Date	2023/02/13
// Author Sae-mi Park
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "EggCarton.h"

using namespace std;

namespace sdds {

    void EggCarton::setBroken() {
        m_cartonSize = -1;
        m_eggNum = -1;
    }

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
        if (size % 6 == 0 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
        {
            m_cartonSize = size;
            m_eggNum = noOfEggs;
            m_eggSize = jumboSize;
        }
        else
        {
            setBroken();
        }
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const {
        int cartonWidth = size == 6 ? 3 : 6;
            for (int i = 0; i < size; i++) {
                ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
                ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
            }
        return ostr;
    }

    ostream& EggCarton::display(ostream& ostr) const
    {
        if (m_cartonSize % 6 == 0 && m_eggNum >= 0 && m_eggNum <= 36 && m_eggNum <= m_cartonSize) //not broken
        {
            displayCarton(m_cartonSize, m_eggNum, m_eggSize, ostr);
        }
        else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;
    }

    istream& EggCarton::read(istream& istr)
    {
        char sizeInput;

        cin >> sizeInput;
        cin.ignore(10000, ',');

        cin >> m_cartonSize;
        cin.ignore(10000, ',');

        cin >> m_eggNum;
        cin.ignore(10000, '\n');

        if (sizeInput == 'j')
        {
            m_eggSize = false;
        }
        else
        {
            m_eggSize = true;
        }

        if (m_cartonSize % 6 != 0 && m_eggNum < 0 && m_eggNum > 36 && m_eggNum > m_cartonSize)
        {
            setBroken();
        }
        return istr;
    }


    EggCarton& EggCarton::operator++()
    {
        if (m_cartonSize % 6 == 0 && m_eggNum >= 0 && m_eggNum <= 36 && m_eggNum <= m_cartonSize) //not broken
        {
            m_eggNum++;
        }
        else
        {
            setBroken();
        }
        return *this;
    }

    EggCarton EggCarton::operator++(int) //postfix
    {
        EggCarton temp = *this;
            ++(*this);
        return temp;
    }


    EggCarton& EggCarton::operator--() //prefix
    {
        if (m_cartonSize % 6 == 0 && m_eggNum >= 0 && m_eggNum <= m_cartonSize)
        {
            --m_eggNum;
        }
        return *this;
    }

    EggCarton EggCarton::operator--(int) //postfix
    {
        EggCarton temp = *this;
            --(*this);
        return temp;
    }


    EggCarton& EggCarton::operator+=(int value)
    {
        if (m_cartonSize % 6 == 0 && m_eggNum >= 0 && m_eggNum <= m_cartonSize && m_eggNum <= m_cartonSize)
        {
            m_eggNum += value;
                if (m_eggNum > 6)
                {
                    setBroken();
                }
        }
        return *this;
    }

    EggCarton& EggCarton::operator+=(EggCarton& right) ////////////hold
    {
        int capacity = 6 - m_eggNum;
            if (right.m_eggNum <= capacity) {
                m_eggNum += right.m_eggNum;
            }
            else {
                m_eggNum = 6;
                right.m_eggNum -= capacity;
            }
        return *this;
    }

    EggCarton& EggCarton::operator=(int value)
    {
        m_eggNum = value;
            if (m_eggNum > 6 && m_eggNum % 6 != 0)
            {
                setBroken();
            }
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const
    {
        double differ = 0.0;
            differ = this->operator double() - right.operator double();
        return (differ >= -0.001 && differ <= 0.001);
    }

    int operator+(int left, const EggCarton& right)
    {
        int eggNum;
            if (right.operator bool())
            {
                eggNum = (left + right.operator int());
            }
            else
            {
                eggNum = left;
            }
        return eggNum;
    }

    ostream& operator<<(ostream& ostr, const EggCarton& right)
    {
        right.display(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, EggCarton& right)
    {
        right.read(istr);
        return istr;
    }

    EggCarton::operator bool() const //not return
    {
        return (m_cartonSize > 0);
    }

    EggCarton::operator int() const
    {
        return (operator bool() ? m_eggNum : -1);
    }

    EggCarton::operator double() const
    {
        double result;
            if (!operator bool())
            {
                result = -1.0;
            }
            else
            {
                if (m_eggSize == true)
                {
                    result = RegularEggWieght * m_eggNum / 1000.0;
                }
                else
                {
                    result = JumboEggWieght * m_eggNum / 1000.0;
                }
            }
        return result;
    }
}

