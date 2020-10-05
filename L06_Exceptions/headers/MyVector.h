//
// Created by stud on 10/5/20.
//

#ifndef L06_EXCEPTIONS_MYVECTOR_H
#define L06_EXCEPTIONS_MYVECTOR_H

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <assert.h>

template <typename T>
class MyVector
{
public:
    explicit MyVector(int capacity = 10);

    MyVector(const MyVector& other);

    MyVector& operator =( const MyVector& other){
        T * temp = NewCopy(other.data_, other.size(), other.capacity());

        data_ = temp;
        size_ = other.size();
        capacity_ = other.capacity();

        return *this;
    }

    ~MyVector ();

    int size() const;
    int capacity() const;

    T& back();

    void push_back( const T& t );
    void pop_back ();

    void insert(const T& t, size_t n);

    T* begin ();
    T* end();

    T& operator []( size_t i );

private:
    size_t capacity_;
    size_t size_;
    T* data_; /* Contains the actual elements - data on the heap */
    T* NewCopy(const T* src, unsigned srcSize, unsigned srcCapacity);
 };

template<typename T>
MyVector<T>::MyVector(int capacity) : data_(new T[capacity]), size_(0), capacity_(capacity){}

template<typename T>
MyVector<T>::MyVector(const MyVector &other) {

    if(this != &other)
    {
        T * temp = NewCopy(other.data_, other.size(), other.capacity());

        data_ = temp;
        size_ = other.size();
        capacity_ = other.capacity();
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] data_;
}

template<typename T>
int MyVector<T>::size() const {
    return size_;
}

template<typename T>
T &MyVector<T>::back() {
    return data_[size()-1];
}

template<typename T>
int MyVector<T>::capacity() const {
    return capacity_;
}

template<typename T>
void MyVector<T>::push_back(const T &t) {
    if(size() == capacity())
    {
        T * temp = NewCopy(data_, size(), (capacity()*2));

        data_ = temp;
        capacity_ *= 2;
    }

    data_[size()] = t;
    size_++;
}

template<typename T>
void MyVector<T>::pop_back() {
    assert(size() > 0);
    --size_;
}

template<typename T>
void MyVector<T>::insert(const T &t, size_t n) {
    assert(n <= size());
    data_[n] = t;
}

template<typename T>
T *MyVector<T>::NewCopy(const T *src, unsigned srcSize, unsigned srcCapacity) {
    T * dest = new T[srcCapacity];
    try {
        copy(src, src+srcSize, dest);
    } catch (...) {
        delete[] dest;
        throw;
    }
    return dest;
}

template<typename T>
T *MyVector<T>::begin() {
    return &data_[0];
}

template<typename T>
T *MyVector<T>::end() {
    return size() > 0 ? &data_[size()-1] + 1 : &data_[0];
}

template<typename T>
T &MyVector<T>::operator[](size_t i) {
    assert(data_ != nullptr);
    assert(i < capacity() && i >= 0);
    return data_[i];
}

#endif //L06_EXCEPTIONS_MYVECTOR_H
