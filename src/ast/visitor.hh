#ifndef VISITOR_HH
# define VISITOR_HH

# include <ast/all.hh>

namespace ast
{
    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(Ast&) = 0;
    };
} // namespace ast

#endif /* !VISITOR_HH */
