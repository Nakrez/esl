/// date 04/03/2013
#ifndef BYTECODE_VISITOR_HH
# define BYTECODE_VISITOR_HH

# include <bytecode/fwd.hh>

namespace bytecode
{
    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(const Bytecode& byte) const;
            virtual void operator()(const Pop& byte) const = 0;
    };
} // namespace bytecode

#endif /* !BYTECODE_VISITOR_HH */
