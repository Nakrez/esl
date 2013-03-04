#ifndef POP_HH
# define POP_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class Pop : public Bytecode
    {
        public:
            Pop(const yy::location& location);
            virtual ~Pop();

            virtual void accept(const Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/pop.hxx>

#endif /* !POP_HH */
