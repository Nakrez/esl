#ifndef CLASS_DEC_HH
# define CLASS_DEC_HH

# include <misc/symbol.hh>

# include <ast/fwd.hh>
# include <ast/dec.hh>

namespace ast
{
    class ClassDec : public Dec
    {
        public:
            ClassDec(const yy::location& location,
                     const misc::symbol& name,
                     IdList* inherit,
                     DecList* components);
            virtual ~ClassDec();

            const IdList* inherit_get() const;
            IdList* inherit_get();

            const DecList* components_get() const;
            DecList* components_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            IdList* inherit_;
            DecList* components_;
    };
} // namespace ast

# include <ast/class-dec.hxx>

#endif /* !CLASS_DEC_HH */
