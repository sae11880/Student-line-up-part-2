// this is part two where it will give you the feed back of your entire line up from part 1

#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
#include <string>
#include "lineup-from-part1.h" 

void student_lineup_from_file() {
	std::ifstream file("LineUp.txt");


	if (!file) {
		std::cerr << "The file 'LineUp.txt' was not found. Please make sure the file exists in the same directory as this program." << std::endl;
		return;
	}

	std::vector<std::string> student_names;
	std::string name;


	while (std::getline(file, name)) {
		if (!name.empty()) {
			student_names.push_back(name);
		}
	}
	file.close();


	if (student_names.size() < 1 || student_names.size() > 25) {
		std::cerr << "The number of students in the file is not between 1 and 25." << std::endl;
		return;
	}

	std::sort(student_names.begin(), student_names.end());
	std::cout << "The student at the front of the line is: " << student_names.front() << std::endl;
	std::cout << "The student at the end of the line is: " << student_names.back();

	// Display all the names 
	std::cout << "\nAll students in line:\n";
	for (const auto& student : student_names) {
		std::cout << student << std::endl;
	}
}