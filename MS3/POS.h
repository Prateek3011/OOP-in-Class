// Final Project
// 
// Version 1.1
// Date	2023-03-26
// Author	Sae-mi Park
// Description
// This program test the student implementation of the Error and
// the Date class for submission.
//
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POS_H
#define SDDS_POS_H
#include <iostream>

namespace sdds {

	const double TAX = 0.13;
	const int MAX_SKU_LEN = 7;
	const int MAX_NAME_LEN = 40;

	const int POS_LIST = 1;
	const int POS_FORM = 2;

	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2030;

	const int MAX_STOCK_NUMBER = 99;
	const int MAX_NO_ITEMS = 2000;

	const char ERROR_POS_SKY[] = "SKU too long";
	const char ERROR_POS_NAME[] = "Item name too long";
	const char ERROR_POS_PRICE[] = "Invalid price value";
	const char ERROR_POS_TAX[] = "Invalid tax status";
	const char ERROR_POS_QTY[] = "Invalid quantity value";
	const char ERROR_POS_STOCK[] = "Item out of stock";
	const char ERROR_POS_EMPTY[] = "Invalid Empty Item";

}
#endif