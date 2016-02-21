#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>

int i_len = 20;

void command();

class CStack
{
private:
    double *data_;
    int size_;
    int avl_length;
public:
    int number = 0;
    CStack();
    ~CStack();
    void push(double val);
    double pop();
    int GetNum();
};

using namespace std;

int main()
{
    int com_1 = 0;
    int com_2 = 0;

    cout << "If you want to create a stack enter 1." << endl;
    cout << "If you want to close program enter 0." << endl;

    cin >> com_1;

    if (!com_1) return 0;

    while (com_1)
    {
        if (com_1 == 1)
        {
            CStack S1;
            command();
            cin >> com_1;
            if (com_1 == 2)
            {
                cout << "Please, enter a number of stack." << endl;
                cin >> com_2;
                S1.push(com_2);
                command();
            }
            if (com_2 == 3)
            {
                cout << "NUMBER:" << S1.pop() << endl;
                command();
            }
            if (!com_1)
            {
                S1.~CStack();
                return 0;
            }
        }
        cin >> com_1;
    }

    return 0;
}

CStack::CStack():
    size_ (0),
    avl_length(i_len)
{
    data_ = new double [i_len];
    number++;
}

CStack::~CStack()
{
    delete data_;
}

void CStack::push(double val)
{
    if (size_ == avl_length)
    {
        avl_length *= 2;
        data_ = (double*) realloc (data_, avl_length * sizeof(double));
    }

    data_[size_] = val;
    size_++;
}

double CStack::pop()
{
    return data_[size_--];
}

void command()
{
    cout << "If you want to close program enter 0." << endl;
    cout << "If you want to push a number enter 2 ." << endl;
    cout << "If you want to pop and print number enter 3." << endl;
    cout << "If you want to create new stack 1." << endl;
}

int CStack::GetNum()
{
    return number;
}
