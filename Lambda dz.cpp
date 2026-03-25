#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	struct student {
		std::string name;
		int age;
		int grade;

		student(std::string name, int age, int grade) {
			this->name = name;
			this->age = age;
			this->grade = grade;
		}
	};
	std::vector<student> students{ student("Maksym-Odin_din_din_din_dun", 15, 67), student("Bob", 16, 42), // not Maksym-Dindyn anymore I guess
		student("Lev-Dobrianskyi", 14, 102), student("Another-Student", 17, 80), student("Matviy-Lesiv", 48, 15),
		student("Skibidi-Student", 89, 20), student("Unnamed-Student", 15, 75) };
	std::cout << "Before sorting: " << std::endl;
	for (student student : students) {
		std::cout << student.name << std::endl;
	}
	auto studentIterator = std::find_if(students.begin(), students.end(), [](student student) {return student.grade > 90; });
	studentIterator = std::find_if(students.begin(), students.end(), [](student student) {return student.name == "Bob"; });
	//std::cout << student(*studentIterator).name << std::endl; // if you want to print what you got
	auto studentIterator2 = std::count_if(students.begin(), students.end(), [](student student) {return student.age > 16; });
	std::sort(students.begin(), students.end(), [](student student1, student student2) {return student1.grade > student2.grade; });
	std::cout << "After sorting: " << std::endl;
	for (student student : students) {
		std::cout << student.name << std::endl;
	}
	auto studentIterator3 = std::all_of(students.begin(), students.end(), [](student student) {return student.age > 12; });
	auto studentIterator4 = std::any_of(students.begin(), students.end(), [](student student) {return student.grade < 60; });
	auto studentIterator5 = std::none_of(students.begin(), students.end(), [](student student) {return student.age < 16; });
}
