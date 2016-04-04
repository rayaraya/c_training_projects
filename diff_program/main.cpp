#include "diff_prog.h"

int main()
{
    std::string re;
    re = read_string();
    Tree v(parse_in_tree(re));
    return 0;
}

