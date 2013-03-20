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
# include "../../lib/content.hh"
# include "../../lib/params.hh"
# include "../../lib/module.hh"
# include "../../lib/exception.hh"
# include "../../lib/context.hh"
# include "../../lib/stack-delimiter.hh"
# include "../../lib/type/squeleton.hh"

# include "../../lib/type/int-object.hh"
# include "../../lib/type/int.hh"
# include "../../lib/type/string-object.hh"
# include "../../lib/type/string.hh"
# include "../../lib/type/array-object.hh"
# include "../../lib/type/array.hh"

# include "../bytecode/bytecode.hh"

namespace esl
{
    class Vm
    {
        public:
            static void instanciate (const std::vector<bytecode::Bytecode*>& code);
            static Vm* get ();
            static void free ();

            /// @brief Run the virtual machine
            void run();

            bool external_call (Function* fun, const Params& params);

            bool is_register_function(const std::string& name) const;
            bool is_register_variable(const std::string& name) const;
            bool is_register_module(const std::string& name) const;

            bool module_function(const std::string& module,
                                 const std::string& fun) const;

            /// @brief POP stack and decr counter on TOS
            void pop ();

        private:
            /// @brief Constructor
            /// @param code The bytecode to execute
            Vm (const std::vector<bytecode::Bytecode*>& code);

            /// @brief Destructor
            ~Vm ();

            /// @brief Execute STORE instruction
            /// @param instr The instruction to execute
            void store (bytecode::Bytecode* instr);

            /// @brief Execute STORE_STK instruction
            void store_stk ();

            /// @brief Execute LOAD instruction
            /// @param instr The instruction to execute
            void load (bytecode::Bytecode* instr);

            /// @brief Execute LOAD_INT instruction
            /// @param instr The instruction to execute
            void load_int (bytecode::Bytecode* instr);

            /// @brief Execute LOAD_STR instruction
            /// @param instr The instruction to execute
            void load_str (bytecode::Bytecode* instr);

            /// @brief Execute JUMP instruction
            /// @param instr The instruction to execute
            void jump (bytecode::Bytecode* instr);

            /// @brief Execute JUMP instruction
            /// @param instr The instruction to execute
            /// @param val The value you want to compare with TOS
            void jump (bytecode::Bytecode* instr, int);

            /// @brief Execute MAKE_FUNCTION instruction
            /// @param instr The instruction to execute
            void register_function (bytecode::Bytecode* instr);

            /// @brief Execute CALL_FUNCTION instruction
            /// @param instr The instruction to execute
            void call_function (bytecode::Bytecode* instr);

            /// @brief Execute RETURN instruction
            void function_return ();

            /// @brief Execute OPEN instruction (load a module)
            /// @param instr The instruction to execute
            void setup_module(bytecode::Bytecode* instr);

            /// @brief Execute MODULE instruction (push module on stack)
            /// @param instr The instruction to execute
            void module(bytecode::Bytecode* instr);

            /// @brief Execute CALL_MODULE
            /// @param instr The instruction to execute
            void call_module(bytecode::Bytecode* instr);

            /// @brief Get the path of the module called
            /// @param mod_name The name of the module
            std::string module_path (const std::string& mod_name);

            /// @brief Perform an operation (call an operator)
            /// @param name The name of the operation
            void operation (const std::string& name);

            /// @brief Execute CALL_METHOD instruction
            /// @param instr The instruction to execute
            void call_method (bytecode::Bytecode* bytecode);

            void instanciation (bytecode::Bytecode* bytecode);
            void create_type (bytecode::Bytecode* bytecode);
            void make_attribut (bytecode::Bytecode* bytecode);
            void store_attribut (bytecode::Bytecode* bytecode);
            void load_attribut (bytecode::Bytecode* bytecode);
            void inherit (bytecode::Bytecode* bytecode);

            /// @brief Push a delimiter on the stack
            void add_delim ();

            /// @brief The VM stack
            std::stack<esl::MemoryObject<esl::Content>*> stack_;

            /// @brief The code to execute
            std::vector<bytecode::Bytecode*> code_;

            /// @brief The current runtime
            esl::Context* runtime_;

            /// @brief Path to look at to find module
            static const std::string path_lib_[];

            /// @brief Static instance of the VM
            static Vm* instance_;

            Type* declaration;
    };
}

#endif /* !VM_HH */
