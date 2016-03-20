#ifndef INT_OR_H
#define INT_OR_H
#include <iostream>

template <typename T = int>
class Int_or
{
    private:
        int *data;
        char *mark;
        int size;
        T reserve;
    public:
        Int_or(int n_size);
        Int_or(const Int_or &thus);
        ~Int_or();

    T& operator[] (int index);

    Int_or<T> operator = (const Int_or &thus);

    template <class X> friend std::istream & operator >>(std::istream & stream, Int_or<X> & v);
    template <class X> friend std::ostream & operator <<(std::ostream & stream, Int_or<X> & v);
};

template <typename T> Int_or<T>::Int_or(int n_size)
{
    size = n_size;
    data = new int[size];
    int i;
    mark = new char[size];

    for(i = 0; i < size; i++)
    {
        data[i] = 0;
        mark[i] = 0;
    }
}

template <typename T> Int_or<T>::Int_or(const Int_or &thus)
{
    size = thus.size;
    data = new int[size];
    mark = new char[size];
    int i;
    for(i = 0; i < size; i++)
        {
            data[i] = thus.data[i];
            mark[i] = thus.mark[i];
        }
}

template <typename T> Int_or<T>::~Int_or()
{
    delete[] data;
    delete[] mark;
}

template <typename T> T& Int_or<T>::operator[] (int index)
{
    int i = index;
    T val = 0;

    if(!mark[i])
    {
        while(!mark[i] && i)
        {
            i--;
        }
    }
    else
    {
        val = data[i];
        return val;
    }

    int j = i + 1;

    while(!mark[j] && j < size)
    {
        j++;
    }
    val = (double)((data[j] - data[i])/(j - i))*(index - i) + data[i];
    return val;
}

template <typename T> Int_or<T> Int_or<T>::operator = (const Int_or &thus)
{
    int i;
    for(i = 0; i < size; i++)
        {
            data[i] = thus.data[i];
            mark[i] = thus.mark[i];
        }
    return *this;
}

template <class X> std::istream & operator >>(std::istream & stream, Int_or<X> & v)
{
    std::cout << "You should enter first and last coordinates." << "\n\n";
    std::cout << "Please, first enter index and later value, all index are positive but less then " << v.size << ".\n\n";
    std::cout << "For exit enter a -1." << "\n\n";

    std::cout << "Enter first: data[0] = ";
    stream >> v.data[0];
    v.mark[0] = 1;
    std::cout << std::endl;

    std::cout << "Enter first: data[" << v.size - 1 <<"] = ";
    stream >> v.data[v.size - 1];
    v.mark[v.size - 1] = 1;
    std::cout << std::endl;
    int i = 0;

    while (i != -1)
    {
        std::cin >> i;
        std::cout << "\n";

        if(i >= 0 && i < v.size)
        {
            stream >> v.data[i];
            v.mark[i] = 1;
        }
        else
            if (i != -1)
                std::cout << "You entered incorrect index. Please enter again." << "\n";
    }

    return stream;
}

template <class X> std::ostream & operator <<(std::ostream & stream, Int_or<X> & v)
{
    int i;

    for(i = 0; i < v.size; i++)
    {
        if (v.mark[i])
            stream << v.data[i] << " " << std::endl;
    }
    return stream;
}
#endif // INT_OR_H
