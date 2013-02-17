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

            virtual void accept(Visitor& visitor);

            const std::string& value_get() const;

        protected:
            std::string value_;
    };
} // namespace ast

# include <ast/string-exp.hxx>

#endif /* !STRING_EXP_HH */
