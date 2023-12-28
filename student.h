#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "person.h"

using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::fixed;
using std::endl;
using std::cout;

class Student : public Person {
private:
    string name;
    string surname;
    int examMark;
    vector<int> marks;


public:
    // virtual functions from base class
    string get_name() const override;
    string get_surname() const override;
    
    // Constructors
    Student() : examMark(0) {};
    Student(const string& name, const string& surname, int examMark, const vector<int>& marks){
        this->name = name;
        this->surname = surname;
        this->examMark = examMark;
        this->marks = marks;
    };

    // Copy Constructor
    Student(const Student& other) :
        name(other.name),
        surname(other.surname),
        examMark(other.examMark),
        marks(other.marks),
        finalMarkAvg(other.finalMarkAvg),
        finalMarkMed(other.finalMarkMed),
        finalMark(other.finalMark) {}

    // Copy Assignment Operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            surname = other.surname;
            examMark = other.examMark;
            marks = other.marks;
            finalMarkAvg = other.finalMarkAvg;
            finalMarkMed = other.finalMarkMed;
            finalMark = other.finalMark;
        }
        return *this;
    }

    // Overloading stream insertion operator <<
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << std::left << std::setw(20) << student.get_name() << std::setw(20)
       << student.get_surname() << std::setw(20) << std::fixed << std::setprecision(2)
       << student.finalMarkAvg << std::setw(20) << std::fixed << std::setprecision(2)
       << student.finalMarkMed << std::endl;
    return os;
}

    friend istream& operator>>(istream& is, Student& student) {
        cout << "Enter name: ";
        is >> student.name;

        cout << "Enter surname: ";
        is >> student.surname;

        cout << "Enter exam mark: ";
        is >> student.examMark;

        cout << "Enter marks (space-separated, enter non-numeric to finish): ";
        int mark;
        while (is >> mark) {
            student.marks.push_back(mark);
        }

        return is;
    }   


    // Getter and Setter functions
    // inline string get_name() const {return name;};
    // inline string get_surname() const {return surname;};
    inline int get_examMark() const {return examMark;};
    inline vector<int> get_marks() const {return marks;};

    void set_name(const string& name);
    void set_surname(const string& surname);
    void set_examMark(int examMark);
    void set_marks(const vector<int>& marks);
    
    // Other methods
    inline void add_mark(int mark) {marks.push_back(mark);}

    // Public members for final marks
    float finalMarkAvg;
    float finalMarkMed;
    float finalMark;

    // Destructor
    ~Student() {};
};

#endif // STUDENT_H_INCLUDED