#include <ast/instr-list.hh>

namespace ast
{
    InstrList::InstrList(const yy::location& location)
        : Instr(location)
    {}

    InstrList::InstrList(const yy::location& location,
                         Instr* instr)
        : Instr(location)
    {
        instr_list_.push_back(instr);
    }
    void InstrList::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast
