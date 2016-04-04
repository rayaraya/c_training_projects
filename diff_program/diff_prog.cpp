#include "diff_prog.h"

Node::Node(type type_n, char type_op, Node* left, Node* right):
    type_node(type_n),
    left_(left),
    right_(right)
{
    data_ch = type_op;
}

Node::Node(type type_n, char type_var):
    type_node(type_n),
    left_(NULL),
    right_(NULL)
{
    data_ch = type_var;
}

Node::Node(type type_n, double val):
    type_node(type_n),
    left_(NULL),
    right_(NULL)
{
    val_ = val;
}

Node::~Node()
{
}

double Node::get_num()
{
    return val_;
}

char Node::get_opr()
{
    return data_ch;
}

char Node::get_var()
{
    return data_ch;
}

int Node::get_type()
{
    return type_node;
}

Tree::Tree(Node* root)
{
    root_ = root;
}

Node* Tree::get_root()
{
    return root_;
}

Tree::~Tree()
{
    //bypassing and clearing memory?
}

std::string read_string() //reads a line passing of generalized spaces
{
    char c;
    std::string str;
    do
    {
        if (!std::cin.get(c))
            break;
        if (!isspace(c))
            str += c;
    }
    while (c != '\n');
    return str;
}


Node* parse_in_tree(std::string str)
{
    int count_ex;
    unsigned int t, i;
    //std::cout << str << std::endl;
    //use it for print full process of parsing
    for(t = OP_1; t < NUMBER; t++)
    {
        for(i = 0, count_ex = 0; i < str.size(); i++)
        {
            if(str[i] == LP)
                count_ex++;
            else if(str[i] == RP)
                count_ex--;
            else if (t == OP_1 && !count_ex)
            {
                if (str[i] == '+')
                    {
                        Node* r = new Node(OP_1,'+', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
                        return r;
                    }
                if (str[i] == '-')
                    {
                        Node* r = new Node(OP_1,'+', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
                        return r;
                    }
            }
            else if (!count_ex)
            {
                if (str[i] == '*')
                    {
                       Node* r = new Node(OP_2, '*', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
                       return r;
                    }
                if (str[i] == '/')
                {
                    Node* r = new Node(OP_2, '/', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
                    return r;
                }
            }
        }
    }

    if(str[0] == '(' && str[str.size() - 1] == ')')
    {
        return parse_in_tree(str.substr( 1, str.size() - 2 ));
    }
    if (str[0] >= '0' && str[0] <= '9')
    {
        std::stringstream n_str(std::stringstream::in | std::stringstream::out);
        n_str << str;
        double data;
        n_str >> data;
        Node *r = new Node(NUMBER, data);
        return r;
    }
    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
    {
        std::stringstream n_str(std::stringstream::in | std::stringstream::out);
        n_str << str;
        char data;
        n_str >> data;
        Node *r = new Node(VARIABLE, data);
        return r;
    }
}
