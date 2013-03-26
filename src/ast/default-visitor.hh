/// @date 26/03/2013

#ifndef AST_DEFAULT_VISITOR_HH
# define AST_DEFAULT_VISITOR_HH

# include <misc/constness.hh>

# include <ast/visitor.hh>

namespace ast
{
    template <template <typename> class Constness>
    class GenDefaultVisitor : public virtual GenVisitor<Constness>
    {
        public:
            using GenVisitor<Constness>::operator();

            GenDefaultVisitor() = default;
            virtual ~GenDefaultVisitor();

            virtual void operator()(typename Constness<AstList>::type&);

            virtual void operator()(typename Constness<DecList>::type&);
            virtual void operator()(typename Constness<IntExp>::type&);
            virtual void operator()(typename Constness<OpExp>::type&);
            virtual void operator()(typename Constness<StringExp>::type&);
            virtual void operator()(typename Constness<FunctionCallExp>::type&);
            virtual void operator()(typename Constness<ReturnExp>::type&);
            virtual void operator()(typename Constness<BreakExp>::type&);
            virtual void operator()(typename Constness<ContinueExp>::type&);
            virtual void operator()(typename Constness<NewExp>::type&);
            virtual void operator()(typename Constness<AssignExp>::type&);

            virtual void operator()(typename Constness<IfInstr>::type&);
            virtual void operator()(typename Constness<ElseInstr>::type&);
            virtual void operator()(typename Constness<WhileInstr>::type&);
            virtual void operator()(typename Constness<InstrList>::type&);
            virtual void operator()(typename Constness<ImportInstr>::type&);

            virtual void operator()(typename Constness<VarId>::type&);
            virtual void operator()(typename Constness<AttributVar>::type&);
            virtual void operator()(typename Constness<MethodCallVar>::type&);
            virtual void operator()(typename Constness<ModuleCallVar>::type&);
            virtual void operator()(typename Constness<ModuleAttributVar>::type&);
            virtual void operator()(typename Constness<ArrayVar>::type&);

            virtual void operator()(typename Constness<FunctionDec>::type&);
            virtual void operator()(typename Constness<VarDec>::type&);
            virtual void operator()(typename Constness<VarDecList>::type&);
            virtual void operator()(typename Constness<MethodDec>::type&);
            virtual void operator()(typename Constness<AttributDec>::type&);
            virtual void operator()(typename Constness<ClassDec>::type&);
    };

    typedef GenDefaultVisitor<misc::const_type> DefaultConstVisitor;
    typedef GenDefaultVisitor<misc::nonconst_type> DefaultVisitor;
} // namespace ast

# include <ast/default-visitor.hxx>

#endif /* !AST_DEFAULT_VISITOR_HH */
