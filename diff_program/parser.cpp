#include "diff_prog.h"

std::string read_string() //reads a line passing of generalized spaces
{
    $
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
    $
    int count_ex;
    unsigned int t, i;
    std::cout << str << std::endl;
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
                        Node* r = new Node(OP_1,'-', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
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
                 if (str[i] == '^')
                {
                    Node* r = new Node(OP_2, '^', parse_in_tree(str.substr(0, i)), parse_in_tree(str.substr(i + 1, str.size() - i)));
                    return r;
                }
            }
        }
    }

    if(str[0] == '(' && str[str.size() - 1] == ')')
    {
        return parse_in_tree(str.substr(1, str.size() - 2));
    }

    if (str[0] >= '0' && str[0] <= '9')
    {
        std::stringstream n_str(std::stringstream::in | std::stringstream::out);
        n_str << str;
        double data;
        n_str >> data;
        //std::cout << data << std::endl;
        Node *r = new Node(NUMBER, data);
        return r;
    }

    if (((str[0] >= 'a' && str[0] <= 'z') ||
         (str[0] >= 'A' && str[0] <= 'Z'))&&
        ((str.size() == 1) ||
        (str[1] >= '0' && str[1] <= '9')))
    {
        std::stringstream n_str(std::stringstream::in | std::stringstream::out);
        n_str << str;
        char data;
        n_str >> data;
        //std::cout << data << std::endl;
        Node *r = new Node(VARIABLE, data);
        return r;
    }
    else
    {
        char f_cmp[3];
        std::string s = str.substr(0, 3);
        strcpy(f_cmp, s.c_str());

        if (!strcmp(f_cmp, "cos") || !strcmp(f_cmp, "sin") || !strcmp(f_cmp, "ctg"))
        {
            //std::cout << f_cmp << std::endl;
            Node *r = new Node(FUNC, f_cmp, parse_in_tree(str.substr(3, str.size() - 3)));
            return r;
        }
        if ((!strcmp(f_cmp, "ln(")) || (!strcmp(f_cmp, "tg(")))
        {
            char data[3];
            data[0] = f_cmp[0];
            data[1] = f_cmp[1];
            //std::cout << data << std::endl;
            Node *r = new Node(FUNC, data, parse_in_tree(str.substr(2, str.size() - 1)));
            return r;
        }
    }
    std::cout << "You enter wrong data!\n"; //there will be another error handling
    exit(0);
    return NULL;
}
