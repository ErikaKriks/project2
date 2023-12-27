#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "functions.h"
#include "student.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::printf;
using std::sort;
using std::ifstream;
using std::cerr;
using std::invalid_argument;
using std::runtime_error;
using std::to_string;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ofstream;
using std::left;
using std::setw;
using std::istringstream;

// NEW

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

void readStudentsFromFileVector(const string &filename, vector<Student> &students) {
    // Construct the full path to the file in the "datafiles" folder
    std::__fs::filesystem::path dataFolderPath = "./datafiles";
    std::__fs::filesystem::path filePath = dataFolderPath / filename;
    
    try {
        if (filename.empty()) {
            throw invalid_argument("Error: File name not provided.");
        }

        ifstream inputFile(filePath); // Open the file

        if (!inputFile.is_open()) {
            throw runtime_error("Error: Unable to open the file.");
        }

        string line;
        bool firstLine = true; // Skip the first line with headers
        int lineCount = 0;

        while (getline(inputFile, line)) {
            ++lineCount;

            if (firstLine) {
                firstLine = false;
                continue; // Skip the header line
            }

            Student student;
            istringstream iss(line);
            string name, surname;
            int mark;

            iss >> name >> surname;
            student.set_name(name);
            student.set_surname(surname);

            // Store all marks including the last one as the exam mark
            vector<int> marks;
            while (iss >> mark) {
                marks.push_back(mark);
            }

            if (!marks.empty()) {
                student.set_examMark(marks.back()); // Set the last mark as the exam mark
                marks.pop_back(); // Remove the last element (exam mark) from marks
            }

            // Assign the remaining marks (excluding the last one as it's the exam mark)
            student.set_marks(marks);

            students.push_back(student);
        }

        inputFile.close();
    } catch (const std::invalid_argument &e) {
        cerr << e.what() << std::endl;
        cout << "File not provided." << std::endl;
    } catch (const std::runtime_error &e) {
        cerr << e.what() << std::endl;
        cout << "Error opening a file: " << e.what() << std::endl;
    }
}

void printStudentTableAvgMed(const vector<Student> &students)
{
    // Print the table header
    printf("%-20s%-20s%-20s%-20s\n", "Name", "Surname", "Final Mark (Avg.)", "Final Mark (Med.)");
    printf("-----------------------------------------------------------------------------\n");

    // Print student data in a table
    for (const Student &student : students)
    {
        printf("%-20s%-20s%-20.2f%-20.2f\n", student.get_name().c_str(), student.get_surname().c_str(), student.finalMarkAvg, student.finalMarkMed);
    }

    // Print the table footer
    printf("-----------------------------------------------------------------------------\n");
}

// Function to generate a random student name
string generateRandomName(int studentNumber) {
    return "Vardas" + to_string(studentNumber);
}


// Function to generate a random student surname
string generateRandomSurname(int studentNumber) {
    return "Pavarde" + to_string(studentNumber);
}


// Function to generate random individual marks between 1 and 10
int generateRandomMark() {
    static default_random_engine generator(time(0));
    uniform_int_distribution<int> markDistribution(1, 10);
    return markDistribution(generator);
}


Student generateRandomStudent(int studentNumber, int numMarks) {
    Student student;
    student.set_name(generateRandomName(studentNumber));
    student.set_surname(generateRandomSurname(studentNumber));
    student.set_examMark(generateRandomMark()); // Random exam mark between 1 and 10

    for (int i = 0; i < numMarks; ++i) {
        student.add_mark(generateRandomMark()); // Random individual marks between 1 and 10
    }

    return student;
}

void saveStudentDataToFileVector(const string &filename, const vector<Student> &students) {
    // Construct the full path to the file in the "datafiles" folder
    std::__fs::filesystem::path dataFolderPath = "./datafiles";
    std::__fs::filesystem::path filePath = dataFolderPath / filename;

    ofstream file(filePath); // Open the file

    if (file.is_open()) {
        file << left << setw(24) << "Vardas" << setw(24) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            file << left << setw(9) << "ND" + to_string(i);
        }
        file << "Egz." << endl;

        for (const Student& student : students) {
            file << left << setw(24) << student.get_name() << setw(24) << student.get_surname();
            for (int mark : student.get_marks()) {
                file << left << setw(9) << mark;
            }
            file << student.get_examMark() << endl;
        }

        file.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

int usersChoiceStrategy() {
    int n;
    printf("Please, choose of the following options: \n");
    printf("1 - Strategy number 1. Two containers will be used for  \n");
    printf("2 - Strategy number 2. One container will be used for students' categorization.\n");
    cin >> n;

    while (n > 2 || n < 1) {
        printf("This choice is not defined. Please, try again.\n");
        cin >> n;
    }
    
    return n;
}

int usersChoiceAvgMed() {
    int n;
    printf("Before entering information, please, choose of the following options: \n");
    printf("0 - Students Final Mark will be calculated based on the Average of Marks.\n");
    printf("1 - Students Final Mark will be calculated based on the Median of Marks.\n");
    cin >> n;

    while (n > 1 || n < 0) {
        printf("This choice is not defined. Please, try again.\n");
        cin >> n;
    }
    
    return n;
}

int getUserSortOption() {
    int sortOption;
    cout << "Choose sorting option:" << std::endl;
    cout << "0: Sort by name" << std::endl;
    cout << "1: Sort by surname" << std::endl;
    cout << "2: Sort by final mark average" << std::endl;
    cout << "3: Sort by final mark median" << std::endl;
    cout << "Enter your choice (0-3): ";
    cin >> sortOption;
    while (sortOption > 3 || sortOption < 0) {
        printf("This choice is not defined. Please, try again.\n");
        cin >> sortOption;
    }

    return sortOption;
}

bool fileExists(const string& filename) {
    std::__fs::filesystem::path dataFolderPath = "./datafiles";
    std::__fs::filesystem::path filePath = dataFolderPath / filename;
    ifstream file(filePath.c_str());
    return file.good();
}

// Function to save student data to a file
void generateStudentDataToFile(const string& filename, int numStudents, int numMarks) {
    std::__fs::filesystem::path dataFolderPath = "./datafiles";
    std::__fs::filesystem::path filePath = dataFolderPath / filename;
    
    ofstream file(filePath);

    if (file.is_open()) {
        // First line of the file
        file << left << setw(24) << "Vardas" << setw(24) << "Pavarde";
        for (int i = 1; i <= numMarks; ++i) {
            file << left << setw(9) << "ND" + to_string(i);
        }
        file << "Egz." << endl;

        for (int i = 1; i <= numStudents; ++i) {
            string name = generateRandomName(i);
            string surname = generateRandomSurname(i);
            int examMark = generateRandomMark();
            

            file << left << setw(24) << name << setw(24) << surname;
            for (int j = 0; j < numMarks; ++j) {
                file << left << setw(9) << generateRandomMark();
            }
            file << examMark << endl;
        }

        file.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

// Comparison function for sorting students by name and surname
void compareStudents(vector<Student> &students, int sortBy) {
    if (sortBy == 0) { // Sort by name
        return sort(students.begin(), students.end(), compareByName);
    } else if (sortBy == 1) { // Sort by surname
        return sort(students.begin(), students.end(), compareBySurname);
    } else if (sortBy == 2) { // Sort by final mark average
        return sort(students.begin(), students.end(), compareByFinalMarkAvg);
    } else if (sortBy == 3) { // Sort by final mark median
        return sort(students.begin(), students.end(), compareByFinalMarkMedian);
    }
}


// Comparator for sorting by name
bool compareByName(const Student &student1, const Student &student2) {
    int nameComparison = student1.get_name().compare(student2.get_name());
    return nameComparison < 0; // Returns true if nameComparison is negative
}

// Comparator for sorting by surname
bool compareBySurname(const Student &student1, const Student &student2) {
    int surnameComparison = student1.get_surname().compare(student2.get_surname());
    return surnameComparison < 0; // Returns true if surnameComparison is negative
}

// Comparator for sorting by final mark average
bool compareByFinalMarkAvg(const Student &student1, const Student &student2) {
    return student1.finalMarkAvg < student2.finalMarkAvg;  
}

// Comparator for sorting by final mark median
bool compareByFinalMarkMedian(const Student &student1, const Student &student2) {
    return student1.finalMarkMed < student2.finalMarkMed;
}


void saveStudentDataToFile(const string& filename, const vector<Student>& students) {
    // Construct the full path to the file in the "datafiles" folder
    std::__fs::filesystem::path dataFolderPath = "./datafiles";
    std::__fs::filesystem::path filePath = dataFolderPath / filename;

    ofstream file(filePath);

    if (file.is_open()) {
        file << left << setw(24) << "Vardas" << setw(24) << "Pavarde" << setw(24) << "Final Mark Avg" << setw(24) << "Final Mark Med" << endl;

        for (const Student& student : students) {
            file << left << setw(24) << student.get_name() << setw(24) << student.get_surname() << setw(24) << student.finalMarkAvg << setw(24) << student.finalMarkMed << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

