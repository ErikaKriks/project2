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
// bool compareStudents(const Student &student1, const Student &student2);
void compareStudents(vector<Student> &students, int sortBy);
bool compareByName(const Student &student1, const Student &student2);
bool compareBySurname(const Student &student1, const Student &student2);
bool compareByFinalMarkAvg(const Student &student1, const Student &student2);
bool compareByFinalMarkMedian(const Student &student1, const Student &student2);
string generateRandomName(int studentNumber);
string generateRandomSurname(int studentNumber);
int generateRandomMark();
Student generateRandomStudent(int studentNumber, int numMarks);
void saveStudentDataToFileVector(const string &filename, const vector<Student> &students);
int usersChoiceStrategy();
int usersChoiceAvgMed();
int getUserSortOption();
bool fileExists(const string& filename);
void generateStudentDataToFile(const string& filename, int numStudents, int numMarks);
void saveStudentDataToFile(const string& filename, const vector<Student>& students);


#endif // FUNCTIONS_H_INCLUDED