#include "CVector_t.h"
#include <iostream>

int main()
{
    CVector_t<int> a(2), b(2), c(2);
    CVector_t<bool> B(6);


    bool g = 1;

    try
    {
        int j = 0;
        for(CVector_t<bool>::CBitIterator it = B.begin(),end = B.end(); it != end; ++it)
        {
            *it = j % 2;
            std::cout<<"  "<< *it << " " << std::endl;
            j++;
        }

        //f = a[1];
        a[0] = 1;
        a[1] = 2;

        b[0] = 2;
        b[1] = 99;

        c = b--;
        std::cout << c;
        c = a++;
        std::cout << c;

        c[0] = 67;
        c[1] = 5;

        std::cout << b[0]<< " " << b[1] << " ";
        std::cout << a[0]<< " " << a[1] << " ";

        int i = 4;

        i = (b < a);


        std::cout <<" "<< i;
    }
    catch (MyException &ex)
    {
        std::cout<< "There was an error: \n";
        ex.show_all();
    }


    return 0;
}
