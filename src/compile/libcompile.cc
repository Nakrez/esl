#include <compile/libcompile.hh>

namespace compile
{
    execute::Executable* main_executable = nullptr;

    misc::Error compile_ast(ast::Ast* ast)
    {
        Compiler compiler;
        compiler(*ast);

        main_executable = compiler.exec_get();

        return compiler.error_get();
    }
} // namespace compile
