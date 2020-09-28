//
// Created by stud on 9/28/20.
//

#ifndef L05_VARIANT_PERSON_H
#define L05_VARIANT_PERSON_H

#include "boost/variant.hpp"
#include <iostream>

class Person : public boost::static_visitor<int>
{
public:
    Person(std::string *name, std::string *age) : name_(name), age_(age) {}

    virtual ~Person() {
        delete name_;
        delete age_;
    }

    friend std::ostream & operator << (std::ostream &, const Person & p)
    {

    }
private:
    std::string * name_;
    std::string * age_;
};


#endif //L05_VARIANT_PERSON_H
