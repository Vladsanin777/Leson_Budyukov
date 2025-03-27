
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

enum {countStudents = 1000};

const char faculty[3][50] = \
{"Медицинский", "Физико-математический",
"Геолого-разведовательный"};

typedef struct {
	unsigned char assessment1 : 3, \
		assessment2 : 3, assessment3 : 3, \
		assessment4 : 3, assessment5 : 3;
} ASSESSMENTS;

typedef struct {
	unsigned short numberCreditBook, \
		numberGrup;
	char faculty[50];
	ASSESSMENTS assessments;
} STUDENT;

namespace action {
	void generateStudent(STUDENT* student, STUDENT *studentEnd) {
		strcpy(student->faculty, faculty[rand() % 3]);
		student->numberCreditBook = rand() << 1;
		student->numberGrup = rand() << 1;
		ASSESSMENTS *assessments = &student->assessments;
		assessments->assessment1 = rand() % 4 + 2;
		assessments->assessment2 = rand() % 4 + 2;
		assessments->assessment3 = rand() % 4 + 2;
		assessments->assessment4 = rand() % 4 + 2;
		assessments->assessment5 = rand() % 4 + 2;
	}
	void removeStudent(STUDENT* student, STUDENT* studentEnd) {
		memmove(student, student + 1, (studentEnd - student-1) * sizeof(STUDENT));
	}
	void printStudent(STUDENT* student, STUDENT* studentEnd) {
		ASSESSMENTS *assessments = &student->assessments;
		std::cout << "Number credit book: " << student->numberCreditBook
			<< std::endl << "Fculty: " << student->faculty << std::endl
			<< "Number grup: " << student->numberGrup << std::endl
			<< "Assessments: " << (short)assessments->assessment1 << ' '
			<< (short)assessments->assessment2 << ' '
			<< (short)assessments->assessment3 << ' '
			<< (short)assessments->assessment4 << ' '
			<< (short)assessments->assessment5 << ' ' << std::endl;
	}
}
namespace check {
	bool checkEmpty(STUDENT* student) { return true; }
	bool checkTow(STUDENT* student) {
		ASSESSMENTS assessments = student->assessments;
		if (assessments.assessment1 == 2 || \
			assessments.assessment2 == 2 || \
			assessments.assessment3 == 2 || \
			assessments.assessment4 == 2 || \
			assessments.assessment5 == 2
			) return true;
		return false;
	}
}
unsigned int constructer(STUDENT* studentBegin, \
	STUDENT* studentEnd, \
	void (*action)(STUDENT*, STUDENT*), const bool minus = false, \
	bool (*check)(STUDENT*) = check::checkEmpty \
){
	unsigned int count = 0;
	for (studentBegin;
		studentBegin != studentEnd; studentBegin++
		) {
		if (check(studentBegin)) {
			action(studentBegin, studentEnd);
			studentBegin -= minus;
			studentEnd -= minus;
		}
		else
			count++;
	}
	return count;
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	STUDENT* students = (STUDENT*)calloc(countStudents, sizeof(STUDENT));
	// generate students
	constructer(students, students + countStudents, \
		action::generateStudent);

	// delete tows
	unsigned int count = constructer(students, students + countStudents, \
		action::removeStudent, true, check::checkTow);
	// print remaining students
	constructer(students, students + count, \
		action::printStudent);
	free(students);
}	