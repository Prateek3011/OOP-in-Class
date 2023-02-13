//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 9, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include "NameTag.h"

using namespace std;

namespace sdds {

	NameTag& NameTag::read() {

		char n_name[MAX_NAME + 1] = { '\0' }, addNum;
		int number = 0;
		bool done = false;

		//setEmpty();
		//In setempty you are setting the name to nullptr. 
		//If the name already had value in it (when calling the read function), 
		//you are loosing that data without deallocating it.

		cout << "Please enter the name: ";

		cin.getline(n_name, 41, '\n');
		if (!cin)
		{
			cin.clear();
			cin.ignore(100000, '\n');
		}



		setName(n_name);


		if (name != nullptr && name[0] != '\0')
		{
			cout << "Would you like to enter an extension? (Y)es/(N)o: ";


			while (!done)
			{
				cin.get(addNum);

				if (addNum == 'Y' || addNum == 'y' || addNum == 'N' || addNum == 'n')
				{
					cin.clear();
					cin.ignore(100000, '\n');

					done = true;
				}
				else
				{
					cout << "Only (Y) or (N) are acceptable, try agin: ";
					//citation from web site
					// https://m.blog.naver.com/lyw94k/220857627756
					cin.clear();
					cin.ignore(100000, '\n');

					done = false;
				}
			}

			done = false;

			if (addNum == 'Y' || addNum == 'y')
			{
				cout << "Please enter a 5 digit phone extension: ";
				while (!done)
				{
					cin >> number;

					if (!cin)
					{
						cin.clear();
						cin.ignore(100000, '\n');
						cout << "Bad integer value, try again: ";
						done = false;

					}
					else
					{
						string str1(to_string(number));
						if (str1.size() == 5)
						{
							setNumbers(number);
							cin.clear();
							cin.ignore(100000, '\n');
							done = true;
						}
						else
						{
							cout << "Invalid value [10000<=value<=99999]: ";
							//citation from web site
							// https://m.blog.naver.com/lyw94k/220857627756
							cin.clear();
							cin.ignore(100000, '\n');
							done = false;
						}
					}

				}
			}
			else
			{
				setNumbers(0);
			}
		}
		else
		{
			setEmpty();
		}
		return *this;
	}

	std::ostream& NameTag::print() const {

		if (isEmpty())
		{
			//=================
			cout << "+";
			if (strlen(name) < 21)
			{
				for (int i = 0; i < 22; i++)
				{
					cout << "-";
				}

			}
			else
			{

				for (int i = 0; i < MAX_NAME + 2; i++)
				{
					cout << "-";
				}
			}
			cout << "+" << endl;

			//=================
			cout << "|";
			if (strlen(name) < 21)
			{
				for (int i = 0; i < 22; i++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int i = 0; i < MAX_NAME + 2; i++)
				{
					cout << " ";
				}
			}
			cout << "|" << endl;


			//=================

			cout << "| ";
			cout.setf(ios::left);
			if (strlen(name) < 21)
			{
				cout.width(21);
				cout << name;
				cout.fill(' ');
			}
			else
			{
				cout << name;
				cout << " ";
			}
			cout << "|";
			cout << endl;

			//=================

			cout << "|";
			if (strlen(name) < 21)
			{
				for (int i = 0; i < 21; i++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int i = 0; i < MAX_NAME + 1; i++)
				{
					cout << " ";
				}
			}
			cout << " |" << endl;


			//=================
			cout << "| ";
			if (validNum())
			{
				cout << "Extension: " << extension;
				for (int i = 0; i < 5; i++)
				{
					cout << " ";
				}
			}
			else
			{
				if (strlen(name) < 21)
				{
					cout.width(21);
					cout << "Extension: N/A";
					cout.fill(' ');

				}
				else
				{
					cout.width(41);
					cout << "Extension: N/A";
					cout.fill(' ');
				}
			}
			cout << "|" << endl;


			//=================
			cout << "| ";
			if (strlen(name) < 21)
			{
				for (int i = 0; i < 21; i++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int i = 0; i < MAX_NAME + 1; i++)
				{
					cout << " ";
				}
			}
			cout << "|" << endl;


			//=================
			cout << "+";
			if (strlen(name) < 21)
			{
				for (int i = 0; i < 22; i++)
				{
					cout << "-";
				}
			}
			else
			{

				for (int i = 0; i < MAX_NAME + 2; i++)
				{
					cout << "-";
				}
			}
			cout << "+";
		}
		else
		{
			cout << "EMPTY NAMETAG!";
		}
		cout << endl;


		return cout;

	}


	bool NameTag::validNum() const {
		bool valid = true;
		if (extension == 0)
		{
			valid = false;
		}
		return valid;
	}


	void NameTag::setName(const char* n_name) {

		if (n_name != nullptr && n_name[0] != '\0')
		{
			if (name && name != nullptr)
			{
				delete[] name;
				setEmpty();
			}
			if (strlen(n_name) > MAX_NAME)
			{
				//name = nullptr;
				name = new char[MAX_NAME + 1];

				strncpy(name, n_name, MAX_NAME);
				name[MAX_NAME] = '\0';

			}
			else
			{
				//name = nullptr;
				name = new char[strlen(n_name) + 1];//////
				strcpy(name, n_name);
			}
		}
		else
		{
			setEmpty();
		}

	}

	void NameTag::setNumbers(int e_extension) {
		extension = e_extension;
	}

	void NameTag::setEmpty() {

		name = nullptr;
		extension = -1;

	}

	bool NameTag::isEmpty() const {
		bool valid = false;

		if (name != nullptr && name[0] != '\0' && extension > -1)
		{
			valid = true;
		}

		return valid;
	}


	NameTag::NameTag() {
		name = nullptr;
		extension = -1;
	}

	NameTag::NameTag(const char* n_name) {

		if (n_name != nullptr && n_name[0] != '\0')
		{
			setName(n_name);
		}
		else
		{
			setEmpty();
		}

		setNumbers(0);
	}

	NameTag::NameTag(const char* n_name, int e_extension) {

		if (n_name != nullptr && n_name[0] != '\0' && e_extension > -1)
		{
			string str1(to_string(e_extension));

			if (str1.size() == 5)
			{
				setName(n_name);
				setNumbers(e_extension);
			}
			else
			{
				setEmpty();
			}
		}
		else
		{
			setEmpty();
		}
	}

	NameTag::~NameTag() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
	}


}