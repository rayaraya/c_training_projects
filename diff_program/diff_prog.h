#ifndef DIFF_PROG_H
#define DIFF_PROG_H

#include <iostream>
#include <cstring>
#include <sstream>
//нужна штука делающая с помощью дефайнов новое дерево пройзводной
typedef int type;

enum
{
    OP_1, //PLUS OR MINUS
    OP_2, //MUL OR DIV
    NUMBER,
    VARIABLE,
    FUNC,
    LP = '(', RP = ')'
};

class Node
{
private:
    friend class Tree;
    type type_node;
    Node* left_;
    Node* right_;
    double val_;
    char data_str[4];
public:
    Node(type type_n, char type_op, Node* left, Node* right); //operator
    Node(type type_n, char type_var); //variable
    Node(type type_n, double val);//number
    Node(type type_n, char* data, Node* right);//function
    ~Node();
    double get_num();
    char get_opr();
    char get_var();
    int get_type();
};


class Tree
{
private:
    Node* root_;
public:
    Tree(Node* root);
    Node* get_root();
    friend Node* parse_in_tree(std::string str);
    ~Tree();
};

Node* parse_in_tree(std::string str);

std::string read_string();

#endif // DIFF_PROG_H
