#ifndef EXECUTABLE_HXX
# define EXECUTABLE_HXX

# include <execute/executable.hh>

namespace execute
{
    inline const std::vector<bytecode::Bytecode*>&
    Executable::code_get() const
    {
        return code_;
    }

    void Executable::add_instruction(bytecode::Bytecode* instr)
    {
        code_.push_back(instr);
    }
} // namespace execute

#endif /* !EXECUTABLE_HXX */
