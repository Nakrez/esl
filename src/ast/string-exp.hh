#ifndef STRING_EXP_HH
# define STRING_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class StringExp : public Exp
    {
        public:
            StringExp(const yy::location& location,
                      const std::string& value);
            virtual ~StringExp();

            const std::string& value_get() const;
            std::string& value_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            std::string value_;
    };
} // namespace ast

# include <ast/string-exp.hxx>

#endif /* !STRING_EXP_HH */
