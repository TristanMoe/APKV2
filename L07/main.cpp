#include <iostream>

#pragma region Exercise 1. (Move)
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

#pragma region Exercise 2 (Move)
/*
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
 */
#pragma endregion

#pragma region Exercise 1 (Select)
/* Base Case
 * Unfolds e.g. sumOfNumbers<int, double, int>(n1, n2, n3)
 * Unfolds e.g. sumOfNumbers<int, double>(n1, n2)
 * Unfolds e.g. sumOfNumbers<int>(n1) Base case hit!
 * */
/*
template<typename N1>
N1&& sumOfNumbers(N1&& first){
    return std::forward<N1>(first);
}

template<typename N1, typename ... Numbers>
double sumOfNumbers(N1 && n1, Numbers&& ... numbers)
{
    return n1 + sumOfNumbers(std::forward<Numbers>(numbers)...);
}

int main()
{
    double sum;
    sum = sumOfNumbers(1, 2, 3, 4.14, 4.1f, 'H');
    std:: cout << sum << std::endl;

    std::cin.get();
    return 0;
}
*/
#pragma endregion

#pragma region Exercise 2 (Compile Time If)
int main()
{

}


# pragma endregion

#pragma region Exercise 3 (Threading)
/*
#include <chrono>
#include <future>
#include <vector>
#include <algorithm>
#include <iterator>

class Algo
{
public:
    Algo(std::vector<int> v)
            : data_(std::move(v))
    {}

    void doAlgo()
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> commence = std::chrono::high_resolution_clock::now();
        std::sort(data_.begin(), data_.end());
        std::chrono::time_point<std::chrono::high_resolution_clock> complete = std::chrono::high_resolution_clock::now();
        duration_ = std::chrono::nanoseconds(complete - commence);
    }

    std::chrono::duration<long double> processingTime()
    {
        return duration_;
    }


    void print()
    {
        std::copy(data_.begin(), data_.end(), std::ostream_iterator<int>(std::cout, " "));
    }
private:
    Algo(const Algo&) = delete; // No copy construction is allowed

    Algo& operator=(const Algo&) = delete; // No copy assignment is allowed

    std::vector<int>                    data_;
    std::chrono::nanoseconds            duration_;
};


typedef Algo SmartAlgo;
typedef Algo CoolAlgo;
typedef Algo FantasticAlgo;


int main(int argc, char* argv[])
{
    int i = 0;
    int n = 10000000; // Change at your leasure

    std::vector<int> data;
    data.reserve(n);
    generate_n( back_inserter( data ), n, [&i](){return i++;}  );
    random_shuffle( data.begin (), data.end () );

    // Insert code here ...



    return 0;
}
*/
#pragma endregion