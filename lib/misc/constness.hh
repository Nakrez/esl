/// @date 20/03/2013

#ifndef CONSTNESS_HH
# define CONSTNESS_HH

namespace misc
{
    template <typename T>
    struct const_type
    {
        typedef const T type;
    };

    template <typename T>
    struct nonconst_type
    {
        typedef T type;
    };
} // namespace misc

#endif /* !CONSTNESS_HH */
