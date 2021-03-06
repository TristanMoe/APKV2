//
// Created by stud on 11/2/20.
//
#include <iostream>
// Disable the expression if not binary value is provided.
template<size_t N, typename = typename std::enable_if<N%10==0 | N%10==1>::type>
struct Binary : std::enable_if<N % 10, bool>
{
    static const size_t value = Binary<N / 10>::value << 1 | N%10;
};

template<>
struct Binary<0>
{
    static const size_t value = 0;
};

