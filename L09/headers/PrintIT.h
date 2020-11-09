//
// Created by stud on 11/9/20.
//

#ifndef L09_PRINTIT_H
#define L09_PRINTIT_H
#include <iostream>
#include "TypeList.h"

template<typename TL>
struct PrintIT
{
    PrintIT(){std::cout << typeid(typename TL::First).name() << std::endl; PrintIT<typename TL::Rest>(); }
};

template<>
struct PrintIT<NullType>
{
    PrintIT() = default;
};
#endif //L09_PRINTIT_H
