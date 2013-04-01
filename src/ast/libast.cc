#include <ast/libast.hh>
#include <ast/all.hh>
#include <ast/pretty-printer.hh>

namespace ast
{
    Ast* main_ast = nullptr;

    misc::Error pretty_print(Ast* ast)
    {
        if (!ast)
            return misc::Error() << misc::Error::OTHER
                                 << "null ast provided" << std::endl;

        PrettyPrinter printer(std::cout);
        printer(*ast);
        std::cout << std::endl;

        return misc::Error();
    }
} // namespace ast
