#ifndef PRETTY_PRINTER_HH
# define PRETTY_PRINTER_HH

# include <iostream>

# include <ast/visitor.hh>

namespace ast
{
    class PrettyPrinter : public Visitor
    {
        public:
            PrettyPrinter(std::ostream& stream);

            virtual void operator()(VarDec&) = 0;
            virtual void operator()(VarDecList&) = 0;
            virtual void operator()(ImportDec&) = 0;
            virtual void operator()(FunctionDec&) = 0;
            virtual void operator()(AttributDec&) = 0;
            virtual void operator()(OpExp&) = 0;
            virtual void operator()(IfExp&) = 0;
            virtual void operator()(ExpList&) = 0;

        protected:
            std::ostream& stream_;
    };
} // namespace ast

#endif /* !PRETTY_PRINTER_HH */
