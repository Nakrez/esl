#ifndef COMPILER_HXX
# define COMPILER_HXX

# include <compile/compiler.hh>

namespace compile
{
    inline const execute::Executable& Compiler::exec_get() const
    {
        return exec_;
    }
} // namespace compile

#endif /* !COMPILER_HXX */
