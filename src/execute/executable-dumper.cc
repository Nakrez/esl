#include <execute/executable-dumper.hh>

namespace execute
{
    ExecutableDumper::ExecutableDumper(std::ostream& ostr)
        : ostr_(ostr)
    {}

    void ExecutableDumper::dump(const Executable& exec)
    {
        // Dump RoData section
        ostr_ << "; begin ro_data section" << std::endl;

        int counter = 0;

        for (auto data : exec.ro_data_get())
        {
            ostr_ << ".string " << counter << " " << data << std::endl;
            ++counter;
        }

        ostr_ << "; end ro_data section" << std::endl;

        ostr_ << std::endl << "; begin code section" << std::endl;

        // Dump code
        bytecode::BytecodeDumper code_dump(ostr_);
        code_dump.dump(exec.code_get());

        ostr_ << "; end code section" << std::endl;
    }
} // namespace execute
