#ifndef START_CLASS_HXX
# define START_CLASS_HXX

# include <bytecode/start-class.hh>

namespace bytecode
{
    inline const misc::symbol& StartClass::name_get() const
    {
        return name_;
    }

    inline void StartClass::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !START_CLASS_HXX */
