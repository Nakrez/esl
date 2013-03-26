#ifndef PRETTY_PRINTER_HH
# define PRETTY_PRINTER_HH

# include <iostream>
# include <list>

# include <misc/indent.hh>

# include <ast/default-visitor.hh>

namespace ast
{
    class PrettyPrinter : public DefaultConstVisitor
    {
        public:
            using DefaultConstVisitor::operator();

            PrettyPrinter(std::ostream& stream);

            virtual void operator()(const AstList&);

            virtual void operator()(const IntExp&);
            virtual void operator()(const StringExp&);
            virtual void operator()(const OpExp&);
            virtual void operator()(const FunctionCallExp&);
            virtual void operator()(const ReturnExp&);
            virtual void operator()(const BreakExp&);
            virtual void operator()(const ContinueExp&);
            virtual void operator()(const NewExp&);
            virtual void operator()(const AssignExp&);

            virtual void operator()(const IfInstr&);
            virtual void operator()(const ElseInstr&);
            virtual void operator()(const WhileInstr&);
            virtual void operator()(const InstrList&);
            virtual void operator()(const ImportInstr&);

            virtual void operator()(const VarId&);
            virtual void operator()(const AttributVar&);
            virtual void operator()(const MethodCallVar&);
            virtual void operator()(const ModuleCallVar&);
            virtual void operator()(const ModuleAttributVar&);
            virtual void operator()(const ArrayVar&);

            virtual void operator()(const FunctionDec&);
            virtual void operator()(const VarDec&);
            virtual void operator()(const MethodDec&);
            virtual void operator()(const AttributDec&);
            virtual void operator()(const ClassDec&);
            virtual void operator()(const DecList&);

        protected:
            template<typename T, class U> void separate(std::list<T> list,
                                                        const U& sep);

        protected:
            std::ostream& stream_;
    };
} // namespace ast

#endif /* !PRETTY_PRINTER_HH */
