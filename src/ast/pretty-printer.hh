#ifndef PRETTY_PRINTER_HH
# define PRETTY_PRINTER_HH

# include <iostream>

# include <ast/visitor.hh>

namespace ast
{
    class PrettyPrinter : public Visitor
    {
        public:
            using Visitor::operator();

            PrettyPrinter(std::ostream& stream);

            virtual void operator()(IntExp&);

        protected:
            std::ostream& stream_;
    };
} // namespace ast

#endif /* !PRETTY_PRINTER_HH */
