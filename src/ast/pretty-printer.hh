#ifndef PRETTY_PRINTER_HH
# define PRETTY_PRINTER_HH

# include <iostream>

# include <ast/visitor.hh>
# include <misc/indent.hh>

namespace ast
{
    class PrettyPrinter : public Visitor
    {
        public:
            using Visitor::operator();

            PrettyPrinter(std::ostream& stream);

            virtual void operator()(IntExp&);
            virtual void operator()(IdExp&);
            virtual void operator()(StringExp&);
            virtual void operator()(OpExp&);
            virtual void operator()(IfInstr&);
            virtual void operator()(ElseInstr&);
            virtual void operator()(InstrList&);

        protected:
            std::ostream& stream_;
    };
} // namespace ast

#endif /* !PRETTY_PRINTER_HH */
