#include <execute/libexecute.hh>

namespace execute
{
    misc::Error readable_dump(const Executable& exec)
    {
        ExecutableDumper dump(std::cout);
        dump.dump(exec);

        return misc::Error();
    }
} // namespace execute
