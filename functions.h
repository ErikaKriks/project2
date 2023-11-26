#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <list>
#include <vector>
#include "student.h"

using std::string;
using std::list;
using std::vector;



// Functions
float calculateFinalMarkAvg(const Student &student);
float calculateFinalMarkMed(const Student &student);
void readStudentsFromFileVector(const std::string &filename, std::vector<Student> &students);
void printStudentTableAvgMed(const vector<Student> &students);
bool compareStudents(const Student &student1, const Student &student2);

#endif // FUNCTIONS_H_INCLUDED