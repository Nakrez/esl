/// @date 26/03/2013

#ifndef AST_DEFAULT_VISITOR_HXX
# define AST_DEFAULT_VISITOR_HXX

# include <ast/default-visitor.hh>

namespace ast
{

    template <template <typename> class Constness>
    GenDefaultVisitor<Constness>::~GenDefaultVisitor()
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AstList>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<DecList>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<IntExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<OpExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<StringExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<FunctionCallExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ReturnExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<BreakExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ContinueExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<NewExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AssignExp>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<IfInstr>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ElseInstr>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<WhileInstr>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<InstrList>::type& l)
    {
        for (auto elem : l.list_get())
            this->visit(elem);
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ImportInstr>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<VarId>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AttributVar>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<MethodCallVar>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ModuleCallVar>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ModuleAttributVar>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ArrayVar>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<FunctionDec>::type&)
    {

    }

    template <template <typename> class Constness>
    void GenDefaultVisitor<Constness>::operator()(typename Constness<VarDec>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<VarDecList>::type& l)
    {
        for (auto elem : l.list_get())
            this->visit(elem);
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<MethodDec>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AttributDec>::type&)
    {

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ClassDec>::type&)
    {

    }
} // namespace ast

#endif /* !AST_DEFAULT_VISITOR_HXX */
