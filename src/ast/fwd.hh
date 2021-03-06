#ifndef AST_FWD_HH
# define AST_FWD_HH

# include <list>

# include <misc/symbol.hh>
# include <misc/constness.hh>

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

    class Dec;
    class VarDec;
    class FunctionDec;
    class AttributDec;
    class MethodDec;
    class ClassDec;

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
    typedef AnyList<Dec> DecList;
    typedef AnyList<Exp> ExpList;
    typedef AnyList<Ast> AstList;

    typedef std::list<misc::symbol> IdList;

    template <template <typename> class Constness>
    class GenVisitor;

    typedef GenVisitor<misc::const_type> ConstVisitor;
    typedef GenVisitor<misc::nonconst_type> Visitor;
} // namespace ast

#endif /* !AST_FWD_HH */
