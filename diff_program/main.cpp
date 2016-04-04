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
    Tree v(parse_in_tree(re));
    return 0;
}

