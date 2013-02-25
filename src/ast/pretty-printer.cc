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

    void PrettyPrinter::operator()(IdExp& exp)
    {
        stream_ << exp.name_get();
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
        stream_ << ") then" << std::endl;
        instr.exp_true_get()->accept(*this);

        if (instr.exp_else_get())
        {
            stream_ << "else" << std::endl;
            instr.exp_else_get()->accept(*this);
        }

        stream_ << "end" << std::endl;
    }

    void PrettyPrinter::operator()(ElseInstr& instr)
    {
        instr.instr_list_get()->accept(*this);
    }

    void PrettyPrinter::operator()(InstrList& list)
    {
        for (auto elem : list.list_get())
        {
            elem->accept(*this);
            stream_ << std::endl;
        }
    }
} // namespace ast
