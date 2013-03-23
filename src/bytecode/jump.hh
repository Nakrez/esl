/// @date 10/03/2013
#ifndef JUMP_HH
# define JUMP_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class Jump : public Bytecode
    {
        public:
            Jump(const yy::location& location,
                 int offset);
            virtual ~Jump();

            int offset_get() const;
            void offset_set(int offset);

            virtual void accept(Visitor& visitor) const;

        protected:
            int offset_;
    };
} // namespace bytecode

# include <bytecode/jump.hxx>

#endif /* !JUMP_HH */
