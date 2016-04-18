#include "diff_prog.h"

Node* copy(Node* v)
{
    $
    if (v == NULL)
        return NULL;
    switch((*v).get_type())
    {
    case OP_1:
        return new Node(OP_1, (*v).get_type_op(), copy((*v).left_), copy((*v).right_));
    case OP_2:
        return new Node(OP_2, (*v).get_type_op(), copy((*v).left_), copy((*v).right_));
    case NUMBER:
        return new Node(NUMBER, (*v).get_num());
    case VARIABLE:
        return new Node(VARIABLE, (*v).get_var());
    case FUNC:
        return new Node(FUNC, (*v).get_func(), copy((*v).right_));
    }
    return NULL;
}

Node* d(Node* n)
{
    $
    if(n == NULL)
        return NULL;
    //std::cout << "type = "  << (*n).get_type() << std::endl;
    switch((*n).get_type())
    {
    case OP_1:
        if((*n).get_type_op() == '+')
            return *d((*n).left_) + d((*n).right_);
        if((*n).get_type_op() == '-')
            return *d((*n).left_) - d((*n).right_);
    case OP_2:
        if((*n).get_type_op() == '*')
            return *(*d((*n).left_) * copy((*n).right_)) + (*d((*n).right_) * copy((*n).left_));
        if((*n).get_type_op() == '/')
            return *(*(*d((*n).left_) * copy((*n).right_)) - (*d((*n).right_) * copy((*n).left_))) /
            (*copy((*n).right_) * copy((*n).right_));
        if((*n).get_type_op() == '^')
        {
            if ((*((*n).right_)).get_type() == NUMBER)
            {
                return (*copy((*n).right_))*
                (*d((*n).left_) * (*copy((*n).left_) * (new Node(NUMBER, (double)((*((*n).right_)).get_num() - 1)))));
            }
            else
            {
                char dat[3] = "ln";
                return (*copy (n)) * d(*new Node(FUNC, dat, copy ((*n).left_)) * copy((*n).right_));
            }
        }
    case NUMBER:
        return new Node(NUMBER, (double)0);
    case VARIABLE:
        return new Node(NUMBER, (double)1);
    case FUNC:
        if (!strcmp((*n).get_func(), "ln"))
        {
            return *d((*n).right_) * (*new Node(NUMBER, (double) 1) / copy((*n).right_));
        }
        if (!strcmp((*n).get_func(), "tg"))
        {
            char dat[4] = "cos";
            return *d((*n).right_) * (*new Node(NUMBER, (double) 1) /
            new Node(OP_2, '^', new Node(FUNC, dat, copy((*n).right_)), new Node(NUMBER, (double)2)));
        }
        if (!strcmp((*n).get_func(), "ctg"))
        {
            char dat[4] = "sin";
            return *new Node(NUMBER, (double) -1) * (*d((*n).right_) * (*new Node(NUMBER, (double) 1) /
            new Node(OP_2, '^', new Node(FUNC, dat, copy((*n).right_)), new Node(NUMBER, (double)2))));
        }
        if (!strcmp((*n).get_func(), "sin"))
        {
            char dat[4] = "cos";
            return *d((*n).right_) * new Node(FUNC, dat, copy((*n).right_));
        }
        if (!strcmp((*n).get_func(), "cos"))
        {
            char dat[4] = "sin";
            return *new Node(NUMBER, (double) -1) * (*d((*n).right_) * new Node(FUNC, dat, copy((*n).right_)));
        }
    }
    return NULL;
}

Node* Node::operator + (Node* v)
{
    return new Node(OP_1, '+', this, v);
}

Node* Node::operator - (Node* v)
{
    return new Node(OP_1, '-', this, v);
}

Node* Node::operator * (Node* v)
{
    return new Node(OP_2, '*', this, v);
}

Node* Node::operator / (Node* v)
{
    return new Node(OP_2, '/', this, v);
}

