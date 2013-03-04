#ifndef BYTECODE_HXX
# define BYTECODE_HXX

# include <bytecode/bytecode.hh>

namespace bytecode
{
    inline const yy::location& Bytecode::location_get() const
    {
        return location_;
    }
} // namespace bytecode

#endif /* !BYTECODE_HXX */
