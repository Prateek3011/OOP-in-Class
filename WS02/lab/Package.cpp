//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 16, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Package.h"
#include "Tools.h"

using namespace std;
namespace sdds {
    int no_of_traces;
    Customers* users;
    
    // Add: Complete the implementation of the no argument [int loadTraces()] function
    int loadTraces() {       // Do: complete the missing parts as guided (6 parts)
        bool check = true;
        int i = 0, count = 0;
       
        if (openFile_r(filename_r)) {
         
            // Add [1]: Set the noOfTraces to the number of records found in the file.
            
            no_of_traces = noOfTraces();
            
            // Add [2]: Dynamically allocate an array of Customers into the global Customers' pointer (users) with the size of no_of_traces.
            users = nullptr;
            users = new Customers[no_of_traces];

            // Add [3]: Load the Customers' records from the file into the dynamically created array (use a loop).
                
             while (check) {
                count += loadTraces(users[i++]);
                if (count == no_of_traces)
                {
                    check = false;
                }
             }
 
            // Add [4]: If th number of the records does not match the number of read ones, print an error message
                
            if (i != no_of_traces) {
                cout << "Error reading the records, Check the data file "<< endl;
            }
            else {
             
            // Add [5]: set  check to true 
                     check = true;
            }
 
            // Add [6]: close the file; call closefile() function
            closefile();

            }
            else {
                cout << "Could not open the"<< filename_r <<" data file"<< endl;
            }
            return check;
            }  




    // Add: Complete the implementation of the one argument [int loadTraces(Customers& user_info)] function that does the following:
                                                  // (1). reads one student record from the file
                                                  // (2). loads the record into the customers' reference
   
    int loadTraces(Customers& user_info) {    // Do: complete the missing parts as guided (3 parts)
        bool check = false;
        char read_Package_name[50];
       
        if (read(user_info.dayofweek) && read(user_info.user_id) && read(user_info.timeinhours) && read(user_info.dayofyear) && read(user_info.Fwifitime)
            && read(user_info.Fctime) && read(read_Package_name)) { // if reading of data

           // Add [1]: allocate memory to the size of the Package_name + 1, keep its address in the name of the customers reference (user_info.Package_Name)

            if (users != nullptr && read_Package_name[0] != '\0')
            {
                user_info.Package_Name = new char[strLen(read_Package_name) + 1];

           // Add [2]:  copy the name into the newly allocated memory, use provided strCpy function
            
                strCpy(user_info.Package_Name, read_Package_name);
           
           // Add [3]: set  check to true if the previous process is successfully completed
                check = true;
            } 
            else
            {
                user_info.Package_Name = nullptr;
            }            
        }
        return check; 
    }

    
    void grouptTraces() {  // Fully provided
        int i, j;
        Customers temp_record;
        for (i = no_of_traces - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (users[j].user_id > users[j + 1].user_id) {
                    temp_record = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp_record;
                }
            }
        }
    } 


    // ADD [1]: implement the display function based on the following condition: (timeinhours > 1.0 and dayofweek == 'F') 
    void display() {
        int i = 0 ;

            for (i = 0; i < no_of_traces; i++)
            {
                if (users[i].timeinhours > 1.0 && users[i].dayofweek == 'F')
                {
                cout << users[i].user_id << "," << users[i].timeinhours << "," << users[i].Fctime << "," <<
                    users[i].Fwifitime << "," << users[i].Package_Name << endl;
                }
            }  
       
    }

  
    // ADD [2]: implement the deallocateMemory function  
    void deallocateMemory() {
        
        //for -> package name
        for (int i = 0; i < no_of_traces; i++)
        {
            delete[] users[i].Package_Name;
            users[i].Package_Name = nullptr;
            
        }

        // whole struct

        delete[] users; 
        users = nullptr;
    }
        

}


