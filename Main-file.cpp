//creating a modulized project 
//this will create the line up then a line up file then return the entire lineup
//there should be one module one header and a line up return module


#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <fstream> 
#include <string>
#include "lineup-from-part1.h"

void student_lineup() {
	int num_students;

	std::cout << "Enter the number of students in the class (1-25): ";
	std::cin >> num_students;

	while (num_students < 1 || num_students > 25) {
		std::cout << "Invalid number of students. Please enter a number between 1 and 25: ";
		std::cin >> num_students;
	}

	std::vector<std::string> student_names(num_students);
	std::cin.ignore();

	for (int i = 0; i < num_students; ++i) {
		std::cout << "Enter the name of a student: ";
		std::getline(std::cin, student_names[i]);
	}

	// next we will complie the names into a different file to allow for the computer to make a list of them. 
	std::ofstream outfile("LineUp.txt");
	if (outfile.is_open()) {
		for (const auto& name : student_names) {
			outfile << name << std::endl;
		}

		outfile.close();
		
	}

	else {
		std::cerr << "Unable to open file LineUp.txt for writing." << std::endl;
		return;
	}

	std::sort(student_names.begin(), student_names.end()); 

	std::cout << "The student at the front of the line is: " << student_names.front() << std::endl;
	std::cout << "The student at the end of the line is: " << student_names.back() << std::endl;
}


int main() { 
	student_lineup(); 
	std::cout << "Reading file"<<std::endl;

	student_lineup_from_file();
	return 0;
	}
