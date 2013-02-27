#ifndef FWD_HH
# define FWD_HH

namespace ast
{
    class Ast;
    class Var;
    class VarId;
    class VarDec;
    class ImportDec;
    class FunctionDec;
    class AttributDec;
    class ExpList;
    class OpExp;
    class IntExp;
    class StringExp;
    class IfInstr;
    class ElseInstr;
    class WhileInstr;
    class Instr;
    template <class T>
    class AnyList;

    typedef AnyList<Instr> InstrList;
    typedef AnyList<VarDec> VarDecList;
} // namespace ast
#endif /* !FWD_HH */
