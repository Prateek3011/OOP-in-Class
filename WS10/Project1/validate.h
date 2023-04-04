/***********************************************************************
// OOP244 Workshop 10:
// File	main.cpp
// Version 1.0
// Date	2023-04-04
// Author	Sae-mi Park
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef VALIDATE_H
#define VALIDATE_H

template <typename t> // t >> represent anytype //keywaord template
bool validate(const t& min, const t objects[], int size, bool val[]) {
	bool ret = true;
	int count = 0;

	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (objects[i] <= min) { // min reference || min not reference > overload <= copy construct need

			if (objects[i] < min)
			{
				count = 1;
				val[i] = false;
			}
		}
		else
		{
			val[i] = true;
		}

	}

	if (count == 0)
	{
		ret = true;
	}
	else
	{
		ret = false;
	}

	return ret;
}

#endif // VALIDATE_H