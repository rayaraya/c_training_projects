#ifndef CVECTOR_T_H
#define CVECTOR_T_H
#include <cassert>
#include <iostream>
#include <cmath>

template <class T> class CVector_t
{
private:
    int size;
    T* data;
public:
    CVector_t(int b_size);
    CVector_t (const CVector_t<T>&thus);

    ~CVector_t();

    T& operator[] (int index);

    CVector_t operator = (CVector_t v_1);

    CVector_t operator +(CVector_t &v_1);
    CVector_t  operator -(CVector_t & v_1);

    void operator += (CVector_t &v_1);
    void operator -= (CVector_t &v_1);

    CVector_t operator * (int a);
    CVector_t operator / (int a);

    T operator | (CVector_t & v_1);

    double operator ^ (CVector_t & v_1);

    int operator > (CVector_t & v_1);
    int operator < (CVector_t & v_1);

    CVector_t operator -- (); //prefix form
    CVector_t operator ++ ();

    CVector_t operator ++ (int notused);
    CVector_t operator -- (int notused); //postfix form

    template <class X> friend std::ostream & operator <<(std::ostream & stream, CVector_t<X> & v);
    template <class X> friend std::istream & operator >>(std::istream & stream, CVector_t<X> & v);
};

template <class T> CVector_t<T>::CVector_t(int b_size)
{
    size = b_size;
    data = new T[size];
    assert(data != NULL);
}

template <class T> CVector_t<T>::CVector_t(const CVector_t<T>&thus)
{
    size = thus.size;
    data = new T[size];
    assert(data != NULL);
    int i;
    for (i = 0; i < size; i++)
        data[i] = thus.data[i];
}

template <class T> CVector_t<T>::~CVector_t()
{
    delete []data;
}

template <class T> T& CVector_t<T>::operator[] (int index)
{
    assert(index >= 0 && index < size);
    return data[index];
}

template <class T> CVector_t<T> CVector_t<T>::operator = (CVector_t v_1)
{
    int i;
    for(i = 0; i < size; i++)
        data[i] = v_1.data[i];
    return *this;
}

template <class T> CVector_t<T> CVector_t<T>::operator +(CVector_t<T> &v_1)
{
    assert(size == v_1.size);

    CVector_t<T> v_r (size);

    int i;
    for (i = 0; i < size; i++)
    {
        v_r.data[i] = data[i] + v_1.data[i];
    }

    return v_r;
}

template <class T> CVector_t<T> CVector_t<T>::operator -(CVector_t<T> & v_1)
{
    assert(size == v_1.size);

    CVector_t<T> v_r(size);
    int i;
    for (i = 0; i < size; i++)
    {
        v_r.data[i] = data[i] - v_1.data[i];
    }
    return v_r;
}



template <class T> void CVector_t<T>::operator += (CVector_t<T> &v_1)
{
    assert(size == v_1.size);
    int i;
    for (i = 0; i < size; i++)
    {
        data[i] += v_1.data[i];
    }
}

template <class T> void CVector_t<T>::operator -= (CVector_t<T> &v_1)
{
    assert(size == v_1.size);
    int i;
    for (i = 0; i < size; i++)
    {
        data[i] -= v_1.data[i];
    }
}

template <class T> CVector_t<T> CVector_t<T>::operator * (int a)
{
    int i;
    CVector_t<T> v_r(size);
    for(i = 0; i < size; i++)
    {
        v_r.data[i] = data[i] * a;
    }
    return v_r;
}


template <class T> CVector_t<T> CVector_t<T>::operator / (int a)
{
    int i;
    CVector_t<T> v_r(size);
    for(i = 0; i < size; i++)
    {
        v_r.data[i] = data[i] / a;
    }
    return v_r;
}

template <class T> T CVector_t<T>::operator | (CVector_t<T> & v_1)
{
    assert(size == v_1.size);
    int i;
    T G = 0;
    for(i = 0; i < size; i++)
    {
        G += data[i] * v_1.data[i];
    }
    return G;
}

template <class T> double CVector_t<T>::operator ^ (CVector_t<T> & v_1)
{
    assert(size == v_1.size);
    double COS = 0;
    double a , b;
    int i;
    for(i = 0; i < size; i++)
    {
        COS += data[i] * v_1.data[i];
        a += data[i] * data[i];
        b += v_1.data[i] * v_1.data[i];
    }
    a = sqrt(a);
    b = sqrt(b);

    COS /= a * b;
    assert(COS <= 1);
    return COS;
}

template <class T> int CVector_t<T>::operator > (CVector_t<T> & v_1)
{
    assert(size == v_1.size);
    long double a = 0 , b = 0;

    int i;

    for(i = 0; i < size; i++)
    {
        a += data[i] * data[i];
        b += v_1.data[i] * v_1.data[i];
    }

    return (a > b) ? 1 : 0;
}

template <class T> int CVector_t<T>::operator < (CVector_t<T> & v_1)
{
    assert(size == v_1.size);
    long double a = 0 , b = 0;

    int i;

    for(i = 0; i < size; i++)
    {
        a += data[i] * data[i];
        b += v_1.data[i] * v_1.data[i];
    }

    return (a < b) ? 1 : 0;
}

template <class T> CVector_t<T> CVector_t<T>::operator -- ()
{
    int i;
    for(i = 0; i < size; i++)
    {
        data[i]--;
    }
    return *this;
}

template <class T> CVector_t<T> CVector_t<T>::operator ++ ()
{
    int i;
    for(i = 0; i < size; i++)
    {
        data[i]++;
    }
    return *this;
}

template <class T> CVector_t<T> CVector_t<T>::operator ++ (int notused) //prefix form
{
    CVector_t temp = *this;
    int i;
    for(i = 0; i < size; i++)
    {
        data[i]++;
    }
    return temp;
}

template <class T> CVector_t<T> CVector_t<T>::operator -- (int notused) //prefix form
{
    CVector_t temp = *this;
    int i;
    for(i = 0; i < size; i++)
    {
        data[i]--;
    }
    return temp;
}

template <class X> std::ostream & operator<<(std::ostream & stream, CVector_t<X> & v)
{
    int i;
    for (i = 0; i < v.size; i++)
        stream << v.data[i] << " ";
    stream << std::endl;
    return stream;
}

template <class X> std::istream & operator >>(std::istream & stream, CVector_t<X> & v)
{
    std::cout << "Please put coordinates for vector size " << v.size << "\n";
    int i;
    for (i = 0; i < v.size; i++)
    {
        stream >> v.data[i];
    }
    return stream;
}

#endif // CVECTOR_T_H
