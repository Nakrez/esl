/// @date 11/03/2013
#ifndef DELIM_HH
# define DELIM_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class Delim : public Bytecode
    {
        public:
            Delim(const yy::location& location);
            virtual ~Delim();

            virtual void accept(Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/delim.hxx>

#endif /* !DELIM_HH */
