//
// Created by stud on 9/21/20.
//

#ifndef L04_STL_WRAPPER_H
#define L04_STL_WRAPPER_H
#include <iostream>
#include <functional>

template<typename T>
class Wrapper : public std::iterator<std::input_iterator_tag, T>
{
public:
    Wrapper(std::function<void(T)> objFunctor) : wrapperFunctor(objFunctor){}
    Wrapper(const Wrapper& toCopy) : wrapperFunctor(toCopy.wrapperFunctor) {}
    Wrapper& operator=(const Wrapper& rhs) {wrapperFunctor = rhs.wrapperFunctor; return *this; }
    Wrapper& operator=(const T& value){ wrapperFunctor(value); return *this; }
    Wrapper& operator++() {return *this;}
    Wrapper& operator++(int) { return *this; }
    bool operator==(const Wrapper& rhs) const {return wrapperFunctor == rhs.wrapperFunctor;}
    bool operator!=(const Wrapper& rhs) const {return wrapperFunctor != rhs.wrapperFunctor;}
    Wrapper& operator*() {return *this; }

    void operator()(T value) const {
        wrapperFunctor(value);
    }
private:
    std::function<void(T)> wrapperFunctor;
};

#endif //L04_STL_WRAPPER_H
