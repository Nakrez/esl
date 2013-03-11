#ifndef DELIM_HXX
# define DELIM_HXX

# include <bytecode/delim.hh>

namespace bytecode
{
    inline void Delim::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
}

#endif /* !DELIM_HXX */
