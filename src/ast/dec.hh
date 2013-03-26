/// date 17 Feb 2013
#ifndef DEC_HH
# define DEC_HH

# include <ast/var.hh>
# include <misc/symbol.hh>

namespace ast
{
    class Dec : public Var
    {
        public:
            Dec(const yy::location& location,
                const misc::symbol& name);
            virtual ~Dec();

            const misc::symbol& name_get() const;
            misc::symbol& name_get();

            virtual void accept(Visitor& visitor) = 0;
            virtual void accept(ConstVisitor& visitor) const = 0;

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/dec.hxx>

#endif /* !DEC_HH */
