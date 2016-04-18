#include "diff_prog.h"

void tex_doc(Node* root)
{
    std::string st;
    std::ofstream file_t;
    std::ifstream file_template;
    file_template.open ("tex_template.txt", std::ios::out);
    file_t.open("tex_test.txt", std::ios::in);
    if (!(file_t.is_open()))
        std::cout<< "File tex_template.txt isn't open for writing." << std::endl;
    if (!(file_t.is_open()))
        std::cout << "File tex_test.txt isn't open for writing." << std::endl;

    while (std::getline(file_template, st))
    {
        file_t << st << std::endl;
    }


    file_template.close();

    file_t <<"\n\n"<< "Expression: " << "$";

    std::string d = dump_tree_in_file(root);

    file_t << d << "$" << "\n\n" << "\\end{document}" ;

    file_t.close();
    file_template.close();
}
