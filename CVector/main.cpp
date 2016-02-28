#include <iostream>
#include <cassert>
#include <cmath>

//косинус угла ^
//скал€рное |

namespace Bek_DV
{
class CVector
{
private:
    int data_[10];
    int size_;
public:
    CVector();
    ~CVector();

    void print();

    int& operator[] (int index);
    CVector & operator +(CVector & v_1);
    CVector & operator -(CVector & v_1);
    void operator += (CVector & v_1);
    void operator -= (CVector & v_1);
    CVector & operator * (int a);
    CVector & operator / (int a);
    int operator | (CVector & v_1);
    double operator ^ (CVector & v_1);
    void val_vec ();
};
}
void init();

using namespace Bek_DV;

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
    a = v4[6];
    std::cout << a;

    return 0;
}

CVector::CVector():
    size_(10)
{
    int i;
    for(i = 0; i < size_; i++)
        data_[i] = 0;
}

CVector::~CVector()
{
    delete data_;
}

void CVector::print()
{
    int i;

    for(i = 0; i < size_; i++)
    {
        std::cout << data_[i];
        std::cout << " ";
    }
    std::cout << "\n";
}

int& CVector::operator[] (int index)
{
    assert(index >= 0 && index < size_);
    return  data_[index];
}

CVector & CVector::operator +(CVector & v_1)
{
    int i;
    static  CVector v_r;
    for (i = 0; i < size_; i++)
    {
        v_r.data_[i] = data_[i] + v_1.data_[i];
    }
    return v_r;
}

CVector & CVector::operator -(CVector & v_1)
{
    int i;
    static  CVector v_r;
    for (i = 0; i < size_; i++)
    {
        v_r.data_[i] = data_[i] - v_1.data_[i];
    }
    return v_r;
}

void CVector::operator += (CVector & v_1)
{
    int i;
    for (i = 0; i < size_; i++)
    {
        data_[i] += v_1.data_[i];
    }
}

void CVector::operator -= (CVector & v_1)
{
    int i;
    for (i = 0; i < size_; i++)
    {
        data_[i] -= v_1.data_[i];
    }
}

CVector & CVector::operator * (int a)
{
    int i;
    static CVector v_r;
    for (i = 0; i < size_; i++)
    {
        v_r.data_[i] = data_[i] * a;
    }
    return v_r;
}
CVector & CVector::operator / (int a)
{
    int i;
    static CVector v_r;
    for (i = 0; i < size_; i++)
    {
        v_r.data_[i] = data_[i] / a;
    }
    return v_r;
}

int CVector::operator | (CVector & v_1)
{
    int i;
    int G = 0;
    for(i = 0; i < size_; i++)
    {
        G += data_[i] * v_1.data_[i];
    }
    return G;
}

double CVector::operator ^ (CVector & v_1)
{
    double COS = 0;
    double a , b;
    int i;
    for(i = 0; i < size_; i++)
    {
        COS += data_[i] * v_1.data_[i];
        a += data_[i] * data_[i];
        b += v_1.data_[i] * v_1.data_[i];
    }
    a = sqrt(a);
    b = sqrt(b);

    COS /= a * b;
    assert(COS <= 1);
    return COS;
}

void init()
{
    std::cout << "Please initialize vector." << std::endl;
}

void CVector::val_vec()
{
    int i;
    for(i = 0; i < size_; i ++)
        std::cin >> data_[i];
}
