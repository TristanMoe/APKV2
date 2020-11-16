//
// Created by stud on 11/16/20.
//

#ifndef L11_CUSTOMCLASS_H
#define L11_CUSTOMCLASS_H
#include <iostream>
#include <vector>
#include <memory_resource>
// Default allocator is of type byte.
namespace cpmr {

    template<typename T>
    class CustomClass {
    public:
        using allocator_type = std::pmr::polymorphic_allocator<std::byte>;

        CustomClass(allocator_type alloc = {}) : alloc_(alloc) {}

        CustomClass(std::vector<T> & data, allocator_type alloc = {}) : alloc_(alloc) {
            std::cout << "-- Default Constructor --" << std::endl;
            for(const T& v: data)
                emdVector.push_back(v);
        };

        // Copy constructors
        CustomClass(const CustomClass &other);

        CustomClass(const CustomClass &other, allocator_type alloc);

        // Move constructor
        CustomClass(CustomClass &&other);
        CustomClass(CustomClass &&other, allocator_type alloc);

        // Copy assignment
        CustomClass &operator=(const CustomClass &toCopy);

        // Move assignment
        CustomClass &operator=(CustomClass &&toMove);

        allocator_type get_allocator() { return alloc_; }

    private:
        allocator_type alloc_;
        std::vector<T, allocator_type> emdVector;
    };

    template<typename T>
    CustomClass<T>::CustomClass(const CustomClass &other) {
        std::cout << "-- Copy Constructor --" << std::endl;
        operator=(other);
    }

    template<typename T>
    CustomClass<T>::CustomClass(const CustomClass &other, CustomClass::allocator_type alloc)
            : alloc_(alloc) {
        std::cout << "-- Extended Copy Constructor --" << std::endl;
        operator=(other);
    }

    template<typename T>
    CustomClass<T> &CustomClass<T>::operator=(const CustomClass &toCopy) {
        std::cout << "-- Copy Assignment --" << std::endl;
        if (&toCopy == this) return *this;
        emdVector.erase(emdVector.begin(), emdVector.end());
        for (const T &v: toCopy.emdVector)
            emdVector.push_back(v);
        return *this;
    }

    template<typename T>
    CustomClass<T> &CustomClass<T>::operator=(CustomClass &&toMove) {
        std::cout << "-- Move Assignment --" << std::endl;
        if (alloc_ == toMove.alloc_)
            std::swap(emdVector, toMove.emdVector); //Swap because allocator is the same
        else
            operator=(toMove); // Use copy assignment.
    }

    template<typename T>
    CustomClass<T>::CustomClass(CustomClass &&other)
            : CustomClass(std::move(other), other.alloc_) // Delegate to extended move constructor
    {
        std::cout << "-- Move Constructor --" << std::endl;
    }

    template<typename T>
    CustomClass<T>::CustomClass(CustomClass &&other, CustomClass::allocator_type alloc)
            : CustomClass(alloc)
    {
        std::cout << "-- Extended Move Constructor --" << std::endl;
        operator=(std::move(other));
    }
}

#endif //L11_CUSTOMCLASS_H
