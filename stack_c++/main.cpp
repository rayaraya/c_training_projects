#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>

class CStack
{
private:
    double *data_;
    int size_;
    int avl_length;
    static int number;
public:
    CStack();
    ~CStack();
    void push(double val);
    double pop();
    static int GetNum();
    void print();
};

void command();

int CStack::number = 0;
int i_len = 20;


int main()
{
    int com_1 = 0;
    int com_2 = 0;

    std::cout << "If you want to close program enter 0." << std::endl;
    std::cout << "If you want to create new stack 1." << std::endl;

    std::cin >> com_1;

    while (com_1 > 1 || com_1 < 0)
    {
        std::cout << "Incorrect command, please enter again." << std::endl;
        std::cout << "If you want to close program enter 0." << std::endl;
        std::cout << "If you want to create new stack 1." << std::endl;
        std::cin >> com_1;
    }

    if (com_1)
    {
        CStack S1;
        if(S1.GetNum() >= 4)
        {
            std::cout << "You create too many stacks." << std::endl;
            return 0;
        }

        command();

        std::cin >> com_2;

        while(com_2)
        {
            if (com_2 == 2)
            {
                std::cout << "Please enter number." << std::endl;
                std::cin >> com_1;
                S1.push(com_1);
                command();
            }

            if (com_2 == 3)
            {
                com_1 = S1.pop();
                command();
            }

            if (com_2 == 4)
            {
                std::cout << "Result: ";
                S1.print();
                std::cout << "\n";
                command();
            }

            if (com_2 > 4 || com_2 < 2)
            {
                std::cout << "Incorrect command, please enter again." << std::endl;
                command();
            }
            std::cin >> com_2;
        }
    }

    return 0;
}

CStack::CStack():
    size_ (0),
    avl_length(i_len)
{
    data_ = new double [i_len];
    assert(data_ != NULL);
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
    assert(data_ != NULL);

    data_[size_] = val;
    size_++;
}

double CStack::pop()
{
    double a;
    std::cout << "Result: ";
    if (size_ == 0)
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    a = data_[size_ - 1];
    size_--;
    std::cout << a << std::endl;
    return a;
}

void command()
{
    std::cout << "If you want to close program enter 0." << std::endl;
    std::cout << "If you want to push a number enter 2 ." << std::endl;
    std::cout << "If you want to pop and print number enter 3." << std::endl;
    std::cout << "If you want to print all stack content enter 4." << std::endl;
}

int CStack::GetNum()
{
    return number;
}

void CStack::print()
{
    if (size_== 0)
    {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    int i;
    double b;

    for (i = size_; i > 0; i--)
    {
        b = (double) data_[i - 1];
        std::cout << b;
        std::cout << " ";
    }
}

