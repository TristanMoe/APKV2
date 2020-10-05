//
// Created by stud on 10/5/20.
//


#include <iostream>
#include <fstream>
using namespace std;

#include "../headers/LogFile.h"
#include "../headers/LogFileException.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LogFile::LogFile()
{
    cout << "Creating LogFile Object" << endl;
}

LogFile::LogFile( const string& logfilename )
{
    init( logfilename );
}

LogFile::~LogFile()
{
    cout << "Deleting LogFile Object" << endl;
}

void LogFile::init( const string& logfilename )
{
    logfilename_ = logfilename;
    internalWrite( "" );
}

void LogFile::write(const std::string& data )
{
    internalWrite( data+"\n" );
}

void LogFile::internalWrite( const string& data )
{
    if(logfilename_ == "") throw LogFileException(LogFileException::EState::es_FILENAME_IS_EMPTY, "Filename is empty");

    std::ofstream out;
    out.open( logfilename_.c_str(), std::ofstream::out | std::ofstream::app);
    if( out )
        out << data;
    else
        throw LogFileException(LogFileException::EState::es_COULD_NOT_OPEN_FILE, "Could not open file");
}


