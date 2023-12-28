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
    vector<int> numStudentsList = {100000, 1000000};
    // vector<int> numStudentsList = {10, 100}; // For testing purposes
    int numMarks = 15;
    int sortOption = 0;
    sortOption = getUserSortOption();
    // Defining time variables used in both strategies
    std::chrono::duration<double> categorizationTime;
    std::chrono::duration<double> savingCategorizedTime;

    // Checking if students file already exists
    for (int numStudents : numStudentsList) {
        string filename = "students" + to_string(numStudents) + ".txt";
        if (fileExists(filename)) {
            cout << filename << " exists! Experiment will be conducted." << endl;
        } 
        else {
            cout << filename << " will be generated." << endl;
            
            // Data generation and saving
            auto startGeneration = std::chrono::high_resolution_clock::now();
            generateStudentDataToFile(filename, numStudents, numMarks);
            auto endGeneration = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> generationTime = endGeneration - startGeneration;

            cout << "Execution times for " << numStudents << " students:" << endl;
            cout << "Data generation and saving: " << generationTime.count() << " seconds" << endl;
        }
    }
    cout << "------------------------" << endl;

    for (int numStudents : numStudentsList) {
                
        string filename = "students" + to_string(numStudents) + ".txt";
        
        // Reading data
        auto startReading = std::chrono::high_resolution_clock::now();
        vector<Student> readStudents;
        readStudentsFromFileVector(filename, readStudents);
        auto endReading = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readingTime = endReading - startReading;

        // Strategy 3
        // Calculate final marks for the output file
        for (Student& student : readStudents) {
            student.finalMarkAvg = calculateFinalMarkAvg(student); // Final mark can be generated using Avg or Med
            student.finalMarkMed = calculateFinalMarkMed(student);
        }
        // Categorization using std::stable_partition
        auto startCategorization = std::chrono::high_resolution_clock::now();
        vector<Student> failStudents;

        // Stable partition based on the failing condition
        auto partitionPoint = stable_partition(readStudents.begin(), readStudents.end(),
                                            [](const Student& student) {
                                                return calculateFinalMarkAvg(student) < 5.0;
                                            });

        // Move failing students to the failStudents vector
        failStudents.assign(readStudents.begin(), partitionPoint);

        // Erase failing students from the readStudents vector
        readStudents.erase(readStudents.begin(), partitionPoint);


        // Sort the Students vector
        compareStudents(failStudents, sortOption);
        compareStudents(readStudents, sortOption);
        auto endCategorization = std::chrono::high_resolution_clock::now();
        categorizationTime = endCategorization - startCategorization;

        // Saving categorized data
        auto startSavingCategorized = std::chrono::high_resolution_clock::now();
        string filenameFail = "students" + to_string(numStudents) + "_fail.txt";
        string filenamePass = "students" + to_string(numStudents) + "_pass.txt";

        saveStudentDataToFile(filenameFail, failStudents);
        saveStudentDataToFile(filenamePass, readStudents);
        auto endSavingCategorized = std::chrono::high_resolution_clock::now();
        savingCategorizedTime = endSavingCategorized - startSavingCategorized;

        cout << "Execution times for " << numStudents << " students:" << endl;
        cout << "Reading: " << readingTime.count() << " seconds" << endl;
        cout << "Categorization: " << categorizationTime.count() << " seconds" << endl;
        cout << "Saving categorized data: " << savingCategorizedTime.count() << " seconds" << endl;
        cout << "------------------------" << endl;

    }
}