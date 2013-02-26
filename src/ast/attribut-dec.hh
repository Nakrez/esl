/// date 17 Feb 2013
#ifndef ATTRIBUT_DEC_HH
# define ATTRIBUT_DEC_HH

# include <ast/dec.hh>
# include <ast/exp.hh>

# include <misc/visibility.hh>

namespace ast
{
    class AttributDec : public Dec
    {
        public:
            AttributDec(const yy::location& location,
                        const misc::symbol& name,
                        Exp* value,
                        misc::visibility visibility);
            ~AttributDec();

            misc::visibility visibility_get() const;
            void visibility_set(misc::visibility visibility);
            const Exp* value_get() const;
            Exp* value_get();

            virtual void accept(Visitor& visitor);

        protected:
            Exp* value_;
            misc::visibility visibility_;
    };
} // namespace ast

# include <ast/attribut-dec.hxx>

#endif /* !ATTRIBUT_DEC_HH */
