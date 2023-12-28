#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>

using std::string;

class Person {
private:
    string name;
    string surname;   
public:
    // Constructor
    // Person(const std::string& name, std::string& surname) : name(name), surname(surname) {}
    
    // virtual functions 
    virtual std::string get_name() const = 0;
    virtual std::string get_surname() const = 0;

    // Setter methods
    void set_name(const std::string& name) {
        this->name = name;
    }
    void set_surname(const std::string& surname) {
        this->surname = surname;
    }

    
    // Virtual destructor (recommended when dealing with inheritance)
    virtual ~Person() {}
};

#endif // PERSON_H_INCLUDED
