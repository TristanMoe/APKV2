#include <iostream>
#include "headers/CustomClass.h"

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cpmr::CustomClass<int> cpmr1(data);

    cpmr::CustomClass<int> cpmr2(std::move(cpmr1));

    cpmr1 = cpmr2;
    cpmr2 = std::move(cpmr1);
    return 0;
}
