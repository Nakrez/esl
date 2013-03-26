/// date 17 Feb 2013
#ifndef EXP_HH
# define EXP_HH

# include <ast/instr.hh>

namespace ast
{
    class Exp : public Instr
    {
        public:
            Exp(const yy::location& location);

            virtual void accept(Visitor& visitor) = 0;
            virtual void accept(ConstVisitor& visitor) const = 0;
    };
}// namespace ast

#endif /* !EXP_HH */
