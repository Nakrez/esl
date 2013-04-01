#include <execute/libexecute.hh>

namespace execute
{
    misc::Error readable_dump(const Executable& exec)
    {
        ExecutableDumper dump(std::cout);
        dump.dump(exec);

        return misc::Error();
    }

    misc::Error execute(const Executable& exec)
    {
        Vm vm(exec);
        vm.run();

        return vm.error_get();
    }
} // namespace execute
