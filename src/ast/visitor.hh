/// date 17 Feb 2013
#ifndef VISITOR_HH
# define VISITOR_HH

# include <ast/fwd.hh>

namespace ast
{

    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(Ast&);

            virtual void operator()(IntExp&) = 0;
            virtual void operator()(OpExp&) = 0;
            virtual void operator()(StringExp&) = 0;
            virtual void operator()(FunctionCallExp&) = 0;
            virtual void operator()(ReturnExp&) = 0;
            virtual void operator()(BreakExp&) = 0;
            virtual void operator()(ContinueExp&) = 0;
            virtual void operator()(NewExp&) = 0;
            virtual void operator()(AssignExp&) = 0;

            virtual void operator()(IfInstr&) = 0;
            virtual void operator()(ElseInstr&) = 0;
            virtual void operator()(WhileInstr&) = 0;
            virtual void operator()(InstrList&) = 0;

            virtual void operator()(VarId&) = 0;
            virtual void operator()(AttributVar&) = 0;
            virtual void operator()(MethodCallVar&) = 0;
            virtual void operator()(ModuleCallVar&) = 0;
            virtual void operator()(ModuleAttributVar&) = 0;
            virtual void operator()(ArrayVar&) = 0;

            virtual void operator()(FunctionDec&) = 0;
            virtual void operator()(VarDec&) = 0;
    };
} // namespace ast

#endif /* !VISITOR_HH */
