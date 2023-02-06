//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 1, 2023

#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_

namespace sdds {

	const int MAX_TNAME = 31;

	class Toys {
		char m_tname[MAX_TNAME];
		int m_sku;
		int m_age;
		double m_price;
		bool m_onSale;

	public:
		
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;

		bool checkValid()const;
		bool skumatch(int sku);
		void isEmpty();

	};

}
#endif // !
