/// date 17 Feb 2013
#ifndef ATTRIBUT_DEC_HH
# define ATTRIBUT_DEC_HH

# include <ast/var-dec.hh>

# include <misc/visibility.hh>

namespace ast
{
    class AttributDec : public VarDec
    {
        public:
            AttributDec(const yy::location& location,
                        const misc::symbol& name,
                        Exp* value,
                        misc::visibility visibility);
            ~AttributDec();

            misc::visibility visibility_get() const;
            void visibility_set(misc::visibility visibility);

        protected:
            misc::visibility visibility_;
    };
} // namespace ast

#endif /* !ATTRIBUT_DEC_HH */
