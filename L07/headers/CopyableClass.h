//
// Created by stud on 10/19/20.
//

#ifndef L07_COPYABLECLASS_H
#define L07_COPYABLECLASS_H

#include <iostream>
#include "boost/shared_ptr.hpp"

class CopyableClass
{
private:
    boost::shared_ptr<std::string> text_;
public:
    CopyableClass(boost::shared_ptr<std::string> & text) : text_(text)  {
        std::cout << "CONSTRUCTOR" << std::endl;
    }

    CopyableClass(const CopyableClass & other)
        : text_(std::move(other.text_))
    {
        std::cout << "COPY CONSTRUCTOR" << std::endl;
    }

    CopyableClass& operator=(const CopyableClass& other)
    {
        std::cout << "COPY ASSIGNMENT"<< std::endl;
        text_ = other.text_;
        return *this;
    }

    CopyableClass(CopyableClass && other) noexcept
        : text_(other.text_)
    {
        std::cout << "MOVE CONSTRUCTOR" << std::endl;
    }

    CopyableClass& operator=(CopyableClass&& other) noexcept
    {
        std::cout << "MOVE ASSIGNMENT"<< std::endl;
        if(this != &other)
        {
            text_.swap(other.text_);
        }
        return *this;
    }

    std::string & getText() const
    {
        return *text_.get();
    }
};

#endif //L07_COPYABLECLASS_H
