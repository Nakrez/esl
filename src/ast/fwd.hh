#ifndef FWD_HH
# define FWD_HH

namespace ast
{
    class Ast;

    class Var;
    class VarId;
    class AttributVar;
    class MethodCallVar;
    class ModuleCallVar;
    class ModuleAttributVar;

    class VarDec;
    class ImportDec;
    class FunctionDec;
    class AttributDec;

    class Exp;
    class OpExp;
    class IntExp;
    class StringExp;
    class FunctionCallExp;
    class ReturnExp;

    class Instr;
    class IfInstr;
    class ElseInstr;
    class WhileInstr;

    template <class T>
    class AnyList;

    typedef AnyList<Instr> InstrList;
    typedef AnyList<VarDec> VarDecList;
    typedef AnyList<Exp> ExpList;
} // namespace ast
#endif /* !FWD_HH */
