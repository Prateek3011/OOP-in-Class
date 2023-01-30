//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 16, 2023

#ifndef FSDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define FSDDS_FILE_H

// Your header file content goes here

namespace fsdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);

}

#endif

