//
// Created by stud on 11/2/20.
//

#ifndef L09_ISSAME_H
#define L09_ISSAME_H

#include <iostream>

template<class T, class U>
struct IsSame : std::false_type{};

template<class T>
struct IsSame<T, T> : std::true_type {};

#endif //L09_ISSAME_H
