//Sae-mi Park || spark280@myseneca.ca || 121333223 || Feb 6, 2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Soccer.h"


using namespace std;

namespace sdds {
       

    //what is the role for this function?
    void SoccerTeam::setTeam(const SoccerTeam& team) {
        
        //???????????????????
        setEmpty();
        // judge the validation about SoccerTeam; 
        if (team.m_teamName[0] != '\0' && team.m_fines >= 0.0 && team.m_noFouls < MAX_FOUL && team.m_noFouls >= 0)
        {
            //valid

            setName(team.m_teamName);

            setFine(team.m_fines, team.m_noFouls);
            
        }
        else
        {
            //not valid
            setEmpty();
        }

    }
    void SoccerTeam::setName(const char* tname) {
        if (tname != nullptr && tname[0] != '\0' && strlen(tname) < 41)
        {
            strcpy(m_teamName, tname);        
        }
        else
        {
            setEmpty();
        }
    }
    void SoccerTeam::setFine(double fines, int foul) {
        
        if (fines >= 0.0 && foul < MAX_FOUL && foul >= 0)
        {
            m_fines = fines;
            m_noFouls = foul;
            m_golas = 0;
        }
        else
        {
            setEmpty();
        }
        
    }
    

    void SoccerTeam::setEmpty() {

        m_teamName[0] = '\0';
        m_noFouls = 0;
        m_fines = 0.0;
        m_golas = 0;

    }

    bool SoccerTeam::isEmpty() const {
        bool valid = false;

        if (m_teamName[0] != '\0' && m_noFouls <= MAX_FOUL)
        {
            valid = true;
        }
        return (valid);
    }

    void SoccerTeam::calFines() {
        //m_fines += m_fines * 0.2;
        m_fines = m_fines * 1.20;
    }

    int SoccerTeam::fouls() const {
        return m_noFouls;
    }

    SoccerTeam::SoccerTeam() {
      
        m_teamName[0] = '\0';
        m_noFouls = 0;
        m_fines = 0.0;
        m_golas = 0;
    }

    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
        setEmpty();
        
        if (tname[0] != '\0' && fines >= 0.0 && foul < MAX_FOUL && foul >= 0)
        {
            setName(tname);

            setFine(fines, foul);
           
        }
        else
        {
            setEmpty();
        }
    }

   
    std::ostream& SoccerTeam::display()const {
        if (isEmpty())
        {
            cout.unsetf(ios::right);
            cout.width(30);
            cout.setf(ios::left);
            cout.fill(' ');
            cout << m_teamName;

            
            cout.width(6);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout <<m_fines;

            cout.width(6);
            cout << m_noFouls;

            
            if (m_golas > 0)
            {
                cout.width(10);
                cout << m_golas <<"w";
            }
            else
            {
                cout.width(10);
                cout << "0";
                cout << " ";
            }
        }
        else
        {
            cout << "Invalid Team";
        }

        return cout;
    }
}