#include "CVector.h"
#include <iostream>
#include <cassert>
#include <cmath>
CVector::CVector():
    size_(5)
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

CVector  CVector::operator +(CVector & v_1)
{
    int i;
    CVector v_r;
    for (i = 0; i < size_; i++)
    {
        v_r.data_[i] = data_[i] + v_1.data_[i];
    }
    return v_r;
}

CVector  CVector::operator -(CVector & v_1)
{
    int i;
    CVector v_r;
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

