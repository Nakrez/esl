/// @date 06/03/2013
#ifndef LOAD_MODULE_HH
# define LOAD_MODULE_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class LoadModule : public Bytecode
    {
        public:
            LoadModule(const yy::location& location,
                       const misc::symbol& name);
            virtual ~LoadModule();

            const misc::symbol& name_get() const;

            virtual void accept(const Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/load-module.hxx>

#endif /* !LOAD_MODULE_HH */
