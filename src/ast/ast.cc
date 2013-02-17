#include "ast.hh"

namespace ast
{
    Ast::Ast(const yy::location& location)
        : location_(location)
    {}

    Ast::~Ast()
    {}
} // namespace ast
