#include "CVector.h"
#include <iostream>

int main()
{
    double cos1_2 = 0, cos2_3 = 0;
    int a;
    int S;

    init();
    CVector v1;
    v1.val_vec();
    init();
    CVector v2;
    v2.val_vec();
    init();
    CVector v3;
    v3.val_vec();
    init();
    CVector v4;
    v4.val_vec();

    std::cout << "Please enter num " << std::endl;
    std::cin >> a;

    v4 = v1 + v2;
    v4.print();

    v4 = v1 + v2 + v3;
    v4.print();

    v4 = v1 - v2;
    v4.print();

    v4 = v1 - v2 - v3;
    v4.print();

    v3 += v2;
    v3.print();

    v3 -= v2;
    v3.print();

    v4 = v2 * a;
    v4.print();

    v4 = v2 / a;
    v4.print();

    S = v1|v2;

    std::cout << S << std::endl;

    cos1_2 =  v1 ^ v2;
    cos2_3 = v2 ^ v3;

    std::cout << cos1_2<< std::endl;
    std::cout << cos2_3<< std::endl;

    v1[0] = a;
    v2[1] = 45;
    v1.print();
    v2.print();
    a = v4[3];
    std::cout << a;

    return 0;
}

