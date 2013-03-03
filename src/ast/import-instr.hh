/// date 17 Feb 2013
#ifndef IMPORT_INSTR_HH
# define IMPORT_INSTR_HH

# include <ast/instr.hh>

namespace ast
{
    class ImportInstr : public Instr
    {
        public:
            ImportInstr(const yy::location& location,
                        const std::string& name);
            virtual ~ImportInstr();

            const std::string& name_get() const;
            std::string& name_get();

            void accept(Visitor& visitor);

        protected:
            std::string name_;
    };
} // namespace ast

# include <ast/import-instr.hxx>

#endif /* !IMPORT_INSTR_HH */
