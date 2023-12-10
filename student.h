#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <vector>

using std::string;
using std::vector;

class Student {
private:
    string name;
    string surname;
    int examMark;
    vector<int> marks;

public:
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

     


    // Getter and Setter functions
    inline string get_name() const {return name;};
    inline string get_surname() const {return surname;};
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