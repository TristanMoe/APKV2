//
// Created by stud on 9/21/20.
//

#ifndef L02_MYARRAYITERATOR_H
#define L02_MYARRAYITERATOR_H
#include <ostream>
#include <iterator>

template<typename T>
class MyArrayIterator : public std::iterator<std::input_iterator_tag, T>
{
private:
    T* ptr;
public:
    MyArrayIterator(T* x) : ptr(x) {}
    MyArrayIterator(const MyArrayIterator& mit) : ptr(mit.ptr) {}
    MyArrayIterator& operator++() {++ptr; return *this; }
    MyArrayIterator operator++(int) {MyArrayIterator tmp(*this); operator++(); return tmp;}
    bool operator==(const MyArrayIterator& rhs) const {return ptr==rhs.ptr;}
    bool operator==(const T& rhs) const {return *ptr==rhs;}
    bool operator!=(const MyArrayIterator& rhs) const {return ptr!=rhs.ptr;}
    T& operator*() {return *ptr;}
};

#endif //L02_MYARRAYITERATOR_H
