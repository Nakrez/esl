/// @date 10/03/2013
#ifndef JUMP_TRUE_HH
# define JUMP_TRUE_HH

# include <bytecode/jump.hh>

namespace bytecode
{
    class JumpTrue : public Jump
    {
        public:
            JumpTrue(const yy::location& location,
                     int offset);
            virtual ~JumpTrue();

            virtual void accept(Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/jump-true.hxx>

#endif /* !JUMP_TRUE_HH */
