/// @date 06/03/2013
#ifndef LOAD_MODULE_HH
# define LOAD_MODULE_HH

# include <string>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class LoadModule : public Bytecode
    {
        public:
            LoadModule(const yy::location& location,
                       const std::string& str);
            virtual ~LoadModule();

            const std::string& str_get() const;

            virtual void accept(const Visitor& visitor) const;

        protected:
            std::string str_;
    };
} // namespace bytecode

# include <bytecode/load-module.hxx>

#endif /* !LOAD_MODULE_HH */
