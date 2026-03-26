#include <iostream>
#include <vector>
#include <algorithm>

class student {
private:
	std::string name;
	int age;
	int grade;
public:
	student(std::string name, int age, int grade) {
		this->name = name;
		this->age = age;
		this->grade = grade;
	}

	std::string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	int getGrade() {
		return grade;
	}
};

int main()
{
	std::vector<student> students{ student("Maksym-Odin_din_din_din_dun", 15, 67), student("Bob", 16, 42), // not Maksym-Dindyn anymore I guess
		student("Lev-Dobrianskyi", 14, 102), student("Another-Student", 17, 80), student("Matviy-Lesiv", 48, 15),
		student("Skibidi-Student", 89, 20), student("Unnamed-Student", 15, 75) };
	std::cout << "Before sorting: " << std::endl;
	for (student student : students) {
		std::cout << student.getName() << std::endl;
	}
	auto studentIterator = std::find_if(students.begin(), students.end(), [](student student) {return student.getGrade() > 90; });
	studentIterator = std::find_if(students.begin(), students.end(), [](student student) {return student.getName() == "Bob"; });
	//std::cout << student(*studentIterator).name << std::endl; // if you want to print what you got
	auto studentIterator2 = std::count_if(students.begin(), students.end(), [](student student) {return student.getAge() > 16; });
	std::sort(students.begin(), students.end(), [](student student1, student student2) {return student1.getGrade() > student2.getGrade(); });
	std::cout << "After sorting: " << std::endl;
	for (student student : students) {
		std::cout << student.getName() << std::endl;
	}
	auto studentIterator3 = std::all_of(students.begin(), students.end(), [](student student) {return student.getAge() > 12; });
	auto studentIterator4 = std::any_of(students.begin(), students.end(), [](student student) {return student.getGrade() < 60; });
	auto studentIterator5 = std::none_of(students.begin(), students.end(), [](student student) {return student.getAge() < 16; });
}
