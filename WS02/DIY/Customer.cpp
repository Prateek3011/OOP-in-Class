//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 27, 2023


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {
    //CustomersRecord t_rec = c_rec;


    // complete
    void EmptyRecord(Customers& rec) {
        Customers temp = { {0} };
        rec = temp;
    }


    void EmptyRecord(CustomersRecord& trec) {
        CustomersRecord temp = { NULL, 0 };
        trec = temp;
    }



    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }


    // complete

    bool read(Customers& rec) {
        bool check = false;
        cout << " Enter User name: ";
        //cin >> rec.user_name;
        read(rec.user_name, 21);

        if (rec.user_name[0] != '\0') //vaild
        {
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;

            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;

            cout << " Enter replies_count: ";
            cin >> rec.replies_count;

            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;


            check = true;
        }
        return check;
    }


    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        //resizing
         //resize logic //deallocate 
        int i;
        Customers* record; //create temp / bigger cup

        t_rec.noOfRecords++; //count num of records
        if (t_rec.noOfRecords == 1) //first records
        {
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords];
            t_rec.ptr_rec[0] = c_rec;

        }
        else //after first records
        {

            record = nullptr; 
            record = new Customers[t_rec.noOfRecords]; // allocate new temp

            for (i = 0; i < (t_rec.noOfRecords-1); i++) // copy old memory to new memory
            {
                record[i] = t_rec.ptr_rec[i];
            }

            record[t_rec.noOfRecords-1] = c_rec; // copy new memory to new size

            delete[] t_rec.ptr_rec; 
            t_rec.ptr_rec = nullptr; //deallocate old memory

            t_rec.ptr_rec = record; //address new to old
        }

        // creat temp | allocate temp | copy to temp | deallocate old memory 

    }

    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " <<
            c_rec.retweets_count << ", " << c_rec.replies_count << ", " <<
            c_rec.share_videos << endl;

    }

    void display(const CustomersRecord& t_rec) {
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            cout << i + 1 <<". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;

        }
    }
}

