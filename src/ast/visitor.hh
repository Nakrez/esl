/// date 17 Feb 2013
#ifndef AST_VISITOR_HH
# define AST_VISITOR_HH

# include <functional>

# include <misc/constness.hh>

# include <ast/fwd.hh>

namespace ast
{
    template <template <typename> class Constness>
    class GenVisitor : public std::unary_function<Ast, void>
    {
        public:
            GenVisitor() = default;
            virtual ~GenVisitor() = default;

            template <typename A> void visit(A* a);
            template <typename A> void visit(typename Constness<A>::type& a);

            virtual void operator()(typename Constness<Ast>::type&);
            virtual void operator()(typename Constness<AstList>::type&) = 0;

            virtual void operator()(typename Constness<DecList>::type&) = 0;
            virtual void operator()(typename Constness<IntExp>::type&) = 0;
            virtual void operator()(typename Constness<OpExp>::type&) = 0;
            virtual void operator()(typename Constness<StringExp>::type&) = 0;
            virtual void operator()(typename Constness<FunctionCallExp>::type&) = 0;
            virtual void operator()(typename Constness<ReturnExp>::type&) = 0;
            virtual void operator()(typename Constness<BreakExp>::type&) = 0;
            virtual void operator()(typename Constness<ContinueExp>::type&) = 0;
            virtual void operator()(typename Constness<NewExp>::type&) = 0;
            virtual void operator()(typename Constness<AssignExp>::type&) = 0;

            virtual void operator()(typename Constness<IfInstr>::type&) = 0;
            virtual void operator()(typename Constness<ElseInstr>::type&) = 0;
            virtual void operator()(typename Constness<WhileInstr>::type&) = 0;
            virtual void operator()(typename Constness<InstrList>::type&);
            virtual void operator()(typename Constness<ImportInstr>::type&) = 0;

            virtual void operator()(typename Constness<VarId>::type&) = 0;
            virtual void operator()(typename Constness<AttributVar>::type&) = 0;
            virtual void operator()(typename Constness<MethodCallVar>::type&) = 0;
            virtual void operator()(typename Constness<ModuleCallVar>::type&) = 0;
            virtual void operator()(typename Constness<ModuleAttributVar>::type&) = 0;
            virtual void operator()(typename Constness<ArrayVar>::type&) = 0;

            virtual void operator()(typename Constness<FunctionDec>::type&) = 0;
            virtual void operator()(typename Constness<VarDec>::type&) = 0;
            virtual void operator()(typename Constness<VarDecList>::type&);
            virtual void operator()(typename Constness<MethodDec>::type&) = 0;
            virtual void operator()(typename Constness<AttributDec>::type&) = 0;
            virtual void operator()(typename Constness<ClassDec>::type&) = 0;
    };

    typedef GenVisitor<misc::const_type> ConstVisitor;
    typedef GenVisitor<misc::nonconst_type> Visitor;
} // namespace ast

# include <ast/visitor.hxx>

#endif /* !AST_VISITOR_HH */
