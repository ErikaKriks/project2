#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>

class Person {
public:
    // virtual functions 
    virtual std::string get_name() const = 0;
    virtual std::string get_surname() const = 0;
    
    // Virtual destructor (recommended when dealing with inheritance)
    virtual ~Person() {}
};

#endif // PERSON_H_INCLUDED
