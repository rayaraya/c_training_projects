#ifndef CVECTOR_H
#define CVECTOR_H



class CVector
{
private:
    int data_[5];
    int size_;
public:
    CVector();
    ~CVector();

    void print();

    int& operator[] (int index);
    CVector  operator +(CVector & v_1);
    CVector  operator -(CVector & v_1);
    void operator += (CVector & v_1);
    void operator -= (CVector & v_1);
    CVector & operator * (int a);
    CVector & operator / (int a);
    int operator | (CVector & v_1);
    double operator ^ (CVector & v_1);
    void val_vec ();
};

void init();

#endif // CVECTOR_H
