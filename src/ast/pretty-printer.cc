#include <ast/pretty-printer.hh>
#include <ast/all.hh>

namespace ast
{
    PrettyPrinter::PrettyPrinter(std::ostream& stream)
        : DefaultConstVisitor()
        , stream_(stream)
    {}

    void PrettyPrinter::operator()(const AstList& list)
    {
        separate(list.list_get(), misc::iendl);
    }

    void PrettyPrinter::operator()(const IntExp& exp)
    {
        stream_ << exp.value_get();
    }

    void PrettyPrinter::operator()(const StringExp& exp)
    {
        stream_ << "\"" << exp.value_get() << "\"";
    }

    void PrettyPrinter::operator()(const OpExp& exp)
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

    void PrettyPrinter::operator()(const FunctionCallExp& exp)
    {
        stream_ << exp.name_get() << "(";
        separate(exp.args_get()->list_get(), ", ");
        stream_ << ")";
    }

    void PrettyPrinter::operator()(const ReturnExp& exp)
    {
        stream_ << "return ";
        exp.exp_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const BreakExp&)
    {
        stream_ << "break";
    }

    void PrettyPrinter::operator()(const ContinueExp&)
    {
        stream_ << "continue";
    }

    void PrettyPrinter::operator()(const NewExp& exp)
    {
        stream_ << "new ";
        exp.exp_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const AssignExp& exp)
    {
        exp.var_get()->accept(*this);
        stream_ << " = ";
        exp.exp_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const IfInstr& instr)
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

    void PrettyPrinter::operator()(const ElseInstr& instr)
    {
        instr.instr_list_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const WhileInstr& instr)
    {
        stream_ << "while (";
        instr.condition_get()->accept(*this);
        stream_ << ") do" << misc::incendl;
        instr.instr_list_get()->accept(*this);
        stream_ << misc::decendl << "end";
    }

    void PrettyPrinter::operator()(const InstrList& list)
    {
        separate(list.list_get(), misc::iendl);
    }

    void PrettyPrinter::operator()(const ImportInstr& instr)
    {
        stream_ << "import " << "\"" << instr.name_get() << "\"";
    }

    void PrettyPrinter::operator()(const VarId& var)
    {
        stream_ << var.name_get();
    }

    void PrettyPrinter::operator()(const AttributVar& var)
    {
        var.call_var_get().accept(*this);
        stream_ << "->" << var.name_get();
    }

    void PrettyPrinter::operator()(const MethodCallVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << "->";
        var.call_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const ModuleCallVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << ".";
        var.call_get()->accept(*this);
    }

    void PrettyPrinter::operator()(const ModuleAttributVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << "." << var.name_get();
    }

    void PrettyPrinter::operator()(const ArrayVar& var)
    {
        var.var_get()->accept(*this);
        stream_ << "[";
        var.exp_get()->accept(*this);
        stream_ << "]";
    }

    void PrettyPrinter::operator()(const FunctionDec& dec)
    {
        stream_ << "function " << dec.name_get() << " (";

        if (dec.args_get())
            separate(dec.args_get()->list_get(), ", ");

        stream_ << ")" << misc::incendl;
        dec.body_get()->accept(*this);
        stream_ << misc::decendl << "end" << misc::iendl;
    }

    void PrettyPrinter::operator()(const VarDec& dec)
    {
        stream_ << dec.name_get();
        if (dec.exp_get())
        {
            stream_ << " = ";
            dec.exp_get()->accept(*this);
        }
    }

    void PrettyPrinter::operator()(const MethodDec& dec)
    {
        stream_ << dec.visibility_get() << " function "
                << dec.name_get() << " (";

        if (dec.args_get())
            separate(dec.args_get()->list_get(), ", ");

        stream_ << ")" << misc::incendl;
        dec.body_get()->accept(*this);
        stream_ << misc::decendl << "end";
    }

    void PrettyPrinter::operator()(const AttributDec& dec)
    {
        stream_ << dec.visibility_get() << " " << dec.name_get();

        if (dec.value_get())
        {
            stream_ << " = ";
            dec.value_get()->accept(*this);
        }
    }

    void PrettyPrinter::operator()(const ClassDec& dec)
    {
        stream_ << "class " << dec.name_get();

        if (dec.inherit_get())
        {
            stream_ << " : (";

            const std::list<misc::symbol>& list = *dec.inherit_get();
            std::list<misc::symbol>::const_iterator it = list.begin();

            for ( ; it != list.end(); ++it)
            {
                if (it != list.begin())
                    stream_ << ", ";
                stream_ << (*it);
            }

            stream_ << ")";
        }

        stream_ << misc::incendl;
        dec.components_get()->accept(*this);
        stream_ << misc::decendl << "end";
    }

    void PrettyPrinter::operator()(const DecList& list)
    {
        separate(list.list_get(), misc::iendl);
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
