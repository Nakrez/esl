#ifndef VM_HXX
# define VM_HXX

# include <execute/vm.hh>

namespace execute
{
    inline const misc::Error& Vm::error_get() const
    {
        return error_;
    }
} // namespace execute

#endif /* !VM_HXX */
