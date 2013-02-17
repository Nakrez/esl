#ifndef IMPORT_DEC_HXX
# define IMPORT_DEC_HXX

# include <ast/visitor.hh>

# include <ast/import-dec.hh>

namespace ast
{
    inline void ImportDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast
#endif /* !IMPORT_DEC_HXX */
