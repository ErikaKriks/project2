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

bool compareStudents(const Student &student1, const Student &student2) {
    // Compare by name
    int nameComparison = student1.get_name().compare(student2.get_name());
    if (nameComparison != 0) {
        return nameComparison < 0;
    }
    
    // If names are equal, compare by surname
    return student1.get_surname().compare(student2.get_surname()) < 0;
}




// OLD
// int usersChoice() {
//     int n;
//     printf("Hello! Please, choose of the following options: \n");
//     printf("0 - Students information will be written manually.\n");
//     printf("1 - Students information will be autogenerated.\n");
//     printf("2 - Students information will be read from file kursiokai.txt and sorted out.\n");
//     printf("3 - Students information will be generated into files.\n");
//     cin >> n;

//     while (n > 3 || n < 0) {
//         printf("This choice is not defined. Please, try again.\n");
//         cin >> n;
//     }
    
//     return n;
// }

// int usersChoiceAvgMed() {
//     int n;
//     printf("Before entering information, please, choose of the following options: \n");
//     printf("0 - Students Final Mark will be calculated based on the Average of Marks.\n");
//     printf("1 - Students Final Mark will be calculated based on the Median of Marks.\n");
//     cin >> n;

//     while (n > 1 || n < 0) {
//         printf("This choice is not defined. Please, try again.\n");
//         cin >> n;
//     }
    
//     return n;
// }

// int usersChoiceVectorList() {
//     int n;
//     printf("Please, choose of the following options: \n");
//     printf("0 - Vector structure will be used for storing Students data.\n");
//     printf("1 - List structure will be used for storing Students data.\n");
//     cin >> n;

//     while (n > 1 || n < 0) {
//         printf("This choice is not defined. Please, try again.\n");
//         cin >> n;
//     }
    
//     return n;
// }

// int usersChoiceStrategy() {
//     int n;
//     printf("Please, choose of the following options: \n");
//     printf("1 - Strategy number 1. Two containers will be used for  \n");
//     printf("2 - Strategy number 2. One container will be used for students' categorization.\n");
//     printf("3 - Strategy number 3 (applicable only for vector structure).\n");
//     cin >> n;

//     while (n > 3 || n < 1) {
//         printf("This choice is not defined. Please, try again.\n");
//         cin >> n;
//     }
    
//     return n;
// }

// // Function to get input for a Student structure
// void getInput(Student &student) {
//     cout << "Enter the student's first name: " << endl;
//     cin >> student.name;
    
//     cout << "Enter the student's last name: " << endl;
//     cin >> student.surname;

//     cout << "Enter the exam mark the student has: " << endl;
//     cin >> student.examMark;

//     int mark;
//     cout << "Enter homework marks (press Enter twice to finish): ";

//     while (true) {
//         if (cin >> mark) {
//             student.marks.push_back(mark); // Add the homework mark to the vector
//         } else {
//             // If the input is not numeric, clear the error state and ignore the input
//             cin.clear();
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }


//         char nextChar = cin.peek(); // Peek at the next character in input

//         if (nextChar == '\n') {
//             char enter = cin.get(); // Consume the Enter character
//             nextChar = cin.peek(); // Peek again

//             if (nextChar == '\n') {
//                 break; // Exit the loop if double Enter is detected
//             }
//         }
//     }
// }

// void getInputAuto(Student &student)
// {
//     cout << "Enter the student's first name: " << endl;
//     cin >> student.name;

//     cout << "Enter the student's last name: " << endl;
//     cin >> student.surname;

//     // Generate random exam mark (between 1 and 10)
//     default_random_engine generator(time(0)); // Re-seed the random number generator
//     uniform_int_distribution<int> examDistribution(1, 10);
//     student.examMark = examDistribution(generator);

//     int n;
//     cout << "Enter the number of homework marks for the student: " << endl;
//     cin >> n;

//     // Generate random homework marks (between 1 and 10)
//     for (int j = 0; j < n; j++)
//     {
//         student.marks.push_back(generateRandomMark());
//     }
// }

// // Function to calculate the final mark for a student
// // float calculateFinalMarkAvg(const Student &student) {
// //     float sum = 0.0;

// //     if (student.marks.empty()) {
// //         return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
// //     }
    
// //     // Calculate the sum of individual marks
// //     for (int mark : student.marks) {
// //         sum += mark;
// //     }
    
// //     // Calculate the average of individual marks
// //     float averageMarks = sum / student.marks.size();
    
// //     // Calculate the final mark using the formula: 0.4 * average marks + 0.6 * exam
// //     return 0.4 * averageMarks + 0.6 * student.examMark;
// // }


// // Function to calculate the final mark using median
// // float calculateFinalMarkMed(const Student &student) {
// //     if (student.marks.empty()) {
// //         return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
// //     }

// //     // Sort the individual marks
// //     vector<int> sortedMarks = student.marks;
// //     sort(sortedMarks.begin(), sortedMarks.end());
    
// //     int n = student.marks.size();

// //     // Calculate the median
// //     float median;
// //     if (n % 2 == 0) {
// //         // If even number of marks, take the average of the middle two
// //         int middle1 = sortedMarks[(n / 2) - 1];
// //         int middle2 = sortedMarks[n / 2];
// //         median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
// //     } else {
// //         // If odd number of marks, take the middle value
// //         median = static_cast<float>(sortedMarks[n / 2]);
// //     }

// //     // Calculate the final mark using the formula: 0.4 * median + 0.6 * exam
// //     return 0.4 * median + 0.6 * student.examMark;
// // }

// void printStudentTable(const vector<Student> &students)
// {
//     // Print the table header
//     printf("%-20s%-20s%-40s%-20s\n", "Name", "Surname", "Final Mark (Avg.)/ Final Mark (Med.)", "Memory Address");
//     printf("------------------------------------------------------------------------------------------------\n");

//     // Print student data in a table
//     for (const Student &student : students)
//     {
//         printf("%-20s%-20s%-40.2f%-20p\n", student.name.c_str(), student.surname.c_str(), student.finalMark, &student);
//     }

//     // Print the table footer
//     printf("------------------------------------------------------------------------------------------------\n");
// }

// void printStudentTableAvgMed(const vector<Student> &students)
// {
//     // Print the table header
//     printf("%-20s%-20s%-20s%-20s\n", "Name", "Surname", "Final Mark (Avg.)", "Final Mark (Med.)");
//     printf("-----------------------------------------------------------------------------\n");

//     // Print student data in a table
//     for (const Student &student : students)
//     {
//         printf("%-20s%-20s%-20.2f%-20.2f\n", student.name.c_str(), student.surname.c_str(), student.finalMarkAvg, student.finalMarkMed);
//     }

//     // Print the table footer
//     printf("-----------------------------------------------------------------------------\n");
// }


// // Comparison function for sorting students by name and surname
// bool compareStudents(const Student &student1, const Student &student2) {
//     // Compare by name
//     int nameComparison = student1.name.compare(student2.name);
//     if (nameComparison != 0) {
//         return nameComparison < 0;
//     }
    
//     // If names are equal, compare by surname
//     return student1.surname.compare(student2.surname) < 0;
// }

// void readStudentsFromFileVector(const string &filename, vector<Student> &students)
// {
//     // Construct the full path to the file in the "datafiles" folder
//     std::__fs::filesystem::path dataFolderPath = "./datafiles";
//     std::__fs::filesystem::path filePath = dataFolderPath / filename;
    
//     ifstream inputFile(filePath);

//     try {
//         if (filename.empty())
//         {
//             throw invalid_argument("Error: File name not provided.");
//         }

//         if (!inputFile.is_open())
//         {
//             throw runtime_error("Error: Unable to open the file.");
//         }

        // string line;
        // bool firstLine = true; // Skip the first line with headers
        // int lineCount = 0;

        // while (getline(inputFile, line))
        // {
        //     ++lineCount;

        //     if (firstLine)
        //     {
        //         firstLine = false;
        //         continue; // Skip the header line
        //     }

        //     Student student;
        //     std::istringstream iss(line);
        //     string name, surname;
        //     int mark;

        //     iss >> student.name >> student.surname;

        //     while (iss >> mark)
        //     {
        //         student.marks.push_back(mark);
        //     }

        //     // Assign the last value in marks as the exam mark
        //     if (!student.marks.empty())
        //     {
        //         student.examMark = student.marks.back();
//                 student.marks.pop_back(); // Remove the last element from marks
//             }

//             if (iss.eof())
//             {
//                 iss.clear();
//                 iss >> student.examMark;
//             }

//             students.push_back(student);
//         }

//         inputFile.close();
//     } catch (const invalid_argument &e) {
//         cerr << e.what() << endl;
//         cout << "File not provided." << endl;
//     } catch (const runtime_error &e) {
//         cerr << e.what() << endl;
//         cout << "Error opening a file: " << e.what() << endl;
//     }
// }

// void readStudentsFromFileList(const string &filename, list<Student> &students)
// {
//     // Construct the full path to the file in the "datafiles" folder
//     std::__fs::filesystem::path dataFolderPath = "./datafiles";
//     std::__fs::filesystem::path filePath = dataFolderPath / filename;
    
//     ifstream inputFile(filePath);

//     try {
//         if (filename.empty())
//         {
//             throw invalid_argument("Error: File name not provided.");
//         }

//         if (!inputFile.is_open())
//         {
//             throw runtime_error("Error: Unable to open the file.");
//         }

//         string line;
//         bool firstLine = true; // Skip the first line with headers
//         int lineCount = 0;

//         while (getline(inputFile, line))
//         {
//             ++lineCount;

//             if (firstLine)
//             {
//                 firstLine = false;
//                 continue; // Skip the header line
//             }

//             Student student;
//             std::istringstream iss(line);
//             string name, surname;
//             int mark;

//             iss >> student.name >> student.surname;

//             while (iss >> mark)
//             {
//                 student.marks.push_back(mark);
//             }

//             // Assign the last value in marks as the exam mark
//             if (!student.marks.empty())
//             {
//                 student.examMark = student.marks.back();
//                 student.marks.pop_back(); // Remove the last element from marks
//             }

//             if (iss.eof())
//             {
//                 iss.clear();
//                 iss >> student.examMark;
//             }

//             students.push_back(student);
//         }

//         inputFile.close();
//     } catch (const invalid_argument &e) {
//         cerr << e.what() << endl;
//         cout << "File not provided." << endl;
//     } catch (const runtime_error &e) {
//         cerr << e.what() << endl;
//         cout << "Error opening a file: " << e.what() << endl;
// }

// }

// // Function to generate a random student name
// string generateRandomName(int studentNumber) {
//     return "Vardas" + to_string(studentNumber);
// }


// // Function to generate a random student surname
// string generateRandomSurname(int studentNumber) {
//     return "Pavarde" + to_string(studentNumber);
// }


// // Function to generate random individual marks between 1 and 10
// int generateRandomMark() {
//     static default_random_engine generator(time(0));
//     uniform_int_distribution<int> markDistribution(1, 10);
//     return markDistribution(generator);
// }


// // Function to generate random student data
// Student generateRandomStudent(int studentNumber, int numMarks) {
//     Student student;
//     student.name = generateRandomName(studentNumber);
//     student.surname = generateRandomSurname(studentNumber);
//     student.examMark = generateRandomMark(); // Random exam mark between 1 and 10

//     for (int i = 0; i < numMarks; ++i) {
//         student.marks.push_back(generateRandomMark()); // Random individual marks between 1 and 10
//     }

//     return student;
// }

// // Function to save student data to a file
// void saveStudentDataToFileList(const string &filename, const list<Student> &students) {
//     // Construct the full path to the file in the "datafiles" folder
//     std::__fs::filesystem::path dataFolderPath = "./datafiles";
//     std::__fs::filesystem::path filePath = dataFolderPath / filename;

//     ofstream file(filePath);


//     if (file.is_open()) {
//         file << left << setw(24) << "Vardas" << setw(24) << "Pavarde";
//         for (int i = 1; i <= 15; ++i) {
//             file << left << setw(9) << "ND" + to_string(i);
//         }
//        file << "Egz." << endl;

//         for (const Student& student : students) {
//             file << left << setw(24) << student.name << setw(24) << student.surname;
//             for (int mark : student.marks) {
//                 file << left << setw(9) << mark;
//             }
//             file << student.examMark << endl;
//         }

//         file.close();
//     } 
//     else {
//         cout << "Error: Could not open file for writing." << endl;
//     }
// }

// void saveStudentDataToFileVector(const string &filename, const vector<Student> &students) {
//     // Construct the full path to the file in the "datafiles" folder
//     std::__fs::filesystem::path dataFolderPath = "./datafiles";
//     std::__fs::filesystem::path filePath = dataFolderPath / filename;

//     ofstream file(filePath);


//     if (file.is_open()) {
//         file << left << setw(24) << "Vardas" << setw(24) << "Pavarde";
//         for (int i = 1; i <= 15; ++i) {
//             file << left << setw(9) << "ND" + to_string(i);
//         }
//         file << "Egz." << endl;

//         for (const Student& student : students) {
//             file << left << setw(24) << student.name << setw(24) << student.surname;
//             for (int mark : student.marks) {
//                 file << left << setw(9) << mark;
//             }
//             file << student.examMark << endl;
//         }

//         file.close();
//     } else {
//         cout << "Error: Could not open file for writing." << endl;
//     }
// }

