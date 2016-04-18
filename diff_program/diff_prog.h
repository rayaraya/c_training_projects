#ifndef DIFF_PROG_H
#define DIFF_PROG_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstring>
#include <cstdlib>

typedef int type;
//обработать pi и e
/*#define dL *((*n).left_)
#define dR *((*n).right_)
#define L ((*n).left_)
#define R ((*n).right_)
#define cR copy((*n).right_)
#define cL copy((*n).left_)*/
#define $ dump p(__LINE__, __FUNCTION__);

static int g = 0;
enum
{
    OP_1, //PLUS OR MINUS
    OP_2, //MUL OR DIV
    NUMBER,
    VARIABLE,
    FUNC,
    LP = '(', RP = ')'
};

class buf_tab
{
private:
    friend class dump;
    int tab;
public:
    buf_tab()
    {
        tab = 0;
    }
};

class dump
{
    int line_;
    char func_[30];
public:
    dump(int line, const char* func)
    {
        line_ = line;
        strcpy(func_, func);
        /*for(int i = 0; i < g; i++)
        {
            std::cout << " ";
        }
        std::cout << "LINE: " << line_ << " FUNCTION: "<< func_ << std::endl;*/
        g++;
    }
    ~dump()
    {
         //std::cout << "CLOSE FUNCTION:" << func_<< std::endl;
        g--;
    }
};

class Node
{
private:
    friend class Tree;
    type type_node;
    double val_;
    char data_str[4];
public:
    Node(type type_n, char type_op, Node* left, Node* right); //operator
    Node(type type_n, char type_var); //variable
    Node(type type_n, double val);//number
    Node(type type_n, char* data, Node* right);//function
    Node(const Node& thus);
    Node* left_;
    Node* right_;
    ~Node();
    double get_num();
    char get_opr();
    char get_var();
    int get_type();
    char get_type_op();
    char* get_func();
    Node* operator + (Node* v);
    Node* operator - (Node* v);
    Node* operator * (Node* v);
    Node* operator / (Node* v);
    void free_node()
    {
        if (this == NULL)
            return;
        type_node = 0;
        val_ = 0;
        delete [] data_str;
        delete this;
    }
};

class Tree
{
    Node* root_;
public:
    Tree(Node* root);
    Node* get_root();
    friend Node* parse_in_tree(std::string str);
    ~Tree();
    void free_tree(Node * v)
    {
        if (v == NULL)
            return;
        free_tree((*v).right_);
        free_tree((*v).left_);
        (*v).free_node();
    }
};

Node* parse_in_tree(std::string str);
std::string dump_tree_in_file(Node *n);

std::string read_string();

void dump_tree(Node *n);
Node* d(Node* n);
Node* copy(Node* v);
void tex_doc(Node* root);

#endif // DIFF_PROG_H
