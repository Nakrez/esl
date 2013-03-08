#ifndef LOAD_MODULE_HXX
# define LOAD_MODULE_HXX

# include <bytecode/load-module.hh>

namespace bytecode
{
    inline const misc::symbol& LoadModule::name_get() const
    {
        return name_;
    }

    inline void LoadModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_MODULE_HXX */
