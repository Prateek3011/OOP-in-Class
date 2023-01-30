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
#include <string>
#include "UI.h"
#include "GPA.h"
#include "GPAlist.h"
//#include "file.h"

using namespace std;

namespace sdds {

    //FILE* fptr;
   // GPA gpas[100];

    void flushkeys() {
        while (cin.get() != '\n');
    }

    // returns true if user enter y or Y
    bool yes() {
        char ch = cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }

    int uimain() {

        bool done = false;

        cout << "Enter GPA query..." << endl;

        while (!done)
        {
            char inputChar[10] = { '\0' }, temp[10] = { '\0' }, char_temp;
            double inputGPA = 0.0;

            cout << "? ";
            cin >> inputChar;

            //cin >> inputGPA;
            void flushkeys();
            

            if (inputChar[0] != '<' && inputChar[0] != '>' && inputChar[0] != '~' && inputChar[0] != '!')
            {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
                cout << "Op: [>,<,~,!]" << endl;
                cout << "value: GPA value" << endl; cout << endl;
            }
            else
            {
                if (inputChar[0] == '!' && inputChar[1] == '\0')
                {
                    cout << "Exit the program? (Y)es/(N)o: ";
                    done = !yes();
                   
                }
                else
                {
                    //divide char to inputChar[0] / inputGPA = inputChar[1],[2],[3]
                    for (int i = 0; inputChar[i] != 0; i++)
                    {
                        if (i != 0) {
                            temp[i - 1] += inputChar[i];
                        }
                    }
                    char_temp = inputChar[0];
                    //string to double
                    //citaion : https://www.geeksforgeeks.org/cpp-program-for-string-to-double-conversion/
                    //googleing
                    inputGPA = stod(temp);

                    //citation : https://jokerkwu.tistory.com/127
                    //googleing
                    cout << fixed;
                    cout.precision(1);

                    displayGPAwithinformation(char_temp, inputGPA); //GPA find
                }
            }
        }
        cout << "Goodbye!" << endl;
        return 0;
    }
}


