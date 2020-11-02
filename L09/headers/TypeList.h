//
// Created by stud on 11/2/20.
//

#ifndef L09_TYPELIST_H
#define L09_TYPELIST_H

#include <iostream>

struct NullType{};

template<typename L, typename R>
struct TypeList
{
    typedef L First;
    typedef R Rest;
};

template <typename T>
using TYPELIST1 = TypeList<T, NullType>;

template <typename A, typename B>
using TYPELIST2 = TypeList< A,
                  TypeList< B, NullType>>;

template <typename A, typename B, typename C>
using TYPELIST3 = TypeList< A,
                  TypeList< B,
                  TypeList< C, NullType>>>;

template <typename A, typename B, typename C, typename D>
using TYPELIST4 = TypeList< A,
                  TypeList< B,
                  TypeList< C,
                  TypeList< D, NullType>>>>;
#endif //L09_TYPELIST_H
