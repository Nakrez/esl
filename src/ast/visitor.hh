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
    };
} // namespace ast

#endif /* !VISITOR_HH */
