#include "diff_prog.h"

Node::Node(type type_n, char type_op, Node* left, Node* right):
    type_node(type_n),
    left_(left),
    right_(right)
{
    $
    data_str[0] = type_op;
}

Node::Node(type type_n, char type_var):
    type_node(type_n),
    left_(NULL),
    right_(NULL)
{
    $
    data_str[0] = type_var;
}

Node::Node(type type_n, double val):
    type_node(type_n),
    left_(NULL),
    right_(NULL)
{
    $
    val_ = val;
}

Node::Node(type type_n, char* data, Node* right):
    type_node(type_n),
    left_(NULL),
    right_(right)
{
    $
    strcpy(data_str ,data);
}

Node::Node(const Node& thus)
{
    $
    left_ = thus.left_;
    right_ = thus.right_;
    type_node = thus.type_node;
    val_ = thus.val_;
    strcpy(data_str, thus.data_str);
}

Node::~Node()
{}

double Node::get_num()
{
    $
    return val_;
}

char Node::get_opr()
{
    $
    return data_str[0];
}

char Node::get_var()
{
    $
    return data_str[0];
}

int Node::get_type()
{
    $
    return type_node;
}

char Node::get_type_op()
{
    return data_str[0];
}

Tree::Tree(Node* root)
{
    root_ = root;
}

Node* Tree::get_root()
{
    return root_;
}

char* Node::get_func()
{
    return data_str;
}


void dump_tree(Node *n)
{
    $
    if (n == NULL)
        return;
    if ((*n).get_type() == OP_2 )
        std::cout << "(";
    dump_tree(n -> left_);
    if ((*n).get_type() == OP_2)
        std::cout << ")";
    //std::cout <<"type node:"<<  (*n).get_type() << std::endl;
    switch((*n).get_type())
    {
    case NUMBER:
        std::cout << (*n).get_num();
        break;
    case VARIABLE:
        std::cout << (*n).get_var();
        break;
    case OP_1:
        std::cout << (*n).get_opr();
        break;
    case OP_2:
        std::cout << (*n).get_opr();
        std::cout << "(";
        break;
    case FUNC:
        std::cout << (*n).get_func();
        std::cout << "(";
        break;
    }
    dump_tree(n -> right_);
    if ((*n).get_type() == OP_2 || (*n).get_type() == FUNC)
        std::cout << ")";
}

std::string dump_tree_in_file(Node *n)
{
    $
    std::string ff;
    if (n == NULL)
    {
        //ff = ff + "\n";
        return ff;
    }
    if ((*n).get_type() == OP_2 )
        ff += "(";
    ff += dump_tree_in_file(n -> left_);
    if ((*n).get_type() == OP_2)
        ff += ")";
    //std::cout <<"type node:"<<  (*n).get_type() << std::endl;
    switch((*n).get_type())
    {
    case NUMBER:
        {
            std::ostringstream sstream;
            sstream << (*n).get_num();
            ff += sstream.str();
            break;
        }
    case VARIABLE:
        ff += (*n).get_var();
        break;
    case OP_1:
        ff += (*n).get_opr();
        break;
    case OP_2:
        ff += (*n).get_opr();
        ff += "(";
        break;
    case FUNC:
        ff += (*n).get_func();
        ff += "(";
        break;
    }
    ff += dump_tree_in_file(n -> right_);
    if ((*n).get_type() == OP_2 || (*n).get_type() == FUNC)
        ff +=")";
    return ff;
}

Tree::~Tree()
{
    if (root_ == NULL)
        return;
    free_tree(root_);
}
