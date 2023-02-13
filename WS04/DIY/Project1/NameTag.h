//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 9, 2023

#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds {

	const int MAX_NAME = 40;
	const int MAX_EXTENSION = 5;

	class NameTag {
		char* name{};
		int extension{};

	public:

		NameTag& read();

		std::ostream& print()const;

		void setName(const char* n_name);
		void setNumbers(int e_extension);

		void setEmpty();
		bool isEmpty() const;
		bool validNum() const;

		NameTag();
		NameTag(const char* n_name);
		NameTag(const char* n_name, int e_extension);
		~NameTag();

	};



}

#endif