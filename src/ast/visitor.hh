/// date 17 Feb 2013
#ifndef VISITOR_HH
# define VISITOR_HH

namespace ast
{
    class Ast;
    class VarDec;
    class VarDecList;
    class ImportDec;
    class FunctionDec;
    class AttributDec;
    class ExpList;
    class OpExp;
    class IfExp;

    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(Ast&) = 0;
            virtual void operator()(VarDec&) = 0;
            virtual void operator()(VarDecList&) = 0;
            virtual void operator()(ImportDec&) = 0;
            virtual void operator()(FunctionDec&) = 0;
            virtual void operator()(AttributDec&) = 0;
            virtual void operator()(OpExp&) = 0;
            virtual void operator()(IfExp&) = 0;
            virtual void operator()(ExpList&) = 0;
    };
} // namespace ast

#endif /* !VISITOR_HH */
