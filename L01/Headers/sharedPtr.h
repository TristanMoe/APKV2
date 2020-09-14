//
// Created by stud on 8/31/20.
//

#ifndef L01_SHAREDPTR_H
#define L01_SHAREDPTR_H

#include <cstddef>
#include <cassert>
#include "helper.h"
namespace SharedPointer
{
    // Whereas T is the value and D is the destructor functor
    template<typename T>
    class SharedPtr
    {
    public:
        SharedPtr(T* t = NULL)
                : rawPtr_(t), n_referenceCount(new int(1))
        {}

        template<typename D>
        SharedPtr(T* t, D d)
                : h_(new Helper<T, D>(d))
        {
            rawPtr_ = t;
            n_referenceCount = new int(1);
        };

        // If the function is not explicit, it would allow implicit conversion
        // for the SharedPtr (See Onenote description).
        explicit SharedPtr(const SharedPtr& toCopy)
                : rawPtr_(toCopy.rawPtr_)
        {
            // Missing NULL check
            // Increment reference count
            // Point to same data
            (*toCopy.n_referenceCount)++;
            n_referenceCount = toCopy.n_referenceCount;
            if(toCopy.h_){
                h_ = toCopy.h_;
            }
        }

        virtual ~SharedPtr();

        SharedPtr& operator=(const SharedPtr& rhs)
        {
            assert(&rhs != this);

            (*n_referenceCount)--;
            clean_up_ptr();

            (*rhs.n_referenceCount)++;

            n_referenceCount = rhs.n_referenceCount;
            rawPtr_ = rhs.rawPtr_;
            h_ = rhs.h_;

            return *this;
        }

        bool operator==(const SharedPtr &rhs) const;
        // Explicit bool operator so it will not deduce operation.
        explicit operator bool() const;

        T& operator*();
        T* operator->();
        size_t count();
        void print();

        int* n_referenceCount; // body counter
    private:
        T* rawPtr_; // Actual pointer
        BaseHelper<T>* h_ = nullptr;
        void clean_up_ptr();
    };

//*____________________________________________________________________*\\
// Implementations \\

    template<typename T>
    SharedPtr<T>::~SharedPtr() {
        // Delete content of counter if no current reference.
        (*n_referenceCount)--;
        clean_up_ptr();
    }

    template<typename T>
    T &SharedPtr<T>::operator*() {
        return *rawPtr_;
    }

    template<typename T>
    T *SharedPtr<T>::operator->() {
        return rawPtr_;
    }


    template<typename T>
    size_t SharedPtr<T>::count() {
        return *n_referenceCount;
    }

    template<typename T>
    void SharedPtr<T>::print() {
        std::cout << "Reference count: " << this->count() << std::endl;
        std::cout << "Pointer value: " << *this->rawPtr_ << std::endl;
        std::cout << "Pointer address: " << this->rawPtr_ << std::endl << std::endl;
    }

    template<typename T>
    void SharedPtr<T>::clean_up_ptr() {
        if (count() < 1 && rawPtr_ != nullptr){
            if (h_){
                std::cout << "Custom Deletion" << std::endl;
                (*h_)(rawPtr_);
                delete h_;
                delete n_referenceCount;
            } else
            {
                std::cout << "Default Deletion" << std::endl;
                delete n_referenceCount;
                delete rawPtr_;
            }
        }
    }

    template<typename T>
    bool SharedPtr<T>::operator==(const SharedPtr &rhs) const {
        return rawPtr_ == rhs.rawPtr_;
    }

    template<typename T>
    SharedPtr<T>::operator bool() const {
        return rawPtr_ != nullptr;
    }
}

#endif //L01_SHAREDPTR_H
