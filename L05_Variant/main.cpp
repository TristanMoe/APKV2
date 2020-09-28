#include <iostream>
#include "boost/variant.hpp"
#include "headers/Person.hpp"

int main() {
    std::cout << "Boost Variant" << std::endl;
    boost::variant<int, std::string> u;
    std::cout << "String: " << u << " Int: " << boost::get<int>(u) << std::endl;

    Person p("Tristan", 23);
    boost::variant<int, Person> v(p);
    std::cout << "Person: " << v << std::endl;
    return 0;
}
