/// @date 08/03/2013
#ifndef END_CLASS_HH
# define END_CLASS_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class EndClass : public Bytecode
    {
        public:
            EndClass(const yy::location& location);
            virtual ~EndClass();

            virtual void accept(Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/end-class.hxx>

#endif /* !END_CLASS_HH */
