#include <execute/executable-dumper.hh>

namespace execute
{
    ExecutableDumper::ExecutableDumper(std::ostream& ostr)
        : ostr_(ostr)
    {}

    void ExecutableDumper::dump(const Executable& exec)
    {
        // Dump code
        bytecode::BytecodeDumper code_dump(ostr_);
        code_dump.dump(exec.code_get());
    }
} // namespace execute
