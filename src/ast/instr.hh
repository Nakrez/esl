#ifndef INSTR_HH
# define INSTR_HH

# include <ast/ast.hh>

namespace ast
{
    class Instr : public Ast
    {
        public:
            Instr(const yy::location& location);
            virtual ~Instr();
    };
} // namespace ast

#endif /* !INSTR_HH */
