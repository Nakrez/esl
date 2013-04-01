#ifndef LIBBYTECODE_HH
# define LIBBYTECODE_HH

# include <misc/error.hh>

# include <compile/libcompile.hh>
# include <execute/executable.hh>

# include <execute/executable-dumper.hh>

namespace execute
{
    misc::Error readable_dump(const Executable& exec);
} // namespace execute

#endif /* !LIBBYTECODE_HH */
