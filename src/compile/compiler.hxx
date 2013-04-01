#ifndef COMPILER_HXX
# define COMPILER_HXX

# include <compile/compiler.hh>

namespace compile
{
    inline execute::Executable* Compiler::exec_get()
    {
        return exec_;
    }

    inline const misc::Error& Compiler::error_get() const
    {
        return error_;
    }
} // namespace compile

#endif /* !COMPILER_HXX */
