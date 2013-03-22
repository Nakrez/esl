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

    inline void Executable::add_instruction(bytecode::Bytecode* instr)
    {
        code_.push_back(instr);
    }

    inline const std::vector<std::string>& Executable::ro_data_get() const
    {
        return ro_data_;
    }

    inline void Executable::add_ro_data(const std::string& data)
    {
        ro_data_.push_back(data);
    }
} // namespace execute

#endif /* !EXECUTABLE_HXX */
