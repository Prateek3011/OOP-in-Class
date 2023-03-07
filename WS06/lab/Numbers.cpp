/***********************************************************************
// OOP244 Workshop 6 Part1: Classes with Resource
// File Numbers.cpp
// Version 1.0
// Date	Feb 25, 2023
// Author Sae-mi Park
// Description
// Tests Numbers module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Numbers.h"
using namespace std;
namespace sdds {
   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

   void Numbers::setEmpty() {
       m_Collection = nullptr;
       m_filename = nullptr;
       m_CollectionSize = 0;
       m_originalFlag = false;
       m_addedFlag = false;
   }

   bool Numbers::load() {
      int lineNum = 0, loadnum = 0;
      double temp = 0.0;
      bool done = false;

      delete[] m_Collection;
      lineNum = countLines(m_filename);

           if (lineNum > 0) 
           {
               m_Collection = new double[lineNum];
               ifstream file(m_filename);
               if (file.is_open())
               {
                   for (int i = 0; i < lineNum; i++)
                   {
                       if (file >> temp)
                       {
                           m_Collection[i] = temp;
                           loadnum = i+1;
                       }
                   }
                   if (loadnum != lineNum)
                   {
                       delete[] m_Collection;
                       delete[] m_filename;
                       setEmpty();
                   }
                   else
                   {
                       m_CollectionSize = lineNum;
                       m_originalFlag = true;
                       done = true;
                   }
               }

           }

       return done;
   }

   void Numbers::save() {

       if (m_originalFlag && m_addedFlag)
       {
           ofstream file(m_filename);
           file.setf(ios::fixed);
           file.precision(2);

           for (unsigned int i = 0; i < m_CollectionSize; i++)
           {
               file << m_Collection[i] << endl;
           }
       }
   }


   double Numbers::max() const {
       double max = 0.0;
       if (!isEmpty())
       {
           max = m_Collection[0];

           for (unsigned int i = 0; i < m_CollectionSize; i++)
           {
               if (max < m_Collection[i])
               {
                   max = m_Collection[i];
               }
           }
       }
       return max;
   }

   double Numbers::min() const {
       double min = 0.0;
       if (!isEmpty())
       {
           min = m_Collection[0];

           for (unsigned int i = 0; i < m_CollectionSize; i++)
           {
               if (min > m_Collection[i])
               {
                   min = m_Collection[i];
               }
           }
       }
       return min;
   }

   double Numbers::average() const {
       double temp = 0.0;

       if (!isEmpty())
       {
           for (unsigned int i = 0; i < m_CollectionSize; i++)
           {
               temp += m_Collection[i];
           }

           temp = temp / m_CollectionSize;
       }
       return temp;
   }

   bool Numbers::isEmpty() const {
       return m_Collection == nullptr;
   }

   Numbers::operator bool() const //not return
   {
       return (m_Collection != nullptr);
   }
   
   
   void Numbers::sort() {
       sort(m_Collection, m_CollectionSize); 
   }

   Numbers& Numbers::operator+=(double num) {
       if (!isEmpty())
       {
           double* temp = nullptr;
           temp = new double[m_CollectionSize + 1];

               for (unsigned int i = 0; i < m_CollectionSize; i++)
               {
                   temp[i] = m_Collection[i];
               }

           temp[m_CollectionSize] = num;
           m_CollectionSize++;

           delete[] m_Collection;
           m_Collection = temp;
           m_addedFlag = true;
       }
       return *this;
   }

   Numbers& Numbers::operator=(const Numbers& src) {     
    if (this != &src)
    {
          save();

          delete[] m_Collection;
          delete[] m_filename;

           m_CollectionSize = src.m_CollectionSize;
           m_originalFlag = false;
           m_addedFlag = true;
           if (src.m_Collection != nullptr && src.m_filename != nullptr)
           {
               m_filename = new char[strlen(src.m_filename) + 1];
               strcpy(m_filename, src.m_filename);

               m_Collection = new double[m_CollectionSize];

                   for (unsigned int i = 0; i < m_CollectionSize; i++)
                   {
                       m_Collection[i] = src.m_Collection[i];
                   }
           }
           else
           {
               m_Collection = nullptr;
               m_filename = nullptr;
           }
    }
       return *this;
   }

   Numbers::Numbers() {
       setEmpty();
   }

   Numbers::Numbers(const char* file) {
       
       setEmpty();
       m_originalFlag = true;
       delete[] m_filename;
       m_filename = new char[strlen(file) + 1];
       strcpy(m_filename, file);

       load();

   }

   Numbers::Numbers(const Numbers& src) {
        setEmpty();
        *this = src;
   }

   Numbers::~Numbers() {
       save();

       delete[] m_Collection;
       delete[] m_filename;
   }

   std::ostream& Numbers::display(std::ostream& ostr) const {
       
       if (isEmpty() || m_Collection == nullptr)
       {
           ostr << "Empty list";
       }
       else
       {
           ostr.setf(ios::fixed);
           ostr.precision(2);

           if (!m_originalFlag)
           {
               ostr << "Copy of " << m_filename << endl;
               for (unsigned int i = 0; i < m_CollectionSize; i++)
               {
                   ostr << m_Collection[i];
                   if (i == m_CollectionSize - 1)
                   {
                       ostr << endl;
                   }
                   else
                   {
                       ostr << ", ";
                   }
               }
           }
           else
           {
               ostr << m_filename << endl;
               for (unsigned int i = 0; i < m_CollectionSize; i++)
               {
                   ostr << m_Collection[i];
                   if (i == m_CollectionSize - 1)
                   {
                       ostr << endl;
                   }
                   else
                   {
                       ostr << ", ";
                   }
               }
           }

           for (int i = 0; i < 76; i++)
           {
               ostr << "-";
           }
           ostr << endl;
           ostr << "Total of " << m_CollectionSize << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
           for (int i = 0; i < 76; i++)
           {
               ostr << "=";
           }
       }
       return ostr;
   }

   std::ostream& operator<<(std::ostream& ostr, const Numbers& num) {
       return num.display(ostr);
   }

   std::istream& operator>>(std::istream& istr, Numbers& num) {
       double temp = 0.0;
       istr >> temp;
       num += temp;
       return istr;
   }

}