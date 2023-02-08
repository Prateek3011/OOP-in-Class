//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 6, 2023
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Tournament.h"


using namespace std;

namespace sdds {
    

    void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
       
        setEmpty();

        if (name == nullptr)
        {
            setEmpty();
        }
        else
        {
            m_num = noOfteam;

            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);


            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < m_num; i++)
            {
                m_soccer[i] = soccer[i];
            }
            

        }

    }

    void Tournament::setEmpty() {
        m_name = nullptr;
        m_num = 0;
        m_soccer = nullptr;
    }

    bool Tournament::isEmpty() const {

        bool valid = false;

        if (m_name != nullptr && m_soccer != nullptr && m_num > 0)
        {
            valid = true;
        }

        return valid;
    }

    Tournament& Tournament::match(const SoccerTeam* ls) {

        for (int i = 0; i < m_num; i++)
        {
            for (int j = i+1; j < m_num; j++)
            {
                if (m_soccer[i].fouls() < m_soccer[j].fouls())
                {
                   m_soccer[j].calFines();
                   m_soccer[j].m_noFouls = m_soccer[j].fouls() * 2;

                   m_soccer[i].m_golas += 1;
                }
 
            }

        }


        return *this;
    }

    std::ostream& Tournament::display() const {

        if (isEmpty())
        {
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl; 

            cout.width(45);
            cout.setf(ios::right);
            cout.fill(' ');
            cout << "Fines";

            cout.width(10);
            cout << "Fouls";

            cout.width(10);
            cout << "Goals";
            cout << endl;

            for (int i = 0; i < m_num; i++)
            {
                cout << "Team[" << i +1 << "] :";
                m_soccer[i].display();
                cout << endl;
            }

        }
        else
        {
            cout << "Invalid Tournament";
        }
        
        return cout;
        //?? At the end return the reference of the ostream object.
    }


    Tournament::Tournament() {
        m_name = nullptr;
        m_num = 0;
        m_soccer = nullptr;
        //setEmpty();
    }

    Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
        
        setEmpty();
     
        if (name == nullptr)
        {
            setEmpty();
        }
        else
        {
            m_num = noOfteam;

            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);


            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < m_num; i++)
            {
                m_soccer[i] = soccer[i];
            }

        }
           
    }

    Tournament::~Tournament() {
        delete[] m_name;
        m_name = nullptr;

        delete[] m_soccer;
        m_soccer = nullptr;
    }

}