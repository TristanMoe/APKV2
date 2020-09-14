//
// Created by stud on 9/7/20.
//

#ifndef L02_PERSON_H
#define L02_PERSON_H

#include <string>

class Person
{
public:
    Person();
    Person(const std::string &name, int age) : name_(name), age_(age) {}
    // MISSING ASSIGNMENT OPERATOR!
    friend std::ostream& operator<<(std::ostream& os, const Person& dt);
private:
    std::string name_ = "";
    int age_ = 0;
};

#endif //L02_PERSON_H
