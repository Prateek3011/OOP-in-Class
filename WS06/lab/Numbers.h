/***********************************************************************
// OOP244 Workshop 6 Part1: Classes with Resource
// File Numbers.h
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

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      unsigned int countLines(const char* filename);
      void sort(double* collectionPtr, unsigned int size);

      double* m_Collection;//array
      char* m_filename;//cString
      unsigned int m_CollectionSize;//int
      bool m_originalFlag;//bool
      bool m_addedFlag;//bool

      void setEmpty();
      bool load();
      void save();
      double max() const;
      double min() const;
      double average() const;
      bool isEmpty() const;

   public:

       operator bool() const;
       void sort();

       Numbers& operator+=(double num);
       Numbers& operator=(const Numbers& src); // copy

       Numbers();
       Numbers(const char* file); 
       Numbers(const Numbers& src); //copy
       ~Numbers();

       std::ostream& display(std::ostream& ostr = std::cout) const;
      // std::ostream& read(std::istream& istr);
   };

   std::ostream& operator<<(std::ostream& ostr, const Numbers& num);
   std::istream& operator>>(std::istream& istr, Numbers& num);
}
#endif // !SDDS_NUMBERS_H_

