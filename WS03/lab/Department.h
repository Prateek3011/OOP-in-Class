//Sae-mi Park || spark280@myseneca.ca || 121333223 || Jan 31, 2023


#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	
	class Department {

		char* departName;
		Project* projects;
		int NumProject;
		double Budget = 15345.99;


	public:

		void updateName(const char* newname);
		void updateBudget(double change);
		bool addProject(Project& newproject);
		void createDepartment(const char* newname, Project& newproject,	double change);

		Project* fetchProjects() const;

		int fetchNumProjects() const;
		double fetchBudget() const;
		char* fetchName() const;

		double totalexpenses();
		double remainingBudget();
		void clearDepartment(); //deallocate


	};
	
	
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_