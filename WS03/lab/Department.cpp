//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 31, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    Department* depart;
    

    void Department::updateName(const char* newname) {
        if (newname != nullptr)
        {
            delete[] departName;
        }

        if (newname != nullptr && newname[0] != '\0')
        {
            departName = new char[strlen(newname) + 1];
            strcpy(departName, newname);
        }
        else
        {
            departName = nullptr;
        };
    }

    void Department::updateBudget(double change) {
        if (Budget > 0)
        {
            Budget += change;
        }
        else
        {
            Budget = 0;
        };
    }

    bool Department::addProject(Project& newproject) {
        int i;
        bool check = true;

        Project* temp;

        if (NumProject < 5)
        {
            NumProject++;
            if (newproject.m_cost < Budget)
            {
                if (NumProject == 1)
                {
                    projects = nullptr;
                    projects = new Project[NumProject];
                    projects[0] = newproject;
                }
                else
                {
                    temp = nullptr;
                    temp = new Project[NumProject];

                    for (i = 0; i < (NumProject - 1); i++) // copy old memory to new memory
                    {
                        temp[i] = projects[i];
                    }

                    temp[NumProject - 1] = newproject; // copy new memory to new size

                    delete[] projects;
                    projects = nullptr; //deallocate old memory

                    projects = temp;

                    //delete[] temp;
                    //memory leak ????????
                }
    
            }
            else
            {
                check = false;
            }
                
        }
       
        return check;
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        depart = nullptr;
        depart = new Department[NumProject];

        updateName(newname);
        addProject(newproject);
        updateBudget(change);

    }

    Project* Department::fetchProjects() const {
        return projects;
    }

    int Department::fetchNumProjects() const {
       
        return NumProject;
    }

    double Department::fetchBudget() const {
        return Budget;
    }

    char* Department::fetchName() const {
        return departName;
    }

    double Department::totalexpenses() { 

        double totalCost = 0.0;

        for (int i = 0; i < NumProject ; i++)
        {
            totalCost += projects[i].m_cost;
        }
        return totalCost;
    }

    double Department::remainingBudget() {
        double cost = 0.0, remain = 0.0;
        
        cost = totalexpenses();
        remain = (Budget - cost);

        return remain;
    }

    void Department::clearDepartment() {

            delete[] depart;
            depart = nullptr;

            delete[] departName;
            departName = nullptr;

            delete[] projects;
            projects = nullptr;
    }



    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

}