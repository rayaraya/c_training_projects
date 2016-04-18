#include "diff_prog.h"

/*
tree have the following func:
-: +, -, /, *
-: ^ that operation with div and mul priority
-: sin, cos, ctg, tg, ln
e and pi = p : will be processed separately from the expression tree
*/
int main()
{
    std::string re;
    re = read_string();
    std::cout<< "Process of parse: " << std::endl;
    Tree v(parse_in_tree(re));
    std::cout << "Expression: ";
    dump_tree(v.get_root());
    Tree diff(d(v.get_root()));
    std::cout << std::endl << "Diff expression: ";
    dump_tree(diff.get_root());
    tex_doc(v.get_root());
    return 0;
}

