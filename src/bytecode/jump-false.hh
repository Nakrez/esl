/// @date 10/03/2013
#ifndef JUMP_FALSE_HH
# define JUMP_FALSE_HH

# include <bytecode/jump.hh>

namespace bytecode
{
    class JumpFalse : public Jump
    {
        public:
            JumpFalse(const yy::location& location,
                      int offset);
            virtual ~JumpFalse();

            virtual void accept(Visitor& visitor) const;
    };
} // namespace byteocde

# include <bytecode/jump-false.hxx>

#endif /* !JUMP_FALSE_HH */
