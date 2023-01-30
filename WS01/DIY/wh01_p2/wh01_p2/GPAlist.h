//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 22, 2023

/***********************************************************************
// OOP244 Workshop 1 p2: File header file
//
// File  UI.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H


namespace sdds {

	bool gpaQuery(const char* filename);
	void sorting(struct GPA* gpas, int num);
	bool findGPA(const struct GPA* gpas, const char char_temp, const double inputGPA);
	void displayGPA(const struct GPA* gpas);
	void displayGPAwithinformation(const char char_temp, const double inputGPA);

}

#endif 
