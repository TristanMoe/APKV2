//
// Created by stud on 9/7/20.
//

#include <iosfwd>
#include <iostream>
#include "../Headers/Person.h"

std::ostream &operator<<(std::ostream &os, const Person &dt) {
    os << "Name " << dt.name_ << " Age: " << dt.age_;
    return os;
}
