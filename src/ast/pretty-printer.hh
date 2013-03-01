#ifndef PRETTY_PRINTER_HH
# define PRETTY_PRINTER_HH

# include <iostream>
# include <list>

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
            virtual void operator()(StringExp&);
            virtual void operator()(OpExp&);
            virtual void operator()(IfInstr&);
            virtual void operator()(ElseInstr&);
            virtual void operator()(WhileInstr&);
            virtual void operator()(InstrList&);
            virtual void operator()(VarId&);
            virtual void operator()(AttributVar&);
            virtual void operator()(FunctionDec&);
            virtual void operator()(VarDec&);

        protected:
            template<typename T, class U> void separate(std::list<T> list,
                                                        const U& sep);

        protected:
            std::ostream& stream_;
    };
} // namespace ast

#endif /* !PRETTY_PRINTER_HH */