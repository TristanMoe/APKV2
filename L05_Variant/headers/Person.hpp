//
// Created by stud on 9/28/20.
//

#ifndef L05_VARIANT_PERSON_HPP
#define L05_VARIANT_PERSON_HPP

#include "boost/variant.hpp"
#include <iostream>

class Person : public boost::static_visitor<>
{
public:
    Person(std::string name, int age) : name_(name), age_(age) {
        std::cout << "Constructor was called" << std::endl;
    }

    std::string getName() const {
        return name_;
    }

    int getAge() const {
        return age_;
    }

    friend std::ostream & operator<<(std::ostream & os, const Person & p)
    {
        os << "Name: " <<  p.getName() << std::endl;
        os << "Age: " << p.getAge() << std::endl;
        return os;
    }

private:
    std::string name_;
    int age_;
};


#endif //L05_VARIANT_PERSON_HPP
