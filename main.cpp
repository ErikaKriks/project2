#include <iostream>
#include <string>
#include <vector>
#include <random> // for random number generation
#include <ctime>  // for seeding the random number generator
#include <chrono>
#include "student.h"
#include "functions.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;


int main() {
    // vector<int> numStudentsList = {1000, 10000, 100000, 1000000, 10000000};
    vector<int> numStudentsList = {10, 100}; // For testing purposes
        
    // Defining time variables used in both strategies
    std::chrono::duration<double> categorizationTime;
    std::chrono::duration<double> savingCategorizedTime;

    for (int numStudents : numStudentsList) {
        // Data generation and saving
        auto startGeneration = std::chrono::high_resolution_clock::now();
        vector<Student> students;
        for (int i = 1; i <= numStudents; ++i) {
            students.push_back(generateRandomStudent(i, 15)); // 15 random individual marks
        }
        string filename = "students" + to_string(numStudents) + ".txt";
        saveStudentDataToFileVector(filename, students);
        auto endGeneration = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> generationTime = endGeneration - startGeneration;

        // Reading data
        auto startReading = std::chrono::high_resolution_clock::now();
        vector<Student> readStudents;
        readStudentsFromFileVector(filename, readStudents);
        auto endReading = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readingTime = endReading - startReading;
            
        // Categorization
        auto startCategorization = std::chrono::high_resolution_clock::now();
        vector<Student> failStudents;
        vector<Student> passStudents;

        for (const Student& student : readStudents) {
            float finalMark = calculateFinalMarkAvg(student); // You can use either Avg or Med function
            if (finalMark < 5.0) {
                failStudents.push_back(student);
            } else {
                passStudents.push_back(student);
            }
        }

        // Sort the failStudents and passStudents vectors
        sort(failStudents.begin(), failStudents.end(), compareStudents);
        sort(passStudents.begin(), passStudents.end(), compareStudents);
        auto endCategorization = std::chrono::high_resolution_clock::now();
        categorizationTime = endCategorization - startCategorization;

        // Saving categorized data
        auto startSavingCategorized = std::chrono::high_resolution_clock::now();
        string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
        string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

        saveStudentDataToFileVector(filenameFail, failStudents);
        saveStudentDataToFileVector(filenamePass, passStudents);
        auto endSavingCategorized = std::chrono::high_resolution_clock::now();
        savingCategorizedTime = endSavingCategorized - startSavingCategorized;
            

            // else if (choice3 == 2) {
            //     // Categorization
            //     auto startCategorization = std::chrono::high_resolution_clock::now();
            //     vector<Student> failStudents;

            //     for (auto it = readStudents.begin(); it != readStudents.end();)
            //     {
            //         Student &student = *it;
            //         student.finalMark = calculateFinalMarkAvg(student);

            //         if (student.finalMark < 5.0)
            //         {
            //             failStudents.push_back(student);
            //             it = readStudents.erase(it); 
            //         }
            //         else
            //         {
            //             ++it;
            //         }
            //     }

            //     // Sort the Students vector
            //     sort(failStudents.begin(), failStudents.end(), compareStudents);
            //     sort(readStudents.begin(), readStudents.end(), compareStudents);
            //     auto endCategorization = std::chrono::high_resolution_clock::now();
            //     categorizationTime = endCategorization - startCategorization;

            //     // Saving categorized data
            //     auto startSavingCategorized = std::chrono::high_resolution_clock::now();
            //     string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
            //     string filenamePass = "students" + to_string(numStudents) + "_pass.txt";


            //     // Save failStudents to the file
            //     saveStudentDataToFileVector(filenameFail, failStudents);
            //     saveStudentDataToFileVector(filenamePass, readStudents);

            //     auto endSavingCategorized = std::chrono::high_resolution_clock::now();
            //     savingCategorizedTime = endSavingCategorized - startSavingCategorized;
            // }

            // else if (choice3 == 3) {
            //     // Strategy 3
            //     // Categorization using std::stable_partition
            //     auto startCategorization = std::chrono::high_resolution_clock::now();
            //     vector<Student> failStudents;

            //     // Stable partition based on the failing condition
            //     auto partitionPoint = stable_partition(readStudents.begin(), readStudents.end(),
            //                                         [](const Student& student) {
            //                                             return calculateFinalMarkAvg(student) < 5.0;
            //                                         });

            //     // Move failing students to the failStudents vector
            //     failStudents.assign(readStudents.begin(), partitionPoint);

            //     // Erase failing students from the readStudents vector
            //     readStudents.erase(readStudents.begin(), partitionPoint);

            //     auto endCategorization = std::chrono::high_resolution_clock::now();
            //     categorizationTime = endCategorization - startCategorization;

            //     // Saving categorized data
            //     auto startSavingCategorized = std::chrono::high_resolution_clock::now();
            //     string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
            //     string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

            //     saveStudentDataToFileVector(filenameFail, failStudents);
            //     saveStudentDataToFileVector(filenamePass, readStudents);
            //     auto endSavingCategorized = std::chrono::high_resolution_clock::now();
            //     savingCategorizedTime = endSavingCategorized - startSavingCategorized;
            // }

            // else {
            //     cout << "Invalid choice. Exiting..." << endl;
            //     return 1;
            // }

        // Output
        cout << "Execution times for " << numStudents << " students:" << endl;
        cout << "Memory address of the data structure: " << &students << endl;
        cout << "Data generation and saving: " << generationTime.count() << " seconds" << endl;
        cout << "Reading: " << readingTime.count() << " seconds" << endl;
        cout << "Categorization: " << categorizationTime.count() << " seconds" << endl;
        cout << "Saving categorized data: " << savingCategorizedTime.count() << " seconds" << endl;
        cout << "------------------------" << endl;
    }
        
    return 0;
}