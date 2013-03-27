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
                       int data);
            virtual ~OpenModule();

            const int& data_get() const;
            int& data_get();

            virtual void accept(Visitor& visitor) const;

        protected:
            int data_;
    };
} // namespace bytecode

# include <bytecode/open-module.hxx>

#endif /* !OPEN_MODULE_HH */
