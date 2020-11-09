//
// Created by stud on 11/2/20.
//

#ifndef L09_ATINDEX_H
#define L09_ATINDEX_H
#include "TypeList.h"
#include "IsSame.h"

template <typename TL, size_t N, size_t NStart = 0>
struct AtIndex
{
    using type = typename AtIndex<typename TL::Rest, N, NStart + 1>::type;
};

template <size_t N, size_t NStart>
struct AtIndex<NullType, N, NStart>
{
    using type = decltype(NullType());
};
#endif //L09_ATINDEX_H
