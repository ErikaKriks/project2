#include <iostream>
#include <string>
#include <vector>
#include <random> // for random number generation
#include <ctime>  // for seeding the random number generator
#include <chrono>
#include <iomanip>
#include "student.h"
#include "functions.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;


int main() {
    // Demonstrate Rule of Three (copy constructor, copy assignment, destructor)
    // Create an instance using the constructor
    Student s1("John", "Doe", 85, {90, 80, 75});

    // Create another instance using the copy constructor
    Student s2 = s1;

    // Modify s1 and s2
    s1.add_mark(95);
    s2.set_examMark(90);

    // Use copy assignment
    Student s3;
    s3 = s1;
    s3.set_examMark(30);


    s1.finalMarkAvg = calculateFinalMarkAvg(s1);
    s1.finalMarkMed = calculateFinalMarkMed(s1);
    s2.finalMarkAvg = calculateFinalMarkAvg(s2);
    s2.finalMarkMed = calculateFinalMarkMed(s2);
    s3.finalMarkAvg = calculateFinalMarkAvg(s3);
    s3.finalMarkMed = calculateFinalMarkMed(s3);


    // Display details of s1, s2, s3
    std::cout << "Details of s1:\n" << s1 << "\n";
    std::cout << "Details of s2:\n" << s2 << "\n";
    std::cout << "Details of s3:\n" << s3 << "\n";

    // Overwritten input/output methods
    // Input
    std::cout << "Enter details for a new student:\n";
    Student newStudent;
    std::cin >> newStudent;

    newStudent.finalMarkAvg = calculateFinalMarkAvg(newStudent);
    newStudent.finalMarkMed = calculateFinalMarkMed(newStudent);

    // Output
    std::cout << "\nDetails of the new student:\n" << newStudent << "\n";

    return 0;
}



// int main() {
//     int choice;
//     int choice1; // Average or Median
//     choice1 = usersChoiceAvgMed();
//     choice = usersChoiceStrategy();

//     vector<int> numStudentsList = { 100000, 1000000};
//     // vector<int> numStudentsList = {10, 100}; // For testing purposes
        
//     // Defining time variables used in both strategies
//     std::chrono::duration<double> categorizationTime;
//     std::chrono::duration<double> savingCategorizedTime;


//     for (int numStudents : numStudentsList) {
//         // Data generation and saving
//         auto startGeneration = std::chrono::high_resolution_clock::now();
//         vector<Student> students;
//         for (int i = 1; i <= numStudents; ++i) {
//             students.push_back(generateRandomStudent(i, 15)); // 15 random individual marks
//         }
//         string filename = "students" + to_string(numStudents) + ".txt";
//         saveStudentDataToFileVector(filename, students);
//         auto endGeneration = std::chrono::high_resolution_clock::now();
//         std::chrono::duration<double> generationTime = endGeneration - startGeneration;

//         // Reading data
//         auto startReading = std::chrono::high_resolution_clock::now();
//         vector<Student> readStudents;
//         readStudentsFromFileVector(filename, readStudents);
//         auto endReading = std::chrono::high_resolution_clock::now();
//         std::chrono::duration<double> readingTime = endReading - startReading;

//         if (choice == 1) {
//         // Strategy 1  
//         // // Categorization
//             auto startCategorization = std::chrono::high_resolution_clock::now();
//             vector<Student> failStudents;
//             vector<Student> passStudents;

//             for (Student& student : readStudents) {
                
//                 if (choice1 == 0) {
//                     student.finalMark = calculateFinalMarkAvg(student);                  
//                 }
//                 else if (choice1 == 1)
//                 {
//                     student.finalMark = calculateFinalMarkMed(student);
//                 }
//                 else {
//                     cout << "Invalid choice. Exiting..." << endl;
//                     return 1;
//                 }
                
//                 if (student.finalMark < 5.0) {
//                     failStudents.push_back(student);
//                 } else {
//                     passStudents.push_back(student);
//                 }
//             }

//             // Sort the failStudents and passStudents vectors
//             sort(failStudents.begin(), failStudents.end(), compareStudents);
//             sort(passStudents.begin(), passStudents.end(), compareStudents);
//             auto endCategorization = std::chrono::high_resolution_clock::now();
//             categorizationTime = endCategorization - startCategorization;

//             // Saving categorized data
//             auto startSavingCategorized = std::chrono::high_resolution_clock::now();
//             string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
//             string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

//             saveStudentDataToFileVector(filenameFail, failStudents);
//             saveStudentDataToFileVector(filenamePass, passStudents);
//             auto endSavingCategorized = std::chrono::high_resolution_clock::now();
//             savingCategorizedTime = endSavingCategorized - startSavingCategorized;
//         }

//         else if (choice == 2) {
//             // Strategy 2
//             // Categorization
//             auto startCategorization = std::chrono::high_resolution_clock::now();
//             vector<Student> failStudents;

//             for (auto it = readStudents.begin(); it != readStudents.end();)
//             {
//                 Student &student = *it;
//                 // student.finalMark = calculateFinalMarkAvg(student);
//                 if (choice1 == 0) {
//                     student.finalMark = calculateFinalMarkAvg(student);                  
//                 }
//                 else if (choice1 == 1)
//                 {
//                     student.finalMark = calculateFinalMarkMed(student);
//                 }
//                 else {
//                     cout << "Invalid choice. Exiting..." << endl;
//                     return 1;
//                 }

//                 if (student.finalMark < 5.0)
//                 {
//                     failStudents.push_back(student);
//                     it = readStudents.erase(it); 
//                 }
//                 else
//                 {
//                     ++it;
//                 }
//             }

//             // Sort the Students vector
//             sort(failStudents.begin(), failStudents.end(), compareStudents);
//             sort(readStudents.begin(), readStudents.end(), compareStudents);
//             auto endCategorization = std::chrono::high_resolution_clock::now();
//             categorizationTime = endCategorization - startCategorization;

//             // Saving categorized data
//             auto startSavingCategorized = std::chrono::high_resolution_clock::now();
//             string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
//             string filenamePass = "students" + to_string(numStudents) + "_pass.txt";


//             // Save failStudents to the file
//             saveStudentDataToFileVector(filenameFail, failStudents);
//             saveStudentDataToFileVector(filenamePass, readStudents);

//             auto endSavingCategorized = std::chrono::high_resolution_clock::now();
//             savingCategorizedTime = endSavingCategorized - startSavingCategorized;
//         }

//         else
//         {
//             cout << "Invalid choice. Exiting..." << endl;
//             return 1; 
//         }

//         // Output
//         cout << "Execution times for " << numStudents << " students:" << endl;
//         cout << "Memory address of the data structure: " << &students << endl;
//         cout << "Data generation and saving: " << generationTime.count() << " seconds" << endl;
//         cout << "Reading: " << readingTime.count() << " seconds" << endl;
//         cout << "Categorization: " << categorizationTime.count() << " seconds" << endl;
//         cout << "Saving categorized data: " << savingCategorizedTime.count() << " seconds" << endl;
//         cout << "------------------------" << endl;
//     }
        
//     return 0;

// }