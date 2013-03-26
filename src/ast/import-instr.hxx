#ifndef IMPORT_INSTR_HXX
# define IMPORT_INSTR_HXX

# include <ast/visitor.hh>

# include <ast/import-instr.hh>

namespace ast
{
    inline const std::string& ImportInstr::name_get() const
    {
        return name_;
    }

    inline std::string& ImportInstr::name_get()
    {
        return name_;
    }

    inline void ImportInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void ImportInstr::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !IMPORT_INSTR_HXX */
