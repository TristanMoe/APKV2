#include <iostream>

#pragma region Exercise 1.
/*
#include "headers/File.h";
int main() {
    const char * txt = "/home/stud/Desktop/Clion/Projects/L07/HelloWorld.txt";
    const char * txt2 = "/home/stud/Desktop/Clion/Projects/L07/HelloWorld2.txt";
    std::string s1("HelloWorld.txt");

    File f1{txt};
    File fString {s1};
    fString.Write("String Hello Hello");
    std::cout << fString.Read() << std::endl;


    f1.Write("Hello World 1\n");

    // Move Assignment
    File f2{txt2};
    f2 = std::move(f1);
    f2.Write("Hello World 2\n");

    // Move Constructor
    File f3(std::move(f2));
    f3.Write("Hello World 3\n");

    // Copy Constructor
    File f4(f3);
    f4.Write("Hello World 4\n");

    // Copy Assignment
    File f5{txt2};
    f5.Write(("Hello World 5\n"));
    std::cout << f5.Read() << std::endl;

    f5 = f4;
    std::cout << f5.Read() << std::endl;


    return 0;
}
*/
#pragma endregion

#pragma region Exercise 2
#include "headers/CopyableClass.h"
#include <vector>
int main()
{
    std::vector<CopyableClass> v1;

    for(int i = 0; i <= 20; i++)
    {
        auto * ptr = new std::string("Hello World");
        boost::shared_ptr<std::string> sPtr(ptr);
        CopyableClass c1(sPtr);
        v1.push_back(std::move(c1));
    }

    std::cout <<std::endl << "Vector Move Operation" << std::endl;
    std::vector<CopyableClass> v2(std::move(v1));
    std::cout << v2[0].getText() << std::endl;
}
#pragma endregion