/// @file src/execute/vm.hh
/// @brief The virtual machine that execute the ESL bytecode
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 01 Dec 2012

#ifndef VM_HH
# define VM_HH

# include <fstream>
# include <vector>
# include <stack>
# include <queue>

# include "../../lib/gc/memory-object.hh"
# include "../../lib/type/esl-types.hh"
# include "../../lib/content.hh"
# include "../../lib/params.hh"
# include "../../lib/exception.hh"
# include "../../lib/context.hh"
# include "../../lib/stack-delimiter.hh"
# include "../utils/bytecode.hh"
# include "../utils/ro-data.hh"

namespace esl
{
    class Vm
    {
        public:

            /// @brief Constructor
            /// @param code The bytecode to execute
            Vm (const std::vector<Bytecode*>& code);

            /// @brief Destructor
            ~Vm ();

            /// @brief Run the virtual machine
            void run();

        private:
            /// @brief Execute STORE instruction
            /// @param instr The instruction to execute
            void store (Bytecode* instr);

            /// @brief Execute STORE_STK instruction
            void store_stk ();

            /// @brief Execute LOAD instruction
            /// @param instr The instruction to execute
            void load (Bytecode* instr);

            /// @brief Execute LOAD_INT instruction
            /// @param instr The instruction to execute
            void load_int (Bytecode* instr);

            /// @brief Execute LOAD_STR instruction
            /// @param instr The instruction to execute
            void load_str (Bytecode* instr);

            /// @brief Execute JUMP instruction
            /// @param instr The instruction to execute
            void jump (Bytecode* instr);

            /// @brief Execute JUMP instruction
            /// @param instr The instruction to execute
            /// @param val The value you want to compare with TOS
            void jump (Bytecode* instr, int);

            /// @brief Execute MAKE_FUNCTION instruction
            /// @param instr The instruction to execute
            void register_function (Bytecode* instr);

            /// @brief Execute CALL_FUNCTION instruction
            /// @param instr The instruction to execute
            void call_function (Bytecode* instr);

            /// @brief Execute RETURN instruction
            void function_return ();

            /// @brief Execute OPEN instruction (load a module)
            /// @param instr The instruction to execute
            void setup_module(Bytecode* instr);

            /// @brief Execute MODULE instruction (push module on stack)
            /// @param instr The instruction to execute
            void module(Bytecode* instr);

            /// @brief Execute CALL_MODULE
            /// @param instr The instruction to execute
            void call_module(Bytecode* instr);

            /// @brief Get the path of the module called
            /// @param mod_name The name of the module
            std::string module_path (const std::string& mod_name);

            /// @brief Perform an operation (call an operator)
            /// @param name The name of the operation
            void operation (const std::string& name);

            /// @brief Execute CALL_METHOD instruction
            /// @param instr The instruction to execute
            void call_method (Bytecode* bytecode);

            /// @brief POP stack and decr counter on TOS
            void pop ();

            /// @brief Push a delimiter on the stack
            void add_delim ();

            /// @brief The VM stack
            std::stack<esl::MemoryObject<esl::Content>*> stack_;

            /// @brief The code to execute
            std::vector<Bytecode*> code_;

            /// @brief The current runtime
            esl::Context* runtime_;

            /// @brief Path to look at to find module
            static const std::string path_lib_[];
    };
}

#endif /* !VM_HH */
