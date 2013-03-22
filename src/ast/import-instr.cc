#include <ast/import-instr.hh>

namespace ast
{
    ImportInstr::ImportInstr(const yy::location& location,
                             const std::string& name)
        : Instr(location)
        , name_(name)
    {}

    ImportInstr::~ImportInstr()
    {
//        delete &name_;
    }
} // namespace ast
