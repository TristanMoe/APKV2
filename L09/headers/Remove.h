//
// Created by stud on 11/9/20.
//

#ifndef L09_REMOVE_H
#define L09_REMOVE_H
#include <iostream>
#include "TypeList.h"

template<typename TL, typename V>
struct Remove;

// Base case if no element is found.
template<typename T> // Specialization 1
struct Remove<NullType, T>
{
    typedef NullType type;
};

// Found element to remove.
// Set Tail of current to Head of the next in line.
// This case is hit if both HEAD and T-type is the same.
// Which means we need to remove the element.
template <typename T, typename Tail> // Specialization 2
struct Remove<TypeList<T, Tail>, T>
{
    typedef Tail type;
};


template <typename Head, typename Tail, typename T> // Specialization 3
struct Remove<TypeList<Head, Tail>, T>
{
    typedef TypeList<Head,
            // Recursion.
            typename Remove<Tail, T>::type>
            type;
};

// Example TL<int, long, char>
// Remove<TL, char>
// SP3 <int, typelist<long, typelist<char, nulltype>, char>
// SP3 <long, typelist<char, nulltype>, char>
// SP2 <char, nulltype>
// TL<int, typelist<long, nulltype>> is the result.
// If it was chosen to remove long, it would have set tail to point to TL<char, nulltype>



#endif //L09_REMOVE_H
