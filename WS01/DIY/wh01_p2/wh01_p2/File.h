//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 22, 2023

/***********************************************************************
// OOP244 Workshop 1 p2: File header file
//
// File  File.h
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
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	bool readName(char Name[]);
	bool readStudentNum(int* stno);
	bool readGPA(double* gpa);

}


#endif // !SDDS_GPA_H