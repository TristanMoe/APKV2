//
// Created by stud on 11/2/20.
//

#ifndef L09_ATINDEX_H
#define L09_ATINDEX_H
#include "TypeList.h"
#include "IsSame.h"

template <typename TL, unsigned int N>
struct AtIndex
{
    static const typename TL::First::type type = AtIndex<typename TL::Rest, N-1>::type;
};

template <typename TL>
struct AtIndex<TL, 0>
{
    static const typename TL::First::Type type;
};

template<unsigned int N>
struct AtIndex<NullType, N>
{
    static const NullType type;
};


#endif //L09_ATINDEX_H
