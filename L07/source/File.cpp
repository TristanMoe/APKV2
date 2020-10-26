//
// Created by stud on 10/19/20.
//

#include "../headers/File.h"

void File::Write(const std::string & data) {
    fprintf(file_,"%s", data.c_str());
}

std::string File::Read() const {
    fseek(file_, 0L, SEEK_END);

    const int size = ftell(file_);

    rewind(file_);

    char* str = new char[size + 1];

    fread(str, sizeof(char), size, file_);

    auto result = std::string(str);

    delete[] str;

    return result;
}

File &File::operator=(File &&other) noexcept {
    if (this != &other)
    {
        fclose(file_);
        file_ = nullptr;
        std::swap(other.file_, file_);
    }
    return *this;
}

File &File::operator=(File &other) noexcept {
    if (this != &other)
    {
        fclose(file_);
        file_ = nullptr;
        std::swap(other.file_, file_);
    }
}

const std::string &File::getFileName() const {
    return this->file_name_;
}



