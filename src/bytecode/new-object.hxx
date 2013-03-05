#ifndef NEW_OBJECT_HXX
# define NEW_OBJECT_HXX

# include <bytecode/new-object.hh>

namespace bytecode
{
    inline const misc::symbol& NewObject::name_get() const
    {
        return name_;
    }

    inline void NewObject::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !NEW_OBJECT_HXX */
