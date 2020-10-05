//
// Created by stud on 10/5/20.
//

#ifndef L06_EXCEPTIONS_LOGFILE_H
#define L06_EXCEPTIONS_LOGFILE_H

#include <string>
#include <stdexcept>

class LogFile
{
public:
    enum EState { es_OK, es_NOT_INITIALIZED, es_COULD_NOT_OPEN_FILE, es_FILENAME_IS_EMPTY };
    void write(const std::string& data );
    void init(const std::string& logfilename );
    EState getState() { return state_; }


    LogFile();
    explicit LogFile( const std::string& logfilename );
    ~LogFile();

private:
    std::string logfilename_;
    EState      state_;
    void internalWrite(const std::string& data );
};

#endif //L06_EXCEPTIONS_LOGFILE_H
