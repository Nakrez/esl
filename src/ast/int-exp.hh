#ifndef INT_EXP_HH
# define INT_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class IntExp : public Exp
    {
        public:
            IntExp(const yy::location& location,
                   int value);
            virtual ~IntExp();

            const int& value_get() const;
            int& value_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            int value_;
    };
} // namespace ast

# include <ast/int-exp.hxx>

#endif /* !INT_EXP_HH */
