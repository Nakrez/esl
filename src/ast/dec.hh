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
            void name_set(const misc::symbol& name);

            virtual void accept(const Visitor& visitor) = 0;

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/dec.hxx>

#endif /* !DEC_HH */
