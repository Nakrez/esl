/// date 17 Feb 2013
#ifndef IMPORT_DEC_HH
# define IMPORT_DEC_HH

# include <ast/dec.hh>

namespace ast
{
    class ImportDec : public Dec
    {
        ImportDec(const yy::location& location,
                  const misc::symbol name);
        virtual ~ImportDec();

        virtual void accept(Visitor& visitor);
    };
} // namespace ast

# include <ast/import-dec.hxx>

#endif /* !IMPORT_DEC_HH */
