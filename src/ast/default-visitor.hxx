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
    GenDefaultVisitor<Constness>::operator()(typename Constness<AstList>::type& l)
    {
        for (auto elem : l.list_get())
            this->visit(elem);
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<DecList>::type& l)
    {
        for (auto elem : l.list_get())
            this->visit(elem);
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<IntExp>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<OpExp>::type& e)
    {
        this->visit(e.lop_get());
        this->visit(e.rop_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<StringExp>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<FunctionCallExp>::type& e)
    {
        this->visit(e.args_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ReturnExp>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<BreakExp>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ContinueExp>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<NewExp>::type& e)
    {
        this->visit(e.exp_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AssignExp>::type& e)
    {
        this->visit(e.var_get());
        this->visit(e.exp_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<IfInstr>::type& i)
    {
        this->visit(i.condition_get());
        this->visit(i.exp_true_get());
        this->visit(i.exp_else_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ElseInstr>::type& i)
    {
        this->visit(i.instr_list_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<WhileInstr>::type& i)
    {
        this->visit(i.instr_list_get());
        this->visit(i.condition_get());

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
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<VarId>::type&)
    {}

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AttributVar>::type& v)
    {
        v.call_var_get().accept(*this);
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<MethodCallVar>::type& v)
    {
        this->visit(v.var_get());
        this->visit(v.call_get());

    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ModuleCallVar>::type& v)
    {
        this->visit(v.var_get());
        this->visit(v.call_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ModuleAttributVar>::type& v)
    {
        this->visit(v.var_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ArrayVar>::type& v)
    {
        this->visit(v.var_get());
        this->visit(v.exp_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<FunctionDec>::type& d)
    {
        this->visit(d.args_get());
        this->visit(d.body_get());

    }

    template <template <typename> class Constness>
    void GenDefaultVisitor<Constness>::operator()(typename Constness<VarDec>::type& v)
    {
        this->visit(v.exp_get());
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
    GenDefaultVisitor<Constness>::operator()(typename Constness<MethodDec>::type& d)
    {
        this->visit(d.args_get());
        this->visit(d.body_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<AttributDec>::type& d)
    {
        this->visit(d.value_get());
    }

    template <template <typename> class Constness>
    void
    GenDefaultVisitor<Constness>::operator()(typename Constness<ClassDec>::type& d)
    {
        this->visit(d.components_get());
    }
} // namespace ast

#endif /* !AST_DEFAULT_VISITOR_HXX */
