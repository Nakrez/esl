#include <compile/libcompile.hh>

namespace compile
{
    execute::Executable* main_executable = nullptr;

    misc::Error compile_ast(ast::Ast* ast)
    {
        Compiler compiler;
        compiler(*ast);

        return compiler.error_get();
    }
} // namespace compile
