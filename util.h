// util.h

#ifndef GUARD_util_h
#define GUARD_util_h

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "analysis.h"
#include "Student_info.h"

int printGreeting();
void printMenu();

void loadGrades(ifstream&, 
	vector<Student_info>&,
	vector<Student_info>&, 
	vector<Student_info>&,
	string::size_type&
);

void fileSelect(int,
	vector<Student_info>&,
	vector<Student_info>&,
	vector<Student_info>&,
	string::size_type&
);

int checkHw(vector<Student_info>&, vector<Student_info>&);
void analyzeGrades(vector<Student_info>&, vector<Student_info>&);
void showScores(vector<Student_info>&, string::size_type&);

#endif