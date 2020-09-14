#include <iostream>
#include "Headers/MyArray.h"
#include "Headers/Person.h"

// Added 2 types to remove
template<typename T, typename D>
T* myfind(T* first, T* last, const D& v)
{
    do{
        if(*first == v)
            return first;
        first++;
    } while (first != last);
    return last;
}

template<typename T, typename D>
T** myfind(T** first, T** last, const D& v)
{
    do{
        if(**first == v)
            return first;
        first++;
    } while (first != last);
    return last;
}

int main() {

    // Partial specialization
    {
        std::string * data1 = new std::string("ABC");
        MyArray<std::string *, 6> s_ptr1;
        MyArray<std::string *, 7> s_ptr2;
        s_ptr1.fill(data1);
        std::cout << "Index operator: " << s_ptr1[0] << std::endl;
        std::string * data2 = new std::string("B");
        s_ptr1[0] = new std::string("CBA");
        std::string ** temp = s_ptr1.begin();
        std::cout << "Specialization value: " << **temp << std::endl;
        s_ptr1.print();

        s_ptr2 = s_ptr1;
        s_ptr2.print();

        MyArray<std::string *, 6> s_ptr3(s_ptr1);
        s_ptr3.print();

        // Myfind
        MyArray<int *, 5> i_ptr1;
        i_ptr1.fill(new int(1));
        delete i_ptr1[2];
        i_ptr1[2] = new int(3);
        delete i_ptr1[4];
        i_ptr1[4] = new int(2);
        std::cout << "Looking for '2'? " << (myfind(i_ptr1.begin(), i_ptr1.end(), 2) != i_ptr1.end() ? "found" : "sry no") << std::endl;
        i_ptr1.print();
    }

    // std:string
    {
        MyArray<std::string, 6> s1;
        s1.fill("B");
        s1[0] = "A";
        s1[5] = "C";
        s1.print();
    }
    // integer
    MyArray<double, 10> s2;
    s2.fill(1);
    std::cout << *(s2.begin()) << std::endl;
    std::cout << *(s2.end()) << std::endl;

    {
        s2[3] = 3;
        s2.print();
        std::cout << "Looking for '3'? " << (myfind(s2.begin(), s2.end(), 3) != s2.end() ? "found" : "sry no")
                  << std::endl;

        MyArray<std::string *, 6> my;
        my.fill(new std::string(""));
        delete my[5];
        my[5] = new std:: string("Hello"); // Assuming that my is a MyArray of string pointers
        std::cout << "Looking for 'Hello '? " << (myfind(my.begin (), my.end(),
                                                         std:: string("Hello")) != my.end()? "found" : "sry no") << std::endl;
    }



    // Custom class
    /*
    MyArray<Person, 2> s3;
    Person * Bob = new Person("Bob", 52);
    s3.fill(*Bob);
    s3.print();
    */

    // Conversion between types
    MyArray <int, 5> myInt; // Array based on 'int'
    MyArray <double, 7> myDouble; // Array based on 'double '

    myInt.fill(5);
    myDouble = myInt;
    return 0;
}
