#ifndef COMPILER_HXX
# define COMPILER_HXX

# include <compile/compiler.hh>

namespace compile
{
    inline const std::vector<Bytecode>& Compiler::bytecode_get() const
    {
        return bytecode_;
    }
} // namespace compile

#endif /* !COMPILER_HXX */
