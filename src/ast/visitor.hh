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
            virtual void operator()(InstrList&) = 0;
            virtual void operator()(IntExp&) = 0;
            virtual void operator()(IdExp&) = 0;
            virtual void operator()(OpExp&) = 0;
            virtual void operator()(IfInstr&) = 0;
            virtual void operator()(ElseInstr&) = 0;
            virtual void operator()(WhileInstr&) = 0;
            virtual void operator()(StringExp&) = 0;
    };
} // namespace ast

#endif /* !VISITOR_HH */
