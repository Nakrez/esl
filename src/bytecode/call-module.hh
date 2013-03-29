/// @date 08/03/2013
#ifndef CALL_MODULE_HH
# define CALL_MODULE_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class CallModule : public Bytecode
    {
        public:
            CallModule(const yy::location& location,
                       int data);
            virtual ~CallModule();

            const int& data_get() const;
            int& data_get();

            virtual void accept(Visitor& visitor) const;

        protected:
            int data_;
    };
} // namespace bytecode

# include <bytecode/call-module.hxx>

#endif /* !CALL_MODULE_HH */
