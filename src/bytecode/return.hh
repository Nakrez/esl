/// @date 10/03/2013
#ifndef RETURN_HH
# define RETURN_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class Return : public Bytecode
    {
        public:
            Return(const yy::location& location);
            virtual ~Return();

            virtual void accept(Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/return.hxx>

#endif /* !RETURN_HH */
