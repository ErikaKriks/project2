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

float calculateFinalMarkAvg(const Student &student) {
    float sum = 0.0;

    // Retrieve the marks using the getter function
    vector<int> marks = student.get_marks();

    if (marks.empty()) {
        return 0.6 * student.get_examMark(); // If no individual marks, return 0.6 * exam mark
    }
    
    // Calculate the sum of individual marks
    for (int mark : marks) {
        sum += mark;
    }
    
    // Calculate the average of individual marks
    float averageMarks = sum / marks.size();
    
    // Calculate the final mark using the formula: 0.4 * average marks + 0.6 * exam
    return 0.4 * averageMarks + 0.6 * student.get_examMark();
}

// Function to calculate the final mark using median
float calculateFinalMarkMed(const Student &student) {
    // Retrieve the marks using the getter function
    vector<int> marks = student.get_marks();
    
    if (marks.empty()) {
        return 0.6 * student.get_examMark(); // If no individual marks, return 0.6 * exam mark
    }

    // Sort the individual marks
    vector<int> sortedMarks = marks;
    sort(sortedMarks.begin(), sortedMarks.end());
    
    int n = marks.size();

    // Calculate the median
    float median;
    if (n % 2 == 0) {
        // If even number of marks, take the average of the middle two
        int middle1 = sortedMarks[(n / 2) - 1];
        int middle2 = sortedMarks[n / 2];
        median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
    } else {
        // If odd number of marks, take the middle value
        median = static_cast<float>(sortedMarks[n / 2]);
    }

    // Calculate the final mark using the formula: 0.4 * median + 0.6 * exam
    return 0.4 * median + 0.6 * student.get_examMark();
}


