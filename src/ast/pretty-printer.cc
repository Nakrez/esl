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

    void PrettyPrinter::operator()(FunctionCallExp& exp)
    {
        stream_ << exp.name_get() << "(";
        separate(exp.args_get()->list_get(), ", ");
        stream_ << ")";
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
        separate(list.list_get(), misc::iendl);
    }

    void PrettyPrinter::operator()(VarId& var)
    {
        stream_ << var.name_get();
    }

    void PrettyPrinter::operator()(AttributVar& var)
    {
        var.call_var_get().accept(*this);
        stream_ << "->" << var.name_get();
    }

    void PrettyPrinter::operator()(MethodCallVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << "->";
        var.call_get()->accept(*this);
    }

    void PrettyPrinter::operator()(ModuleCallVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << ".";
        var.call_get()->accept(*this);
    }

    void PrettyPrinter::operator()(ModuleAttributVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << "." << var.name_get();
    }

    void PrettyPrinter::operator()(FunctionDec& dec)
    {
        stream_ << "function " << dec.name_get() << " (";

        if (dec.args_get())
            separate(dec.args_get()->list_get(), ", ");

        stream_ << ")" << misc::incendl;
        dec.body_get()->accept(*this);
        stream_ << misc::decendl << "end" << misc::iendl;
    }

    void PrettyPrinter::operator()(VarDec& dec)
    {
        stream_ << dec.name_get();
        if (dec.exp_get())
        {
            stream_ << " = ";
            dec.exp_get()->accept(*this);
        }
    }

    template<typename T, class U>
    void PrettyPrinter::separate(std::list<T> list, const U& sep)
    {
        typename std::list<T>::const_iterator it = list.begin();

        for ( ; it != list.end(); ++it)
        {
            if (it != list.begin())
                stream_ << sep;
            (*it)->accept(*this);
        }
    }
} // namespace ast
