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
            void add_instruction(bytecode::Bytecode* instr);

            const std::vector<std::string>& ro_data_get() const;
            void add_ro_data(const std::string& data);
            const std::string& ro_data_get(int at) const;

        private:
            std::vector<bytecode::Bytecode*> code_;
            std::vector<std::string> ro_data_;
    };
} // namespace execute

# include <execute/executable.hxx>

#endif /* !EXECUTABLE_HH */
