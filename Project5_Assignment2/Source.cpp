#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>


using namespace std;
//#define PRE_RELEASE

struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
#ifdef PRE_RELEASE
	std::string email;
#endif
};


void readFromFile(std::string filename, std::vector<STUDENT_DATA>& myvector)
{

	std::ifstream fin(filename); //opens file
	if (!fin.is_open())  //file is not open
	{
		std::cout << "Error: unable to open file for reading" << std::endl; //error checking, file could not be opened
	}
	else //file was sucessfully opened
	{
		std::string line;
		while (getline(fin, line)) //continues while we can get a new line from the file
		{ 
			STUDENT_DATA student; //creates a student 

			std::istringstream issLine(line); //turns the line into a istringstream
			std::string firstname, lastname; 

			getline(issLine, firstname, ','); //reads until we reach the first comma

#ifdef PRE_RELEASE
			std::string email;
			getline(issLine, lastname, ',');
			getline(issLine, email);
			student.email = email;
#else
			getline(issLine, lastname);
#endif


			student.firstName = firstname; //saves the data to the STUDENT_DATA
			student.lastName = lastname; //saves the data to the STUDENT_DATA

			myvector.push_back(student); //adds the STUDENT_DATA to the vector
		}

	}
	fin.close(); //closes the file
}


int main()
{

#ifdef PRE_RELEASE
	std::cout << "Application is running pre-release source code" << std::endl;
#else
	std::cout << "Application is running standard source code" << std::endl;
#endif


	std::vector<STUDENT_DATA> myvector; //creates the vector
	std::string filename;


#ifdef PRE_RELEASE
	filename = "StudentData_Emails.txt";
#else
	filename = "StudentData.txt";
#endif


	readFromFile(filename, myvector); //calls method that will read file


#ifdef _DEBUG
	for (int i = 0; i < myvector.size(); i++)
	{
		#ifdef PRE_RELEASE
			std::cout << myvector[i].firstName << myvector[i].lastName << " " << myvector[i].email << std::endl;
		#else
			std::cout << myvector[i].firstName << myvector[i].lastName << std::endl;
		#endif
	}
#endif
	 

	return 1;
}

