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
    class IntExp;
    class StringExp;
    class IdExp;
    class IfExp;
    class Instr;
    template <class T>
    class AnyList;
    typedef AnyList<Instr> InstrList;

    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(Ast&);
            virtual void operator()(AnyList<Instr>&);
            virtual void operator()(IntExp&) = 0;
    };
} // namespace ast

#endif /* !VISITOR_HH */
