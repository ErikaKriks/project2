#include <string>
#include <vector>
#include "student.h"

using std::string;
using std::vector;


// Setter function definitions
void Student::set_name(const string& name) {
    this->name = name;
}

void Student::set_surname(const string& surname) {
    this->surname = surname;
}

void Student::set_examMark(int examMark) {
    this->examMark = examMark;
}

void Student::set_marks(const std::vector<int>& marks) {
    this->marks = marks;
}
