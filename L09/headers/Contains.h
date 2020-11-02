//
// Created by stud on 11/2/20.
//

#ifndef L09_CONTAINS_H
#define L09_CONTAINS_H
#include "TypeList.h"
#include "IsSame.h"

// Primary template
template<typename TL, typename V>
struct Contains
{
    static const bool value =
            IsSame<typename TL::First, V>::value ? true :Contains<typename TL::Rest, V>::value;
};

// Base case.
template<typename V>
struct Contains<NullType, V>
{
    static const bool value = false;
};



#endif //L09_CONTAINS_H
