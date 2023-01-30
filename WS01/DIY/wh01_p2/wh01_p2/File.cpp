//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 22, 2023

/***********************************************************************
// Workshop 1 p2: tester program
//
// File  file.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "File.h"
#include "GPA.h"
//#include "GPAlist.h"
//#include "UI.h"


using namespace std;

namespace sdds {

    FILE* fptr;
    //GPA gpas[100];

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // returns true if successful
    bool readName(char Name[]) {
        return fscanf(fptr, "%[^,],", Name) == 1;
    }

    // returns true if successful
    bool readStudentNum(int* stno) {
        return fscanf(fptr, "%d,", stno) == 1;
    }
    
    // returns true if successful
    bool readGPA(double* gpa) {
        return fscanf(fptr, "%lf\n", gpa) == 1;
    }
}

    

    
   

