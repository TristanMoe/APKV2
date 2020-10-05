// ProgramTransformation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iterator>
using namespace std;

#include "headers/LogFile.h"
#include "headers/MyVector.h"

int main()
{
    MyVector<int> v(10);
    for(int i = 0; i < 15; i++)
    {
        v.push_back(10);
    }
    v.insert(15, 12);
    cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    cout << "Place " << 30 << " Value: " << v[12] << endl;

    cout << "Printing all vector values:" << endl;
    cout << "===========================" << endl;
    std::ostream_iterator<int> out_it (std::cout,", ");
    std::copy(v.begin(), v.end(), out_it);
    cout << endl << "===========================" << endl;

    return 0;
}

/*
int main()
{
    {
        LogFile dummy;
        if( !dummy.write( "Writing from main" ) )
        {
            switch( dummy.getState() )
            {
                case LogFile::es_OK:
                    break;
                case LogFile::es_NOT_INITIALIZED:
                    cerr << "Dummy not initialized" << endl;
                    break;
                case LogFile::es_COULD_NOT_OPEN_FILE:
                    cerr << "Could not open Dummy" << endl;
                    break;
                case LogFile::es_FILENAME_IS_EMPTY:
                    cerr << "Dummy filename is empty" << endl;
                    break;
            }
        }
    }

    LogFile logFile( "Exceptions.log" );
    if( logFile.getState() != LogFile::es_OK )
    {
        switch( logFile.getState() )
        {
            case LogFile::es_OK:
                break;
            case LogFile::es_NOT_INITIALIZED:
                cerr << "LogFile not initialized" << endl;
                break;
            case LogFile::es_COULD_NOT_OPEN_FILE:
                cerr << "Could not open LogFile" << endl;
                break;
            case LogFile::es_FILENAME_IS_EMPTY:
                cerr << "LogFile filename is empty" << endl;
                break;
        }
    }
    else if(!logFile.write( "Writing from main" ) )
    {
        switch( logFile.getState() )
        {
            case LogFile::es_OK:
                break;
            case LogFile::es_NOT_INITIALIZED:
                cerr << "LogFile not initialized" << endl;
                break;
            case LogFile::es_COULD_NOT_OPEN_FILE:
                cerr << "Could not open LogFile" << endl;
                break;
            case LogFile::es_FILENAME_IS_EMPTY:
                cerr << "LogFile filename is empty" << endl;
                break;
        }
    }

    if(logFile.getState() == LogFile::es_OK)
        if( !logFile.write( "Writing from main - again" ) )
        {
            switch( logFile.getState() )
            {
                case LogFile::es_OK:
                    break;
                case LogFile::es_NOT_INITIALIZED:
                    cerr << "LogFile not initialized" << endl;
                    break;
                case LogFile::es_COULD_NOT_OPEN_FILE:
                    cerr << "Could not open LogFile" << endl;
                    break;
                case LogFile::es_FILENAME_IS_EMPTY:
                    cerr << "LogFile filename is empty" << endl;
                    break;
            }
        }
}
*/