//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 16, 2023


#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	bool read(char* Cstring);
	bool read(int& intNum);
	bool read(double& doubleNum);
	bool read(char& character);

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
