//
// Created by stud on 9/21/20.
//

#ifndef L04_STL_WRAPPER_H
#define L04_STL_WRAPPER_H
#include <iostream>
#include <functional>

template<typename T>
class Wrapper
{
public:
    Wrapper(std::function<void(int)> objFunctor) : wrapperFunctor(objFunctor){
    }
    void operator()(T value) const {
        wrapperFunctor(value);
    }
private:
    std::function<void(T)> wrapperFunctor;
};

#endif //L04_STL_WRAPPER_H
