/// @date 22/03/2013

#ifndef EXECUTABLE_DUMPER_HH
# define EXECUTABLE_DUMPER_HH

# include <execute/executable.hh>

# include <bytecode/bytecode-dumper.hh>

namespace execute
{
    class ExecutableDumper
    {
        public:
            ExecutableDumper(std::ostream& ostr);
            ~ExecutableDumper() = default;

            void dump(const Executable& exec);

        private:
            std::ostream& ostr_;
    };
} // namespace execute

#endif /* !EXECUTABLE_DUMPER_HH */
