#ifndef VISIBILITY_HH
# define VISIBILITY_HH

# include <iostream>

namespace misc
{
    enum visibility
    {
        PUBLIC,
        PRIVATE,
        PROTECTED
    };

    std::ostream& operator<< (std::ostream& ostr, const visibility& v);
} // namespace misc

#endif /* !VISIBILITY_HH */
