/// @date 22/03/2013

#ifndef EXECUTABLE_HH
# define EXECUTABLE_HH

# include <bytecode/all.hh>

namespace execute
{
    class Executable
    {
        public:
            Executable();
            ~Executable();

            const std::vector<bytecode::Bytecode*>& code_get() const;

        private:
            std::vector<bytecode::Bytecode*> code_;
    };
} // namespace execute

# include <execute/executable.hxx>

#endif /* !EXECUTABLE_HH */
