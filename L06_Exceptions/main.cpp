// ProgramTransformation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "boost/filesystem.hpp"

#include "headers/LogFile.h"
#include "headers/MyVector.h"
#include "headers/LogFileException.h"

/*
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
 */

int main()
{
    try {
        LogFile dummy;
        dummy.write( "Writing from main" );
    } catch (LogFileException & ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        LogFile logFile( "Exceptions.log" );
    } catch (LogFileException & ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        LogFile logFile( "Exceptions.log" );
        logFile.write( "Writing from main" );
    } catch (std::runtime_error & ex) {
        std::cout << ex.what() << std::endl;
    }
}
