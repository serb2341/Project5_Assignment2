#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>


using namespace std;


struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
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
			getline(issLine, lastname); //value after comma is saved to the last name variable


			student.firstName = firstname; //saves the data to the STUDENT_DATA
			student.lastName = lastname; //saves the data to the STUDENT_DATA

			myvector.push_back(student); //adds the STUDENT_DATA to the vector
		}

	}
	fin.close(); //closes the file
}


int main()
{



	std::vector<STUDENT_DATA> myvector; //creates the vector
	std::string filename;

	filename = "StudentData.txt"; //filename for the file that contains the student data

	readFromFile(filename, myvector); //calls method that will read file


	return 1;
}

