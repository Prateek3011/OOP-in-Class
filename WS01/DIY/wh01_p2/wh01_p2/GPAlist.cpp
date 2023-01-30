//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 22, 2023

/***********************************************************************
// Workshop 1 p2: tester program
//
// File  UI.cpp
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
#include "GPAlist.h"
#include "GPA.h"
#include "File.h"
#include "UI.h"


using namespace std;

namespace sdds{
	//FILE* fptr;
	GPA ggpas[100];

	bool gpaQuery(const char* filename) {
        GPA ggpa;

        int gpanum = 0;
        bool ok = true;

        if (openFile(filename)) {
            while (ok && gpanum < 100) {
                ok = readName(ggpa.name) &&
                    readStudentNum(&ggpa.stno) &&
                    readGPA(&ggpa.gpa);
                if (ok) ggpas[gpanum++] = ggpa;
            }
            closeFile();
            sorting(ggpas, 86);
            uimain();
            
        }
        return gpanum == 86;
    }

    void sorting(struct GPA* gpas, int num)
    {
        struct GPA temp = { 0 };

        for (int i = 0; i < num; i++) {
            for (int j = i; j < num; j++) {
                if (gpas[i].stno > gpas[j].stno) {

                    temp = gpas[i];
                    gpas[i] = gpas[j];
                    gpas[j] = temp;

                }
            }
        }

    }
    void displayGPAwithinformation(const char char_temp, const double inputGPA)
    {       
        int i, j;
       
        for (i = 0, j = 1 ; i < 100; i++) {
            if (findGPA(&ggpas[i], char_temp, inputGPA)) {
                cout << "[" << j++ << "] ";
                displayGPA(&ggpas[i]);
            }
        }

        if (j == 1) {
            cout << "No match found for: " << inputGPA << endl;
        }
        
    }

   //GPA로 검색
   bool findGPA(const struct GPA* gpas, const char char_temp, const double inputGPA) {
       
       int i = 0;
       bool found = false;
      
           if (char_temp == '~')
           {
               if (gpas[i].gpa == inputGPA)
               {
                   found = true;
               }
              
           }
           else if (char_temp == '<')
           {
               if (gpas[i].gpa < inputGPA && gpas[i].gpa != 0)
               {
                   found = true;
               }
              
           }
           else
           {
               if (gpas[i].gpa > inputGPA)
               {
                   found = true;
               }
               
           }
     
       return found;

    }

   void displayGPA(const GPA* gpas) {
     

       cout << gpas->stno << ": " << gpas->gpa << " (" << gpas->name << ")" << endl;
   }

  

}