#include <iostream>

#pragma region Exercise 2.1 Binary
/*
#include "headers/Binary.h"
int main() {
    std::cout << "Exercise 1" << std::endl;

    std::cout << "Binary <1011>:: value = " << Binary <1011>::value << std::endl;
    // Should generate a compiler error , but does not!

    return 0;
}
*/
#pragma endregion

#pragma region 3 Typelists
#include "headers/TypeList.h"
#include "headers/IsSame.h"
#include "headers/Contains.h"
#include "headers/AtIndex.h"

int main()
{
    /* Must be true */
    std::cout << "IsSame <int, int >::value = " << IsSame <int , int >::value << std::
    endl;

    /* Must be false */
    std::cout << "IsSame <int, char >::value = " << IsSame <int , char >::value << std
    ::endl;

    typedef TYPELIST3<int , char , long> TL;
    /* Must be true */
    std::cout << "Contains <TL, int >::value = " << Contains <TL , int >::value << std
    ::endl;
    /* Must be false */
    std::cout << "Contains <TL, std::string >::value = " << Contains <TL , std::
    string >::value << std::endl;

    std::cout << "IsSame <typename AtIndex <TL , 2>::type , int >:: value" << IsSame <
            typename AtIndex <TL , 2>::type , int>:: value << std::endl;

}
#pragma endregion
