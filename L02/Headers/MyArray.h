//
// Created by stud on 9/7/20.
//

#ifndef L02_MYARRAY_H
#define L02_MYARRAY_H


#include "assert.h"
#include "MyArrayIterator.h"

template<typename T, std::size_t N>
class MyArray
{
public:
    // User defined size.
    MyArray() : arrayPtr(new T [N]), size_(N) {   }

    template<typename D>
    MyArray(const MyArray<D, N>& toCopy)
    {
        arrayPtr = new T [N];
        D * startValue = toCopy.begin();
        for(auto index = 0; index < toCopy.size(); index++)
        {
            arrayPtr[index] = *startValue;
            startValue++;
        }
        size_ = toCopy.size();
    }

    std::size_t count() const;

    template<typename D, size_t M>
    MyArray& operator =(const MyArray<D, M> & rhs)
    {
        delete[] arrayPtr;
        arrayPtr = new T [rhs.count()];
        MyArrayIterator<D> startValue = rhs.begin();
        for(auto index = 0; index < rhs.count(); index++)
        {
            arrayPtr[index] = *startValue;
            startValue++;
        }
        size_ = rhs.count();
        return *this;
    }

    virtual ~MyArray() {
        // Delete content of array.
        delete[] arrayPtr;
    }

    // Return first element
    // Cannot be dereferenced or changed within function
    // Possible to change value.
    MyArrayIterator<T> const begin() const;

    // Return last element
    // Cannot be dereferenced or changed within function
    // Possible to change value
    MyArrayIterator<T> const end() const;

    T& operator[](int i);

    void fill(const T&);
    void print();

    bool isEmpty();

private:
    std::size_t size_ = 0;
    T * arrayPtr = nullptr;
};

template<typename T, std::size_t N>
MyArrayIterator<T> const MyArray<T, N>::begin() const {
    // assert(!isEmpty() && arrayPtr != nullptr);
    return MyArrayIterator<T>(&arrayPtr[0]);
}

template<typename T, std::size_t N>
MyArrayIterator<T> const MyArray<T, N>::end() const {
    // assert(!isEmpty() && arrayPtr != nullptr);
    return MyArrayIterator<T>(size_ > 0 ? &arrayPtr[size_-1] + 1 : &arrayPtr[0]);
}


template<typename T, std::size_t N>
bool MyArray<T, N>::isEmpty() {
    return size_ == 0;
}

template<typename T, std::size_t N>
T &MyArray<T, N>::operator[](int i) {
    assert(!isEmpty() && arrayPtr != nullptr);
    assert(i < count() && i >= 0);
    return arrayPtr[i];
}

template<typename T, std::size_t N>
void MyArray<T, N>::fill(const T & value) {
    assert(!isEmpty() && arrayPtr != nullptr);
    for (auto iter = 0; iter < count(); iter++)
    {
        arrayPtr[iter] = value;
    }
}

template<typename T, std::size_t N>
void MyArray<T, N>::print() {
    std::ostream_iterator< T& > outPut(std::cout, "\n");
    std::copy(begin(), end(), outPut);
}

template<typename T, std::size_t N>
std::size_t MyArray<T, N>::count() const {
    return size_;
}

// Partial Specialization for pointers
// T is a pointer.
template<typename T, std::size_t N>
class MyArray<T*, N>
{
public:
    MyArray()
        : arrayPtr(new T*[N]), size_(N)
    {}

    virtual ~MyArray() {
        for(auto index = 0; index < size_; index++)
        {
            delete arrayPtr[index];
        }
    }

    MyArray(const MyArray<T*, N>& toCopy)
        : size_(toCopy.count())
    {
        arrayPtr = new T* [toCopy.count()];
        MyArrayIterator<T*> startValue = toCopy.begin();
        for(auto index = 0; index < size_; index++)
        {
            arrayPtr[index] = new T(**startValue);
            startValue++;
        }
    }

    template<typename D, size_t M>
    MyArray& operator =(const MyArray<D*, M> & rhs)
    {
        for(auto index = 0; index < size_; index++)
        {
            delete arrayPtr[index];
        }
        MyArrayIterator<T *> startValue = rhs.begin();
        size_ = rhs.count();
        arrayPtr = new T *[size_];
        for(auto index = 0; index < rhs.count(); index++)
        {
            arrayPtr[index] = new T(**startValue);
            startValue++;
        }

        return *this;
    }

    size_t count() const;
    void fill(T*);
    MyArrayIterator<T*> const begin() const;
    MyArrayIterator<T*> const end() const;
    T *& operator[](int i) const;
    void print(){
        std::ostream_iterator< T*& > outPut(std::cout, "\n");
        std::copy(begin(), end(), outPut);
    }

private:
    std::size_t size_ = 0;
    T ** arrayPtr = nullptr;
};

template<typename T, std::size_t N>
MyArrayIterator<T*> const MyArray<T*, N>::begin() const {
    return MyArrayIterator<T*>(&arrayPtr[0]);
}

template<typename T, std::size_t N>
MyArrayIterator<T*> const MyArray<T*, N>::end() const {
    return MyArrayIterator<T*>(size_ > 0 ? &arrayPtr[size_-1] + 1 : &arrayPtr[0]);
}

template<typename T, std::size_t N>
//Non const so copy of element
void MyArray<T *, N>::fill(T * value) {
    assert(arrayPtr != nullptr);
    for (auto iter = 0; iter < size_; iter++)
    {
        arrayPtr[iter] = new T(*value);
    }
}

template<typename T, std::size_t N>
size_t MyArray<T *, N>::count() const {
    return size_;
}

template<typename T, std::size_t N>
T *& MyArray<T*, N>::operator[](int i) const {
    return arrayPtr[i];
}
#endif //L02_MYARRAY_H
