//
// Created by stud on 10/19/20.
//

#ifndef L07_FILE_H
#define L07_FILE_H

#include <stdio.h>
#include <cerrno>
#include <iostream>
#include <fstream>
#include <utility>

class File
{
public:
    File(const std::string & fileName) : file_name_(std::move(fileName))
    {
        file_ = fopen(file_name_.c_str(), "w+b");
        if(!file_){
            std::cout << "Could not open file" << std::endl;
        }
    }

    File(File& other)
        : file_(other.file_), file_name_(other.file_name_)
    {
        other.file_ = nullptr;
    }

    *File(File&& other) noexcept
        : file_(std::move(other.file_)), file_name_(std::move(other.file_name_))
    {
        other.file_ = nullptr;
    }

    File& operator=(File&& other) noexcept;
    File& operator=(File& other) noexcept;

    void Write(const std::string & s);

    std::string Read() const;

    const std::string& getFileName() const;

    virtual ~File() {
        if(file_ != nullptr)
        {
            fclose(file_);
        }
    }

private:
    std::string file_name_;
    FILE* file_;
};


#endif //L07_FILE_H
