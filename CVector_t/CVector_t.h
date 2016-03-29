#ifndef CVECTOR_T_H
#define CVECTOR_T_H

#include <iostream>
#include <cmath>
#include <cstring>
//дробь, нео и архитектор, ассмеблер
//интерполятор
class MyException
{
protected:
    std::string what_;
    std::string where_;
    int sf_;
public:
    MyException(const std::string& where, const std::string& what):
        what_(what),
        where_(where),
        sf_(0)
    {}
    MyException (const std::string what):
        what_(what),
        sf_(0)
    {}
    MyException(const std::string& where, const std::string& what, int sf):
        what_(what),
        where_(where),
        sf_(sf)
    {}
    void show_all()
    {
        std::string msg = what_ + " " + "Look here a specification: " + where_;
        std::cout << msg;
        if(sf_!= 0)
            std::cout << sf_ << ".\n";
    }
};

template <class T = int> class CVector_t
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

template <> class CVector_t<bool>
{
private:
    int size;
    unsigned char* data;

    void setbit(const int num, bool value)
    {
        try
        {
            if (!(num >= 0 && num / 8 + 1 < size))
                throw MyException("Function setbit of class CVector_t<bool>: line ","Invalid index.", __LINE__);
            if (value < 0 || value > 1)
                throw MyException("Function setbit of class CVector_t<bool>: line ","Invalid value.", __LINE__);
            data[num / 8] = data[num / 8] ^ (value << (num % 8));
        }
        catch(MyException & ex)
        {
            throw ex;
        }
    }
    bool getbit(const int num) const
    {
        try
        {
            if (!(num >= 0 && num / 8 + 1 < size))
                throw MyException("Function getbit of class CVector_t<bool>: line ","Invalid index.", __LINE__);
            return (data[num / 8] & (1 << num % 8));
        }
        catch(MyException & ex)
        {
            throw ex;
        }
    }
public:
    CVector_t(int b_size)
    {
        size = b_size;
        int N = size / 8 + !!(size % 8);
        try
        {
            data = new unsigned char[N];
        }
        catch(...)
        {
            throw MyException("In constructor CVector_t<bool>: line ","Memory isn't allocated in ctor.", __LINE__);
        }
        int i;
        for(i = 0; i < N; i++)
        {
            data[i] = 0;
        }
    }
    CVector_t (const CVector_t<bool>&thus)
    {
        size = thus.size;
        try
        {
            data = new unsigned char[size / 8 + !!(size % 8)];
        }
        catch(...)
        {
            throw MyException("In constructor CVector_t<bool>: line ","Memory isn't allocated in copy ctor.", __LINE__);
        }

        int i;
        for(i = 0; i < (size / 8 + !!(size % 8)); i++)
        {
            data[i] = thus.data[i];
        }
    }

    ~CVector_t()
    {
        delete[] data;
    }
    int getsize()
    {
        return size;
    }
    bool operator == (const CVector_t & thus)
    {
        return (this == &thus);
    }
    bool operator != (const CVector_t & thus)
    {
        return !(*this == thus);
    }

    class CBit
    {
    private:
        CVector_t<bool> &base_;
        CBit& operator = (const CBit&);
        friend class CBitIterator;
        const int num_;
    public:
        CBit(CVector_t & base, const int num):
            base_(base),
            num_(num)
        {}
        CBit(const CBit&);
        CBit& operator = (bool value)
        {
            base_.setbit(num_, value);
            return *this;
        }
        operator int() const
        {
            return base_.getbit(num_);
        }
    };

    CBit operator [](const int& num)
    {
        return CBit(*this, num);
    }
    bool operator[](const int& num) const
    {
        return getbit(num);
    }

    class CBitIterator
    {
    private:
        friend class CVector_t<bool>;
        CVector_t<bool> &base_;
        int index;
        CBitIterator(CVector_t &base, int ind):
            base_(base),
            index(ind)
        {
            try
            {
                if (ind < 0 || ind > base_.getsize() - 1)
                    throw MyException("In constructor CVector_t<bool>::CBitIterator line ","Invalid index", __LINE__);
            }
            catch(MyException & ex)
            {
                throw ex;
            }
        }
    public:
        CBitIterator& operator = (const CBitIterator& thus)
        {
            try
            {
                if (this != &thus)
                {
                    if(thus.base_ != base_)
                        throw MyException("In operator = in class CBitIterator line ","Different base. ", __LINE__);
                    base_ = thus.base_;
                    index = thus.index;
                }
            }
            catch(MyException &ex)
            {
                throw ex;
            }
            return *this;
        }
        CBitIterator& operator ++()
        {
            try
            {
                if(index == base_.getsize() - 1)
                    throw MyException("In operator ++ in class CBitIterator line", "You try ++index but your index have a max value.", __LINE__);
                index++;
            }
            catch(MyException &ex)
            {
                throw ex;
            }
            return *this;
        }
        CBitIterator operator ++ (int notused)
        {
            try
            {
                if(index == base_.getsize() - 1)
                    throw MyException("In operator ++ in class CBitIterator line", "You try ++index but your index have a max value.", __LINE__);
                index++;
                CBitIterator temp(base_, index);
                return temp;
            }
            catch(MyException &ex)
            {
                throw ex;
            }
        }
        CBit operator *()
        {
            CBit a(base_, index);
            return a; //current
        }
        bool operator == (const CBitIterator& thus)
        {
            return ((this == &thus) || ((index == thus.index) && (base_ == thus.base_)));
        }
        bool operator != (const CBitIterator& thus)
        {
            return !(*this == thus);
        }
    };

    CBitIterator begin()
    {
        return CBitIterator(*this, 0);
    }
    CBitIterator end()
    {
        return CBitIterator(*this, (*this).getsize() - 1);
    }
};

template <class T> CVector_t<T>::CVector_t(int b_size)
{
    size = b_size;

    try
    {
        data = new T[size];
    }
    catch (...)
    {
        throw MyException("In constructor CVector_t: line ","Memory isn't allocated in ctor.", __LINE__);
    }
}

template <class T> CVector_t<T>::CVector_t(const CVector_t<T>&thus)
{
    size = thus.size;
    try
    {
        data = new T[size];
    }
    catch(...)
    {
        throw MyException("In copy constructor CVector_t: line ","Memory isn't allocated in copy ctor.", __LINE__);
    }

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
    try
    {
        if (!(index >= 0 && index < size))
            throw MyException("Operator [] of class CVector_t: line ","Invalid index.", __LINE__);
        return data[index];
    }
    catch(MyException &ex)
    {
        throw ex;
    }
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
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator +: line ","Dimension of vectors is different.\n", __LINE__);

        CVector_t<T> v_r (size);

        int i;
        for (i = 0; i < size; i++)
        {
            v_r.data[i] = data[i] + v_1.data[i];
        }

        return v_r;
    }
    catch (MyException &ex)
    {
        throw ex;
    }
}

template <class T> CVector_t<T> CVector_t<T>::operator -(CVector_t<T> & v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator -: line ","Dimension of vectors is different.\n", __LINE__);
        CVector_t<T> v_r(size);
        int i;
        for (i = 0; i < size; i++)
        {
            v_r.data[i] = data[i] - v_1.data[i];
        }
        return v_r;
    }
    catch (MyException & ex)
    {
        throw ex;
    }
}

template <class T> void CVector_t<T>::operator += (CVector_t<T> &v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator +=: line ","Dimension of vectors is different.\n", __LINE__);
        int i;
        for (i = 0; i < size; i++)
        {
            data[i] += v_1.data[i];
        }
    }
    catch (MyException & ex)
    {
        throw ex;
    }
}

template <class T> void CVector_t<T>::operator -= (CVector_t<T> &v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator -=: line ","Dimension of vectors is different.\n", __LINE__);
        int i;
        for (i = 0; i < size; i++)
        {
            data[i] -= v_1.data[i];
        }
    }
    catch (MyException & ex)
    {
        throw ex;
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
    try
    {
        if (a == 0) throw MyException("In operator /: line ", "You try to divide by zero.", __LINE__);
        int i;
        CVector_t<T> v_r(size);
        for(i = 0; i < size; i++)
        {
            v_r.data[i] = data[i] / a;
        }
        return v_r;
    }
    catch (MyException &ex)
    {
        throw ex;
    }
}

template <class T> T CVector_t<T>::operator | (CVector_t<T> & v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator | : line ","Dimension of vectors is different.\n", __LINE__);
        int i;
        T G = 0;
        for(i = 0; i < size; i++)
        {
            G += data[i] * v_1.data[i];
        }
        return G;
    }
    catch(MyException &ex)
    {
        throw ex;
    }
}

template <class T> double CVector_t<T>::operator ^ (CVector_t<T> & v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator ^: line ","Dimension of vectors is different.\n", __LINE__);
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
        if (!COS <= 1) throw MyException ("Invalid cosine in operator ^. \n");
        return COS;
    }
    catch (MyException & ex)
    {
        throw ex;
    }
}

template <class T> int CVector_t<T>::operator > (CVector_t<T> & v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator >: line ","Dimension of vectors is different.\n", __LINE__);
        long double a = 0 , b = 0;

        int i;

        for(i = 0; i < size; i++)
        {
            a += data[i] * data[i];
            b += v_1.data[i] * v_1.data[i];
        }

        return (a > b) ? 1 : 0;
    }
    catch (MyException & ex)
    {
        throw ex;
    }
}

template <class T> int CVector_t<T>::operator < (CVector_t<T> & v_1)
{
    try
    {
        if (!(size == v_1.size)) throw MyException("In operator <: line ","Dimension of vectors is different.\n", __LINE__);

        long double a = 0 , b = 0;

        int i;

        for(i = 0; i < size; i++)
        {
            a += data[i] * data[i];
            b += v_1.data[i] * v_1.data[i];
        }

        return (a < b) ? 1 : 0;
    }
    catch (MyException & ex)
    {
        throw ex;
    }
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

template <class T> CVector_t<T> CVector_t<T>::operator ++ (int notused)
{
    CVector_t temp = *this;
    int i;
    for(i = 0; i < size; i++)
    {
        data[i]++;
    }
    return temp;
}

template <class T> CVector_t<T> CVector_t<T>::operator -- (int notused)
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
    stream << "(";
    for (i = 0; i < v.size; i++)
    {
        stream << v.data[i];
        if (i < v.size - 1)
            stream << ",";
    }
    stream << ")" << std::endl;
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
