#ifndef BRACKET_OP_HH
# define BRACKET_OP_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class BracketOp : public Bytecode
    {
        public:
            BracketOp(const yy::location& location);
            virtual ~BracketOp();

            virtual void accept(const Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/bracket-op.hxx>

#endif /* !BRACKET_OP_HH */
