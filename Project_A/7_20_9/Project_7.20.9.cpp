//7.20.9
// Created by Jorge Vasquez
// Tested by Guillermo Chavarin



#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
	string firstName;
	string lastName;
	int quizScores[10];
	char grade;

};

char quizGrade(int total) {
	if (total >= 90) {
		return 'A';
	}
	else if (total >= 80) {
		return 'B';
	}
	else if (total >= 70) {
		return 'C';
	}
	else if (total >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}

int main() {
	vector<student> students;
	student s;
	int sum;
	string userOpt;

	cout << "To add enter a student press 1 or Q to exit: ";
	cin >> userOpt;

	while (userOpt != "Q" && userOpt != "q") {

		cout << "Enter first Name: ";
		cin >> s.firstName;
		cout << "Enter last name: ";
		cin >> s.lastName;
		cout << "Enter 10 quiz scores: ";
		sum = 0;

		for (int i = 0; i < 10; i++) {
			cin >> s.quizScores[i];
			sum += s.quizScores[i];
		}

		s.grade = quizGrade(sum);

		students.push_back(s);
		cout << "To add enter a student press 1 or Q to exit: ";
		cin >> userOpt;
	}

	const string grades = "ABCDF";
	for (char g : grades) {
		cout << "Students with grade " << g << ":\n";
		for (const auto& s : students) {
			if (s.grade == g) {
				cout << s.firstName << " " << s.lastName << " " << s.grade << endl;
				for (int i = 0; i < 10; i++) {
					cout << s.quizScores[i] << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
