#ifndef FWD_HH
# define FWD_HH

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
    class IfInstr;
    class ElseInstr;
    class WhileInstr;
    class Instr;
    template <class T>
    class AnyList;

    typedef AnyList<Instr> InstrList;
} // namespace ast
#endif /* !FWD_HH */
