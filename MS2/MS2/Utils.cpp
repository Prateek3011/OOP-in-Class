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
#include <ctime>
#include "Utils.h"

using namespace std;

namespace sdds {

	int daysOfMonth(int year, int month) {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = month >= 1 && month <= 12 ? month : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
}