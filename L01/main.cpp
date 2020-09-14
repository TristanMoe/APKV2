//
// Created by stud on 8/31/20.
//

#include <iostream>
#include "Headers/sharedPtr.h"
using namespace SharedPointer;

int main(){
    std::cout << "Hello Word!" << std::endl;

    std::string * s1 = new std::string("Hello World");
    std::string * s2 = new std::string("Goodbye Program");
    SharedPtr<std::string> P1{s1};
    P1.print();

    {
        //(*P1) = 10;
        SharedPtr<std::string> P2{P1};
        P2.print();

        SharedPtr<std::string> P3{s2};
        P3.print();
        P3 = P2;
        P3.print();
    }

    P1.print();

    {
        // Try custom destructor
        int *s3 = new int(25);
        int *s4 = new int(30);
        void (*f_destruct)(int *) = [](int *value) {
            delete value;
        };
        SharedPtr<int> P4{s3, f_destruct};
        SharedPtr<int> P5{s4, f_destruct};
        P4.print();
        P5.print();

        P5 = P4;
        P5.print();
    }

    // Conversion to bool
    SharedPtr <std::string > sp1(new std:: string("Hello world"));
    if(sp1)
        std::cout << "SP Contains: " << *sp1 << std::endl;

    SharedPtr <std::string > sp2(new std:: string("Hello"));
    SharedPtr <std::string > sp3(new std:: string("world"));
    if(sp2 == sp3) // Comparison function will activiate.
        std::cout << "This should fail" << std::endl;
    //

    return 0;
}
