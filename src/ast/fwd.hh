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
    class ArrayVar;

    class VarDec;
    class FunctionDec;
    class AttributDec;

    class Exp;
    class OpExp;
    class IntExp;
    class StringExp;
    class FunctionCallExp;
    class ReturnExp;
    class BreakExp;
    class ContinueExp;
    class NewExp;
    class AssignExp;

    class Instr;
    class IfInstr;
    class ElseInstr;
    class WhileInstr;
    class ImportInstr;

    template <class T>
    class AnyList;

    typedef AnyList<Instr> InstrList;
    typedef AnyList<VarDec> VarDecList;
    typedef AnyList<Exp> ExpList;
    typedef AnyList<Ast> AstList;
} // namespace ast
#endif /* !FWD_HH */
