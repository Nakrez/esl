#include <compile/command.hh>

namespace compile
{
    void internal_compile()
    {
        compile_ast(ast::main_ast).exit_on_error();
        delete ast::main_ast;
    }
} // namespace compile
