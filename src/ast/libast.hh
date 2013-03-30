#ifndef LIBAST_HH
# define LIBAST_HH

# include <misc/error.hh>

# include <ast/fwd.hh>

namespace ast
{
    extern Ast* main_ast;

    misc::Error pretty_print(Ast* ast);
} // namespace ast

#endif /* !LIBAST_HH */
