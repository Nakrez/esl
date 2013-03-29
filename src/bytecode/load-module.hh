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
                       int data);
            virtual ~LoadModule();

            const int& data_get() const;
            int& data_get();

            virtual void accept(Visitor& visitor) const;

        protected:
            int data_;
    };
} // namespace bytecode

# include <bytecode/load-module.hxx>

#endif /* !LOAD_MODULE_HH */
