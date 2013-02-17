#ifndef DEC_HH
# define DEC_HH

# include <ast/ast.hh>
# include <misc/symbol.hh>

namespace ast
{
    class Dec : public Ast
    {
        public:
            Dec(const yy::location& location,
                const misc::symbol& name);

            const misc::symbol& name_get() const;
            void name_set(const misc::symbol& name);

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/dec.hxx>

#endif /* !DEC_HH */
