//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 27, 2023


#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };


    void EmptyRecord(Customers& rec);
    void EmptyRecord(CustomersRecord& trec);


    void read(char* str, int len);

    // to be completed

    bool read(Customers& rec);

    void read(char* str, int len);

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);

    void display(const Customers& c_rec);

    void display(const CustomersRecord& t_rec);


}

#endif 
