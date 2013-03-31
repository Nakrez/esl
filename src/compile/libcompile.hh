#ifndef LIBCOMPILE_HH
# define LIBCOMPILE_HH

# include <misc/error.hh>

# include <ast/libast.hh>

# include <compile/compiler.hh>

# include <execute/executable.hh>

namespace compile
{
    extern execute::Executable* main_executable;

    misc::Error compile_ast(ast::Ast* ast);
} // namespace compile

#endif /* !LIBCOMPILE_HH */
