/// @date 05/03/2013
#ifndef LOAD_VAR_HH
# define LOAD_VAR_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class LoadVar : public Bytecode
    {
        public:
            LoadVar(const yy::location& location,
                    const misc::symbol& name);
            virtual ~LoadVar();

            const misc::symbol& name_get() const;

            void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/load-var.hxx>

#endif /* !LOAD_VAR_HH */
