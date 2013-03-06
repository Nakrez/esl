/// @date 06/03/2013
#ifndef OPEN_MODULE_HH
# define OPEN_MODULE_HH

# include <string>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class OpenModule : public Bytecode
    {
        public:
            OpenModule(const yy::location& location,
                       const std::string& str);
            virtual ~OpenModule();

            const std::string& str_get() const;

            virtual void accept(const Visitor& visitor) const;

        protected:
            std::string str_;
    };
} // namespace bytecode

# include <bytecode/open-module.hxx>

#endif /* !OPEN_MODULE_HH */
