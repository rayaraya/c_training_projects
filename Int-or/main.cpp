#include "Int_or.h"
#include <iostream>

int main()
{
    Int_or<double> v1(4);
    Int_or<double> v2(4);
    double p = 0;

    std::cin >> v1;
    std::cout << v1;
    std::cout << v2;
    v2 = v1;
    p = v1[2];
    std::cout << v1;
    std::cout << v2;
    std::cout << "This is p = v1[2] = " << p << std::endl;
    std::cout << "This is only v1[2] = " << v1[2];
    return 0;
}
