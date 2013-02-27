#include <ast/pretty-printer.hh>
#include <ast/all.hh>

namespace ast
{
    PrettyPrinter::PrettyPrinter(std::ostream& stream)
        : Visitor()
        , stream_(stream)
    {}

    void PrettyPrinter::operator()(IntExp& exp)
    {
        stream_ << exp.value_get();
    }

    void PrettyPrinter::operator()(StringExp& exp)
    {
        stream_ << "\"" << exp.value_get() << "\"";
    }

    void PrettyPrinter::operator()(OpExp& exp)
    {
        if (exp.rop_get())
        {
            stream_ << "(";
            exp.lop_get()->accept(*this);
            stream_ << " " << exp.str_op() << " ";
            exp.rop_get()->accept(*this);
            stream_ << ")";
        }
        else
        {
            stream_ << "(" << exp.str_op();
            exp.lop_get()->accept(*this);
            stream_ << ")";
        }
    }

    void PrettyPrinter::operator()(IfInstr& instr)
    {
        stream_ << "if (";
        instr.condition_get()->accept(*this);
        stream_ << ") then" << misc::incendl;
        instr.exp_true_get()->accept(*this);

        if (instr.exp_else_get())
        {
            stream_ << misc::decendl << "else" << misc::incendl;
            instr.exp_else_get()->accept(*this);
        }

        stream_ << misc::decendl << "end" << misc::iendl;
    }

    void PrettyPrinter::operator()(ElseInstr& instr)
    {
        instr.instr_list_get()->accept(*this);
    }

    void PrettyPrinter::operator()(WhileInstr& instr)
    {
        stream_ << "while (";
        instr.condition_get()->accept(*this);
        stream_ << ") do" << misc::incendl;
        instr.instr_list_get()->accept(*this);
        stream_ << misc::decendl << "end";
    }

    void PrettyPrinter::operator()(InstrList& list)
    {
        std::list<Instr*>::const_iterator it = list.list_get().begin();

        for ( ; it != list.list_get().end(); ++it)
        {
            if (it != list.list_get().begin())
                stream_ << misc::iendl;
            (*it)->accept(*this);
        }
    }

    void PrettyPrinter::operator()(VarId& var)
    {
        stream_ << var.name_get();
    }
} // namespace ast
