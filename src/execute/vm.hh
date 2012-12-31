#ifndef VM_HH
# define VM_HH

# include <fstream>
# include <vector>
# include <stack>
# include <queue>

# include "../../lib/gc/memory-object.hh"
# include "../../lib/type/esl-types.hh"
# include "../../lib/content.hh"
# include "../../lib/executable-context.hh"
# include "../../lib/params.hh"
# include "../../lib/exception.hh"
# include "../../lib/module.hh"
# include "../utils/bytecode.hh"
# include "../utils/ro-data.hh"
# include "operation.hh"

namespace esl
{
    class Vm
    {
        using int_operation = int (*)(int, int);
        using str_operation = std::string (*)(const std::string&,
                                              const std::string&);
        using str_bool_operation = int (*)(const std::string&,
                                           const std::string&);

        public:
            Vm (const std::vector<Bytecode*>&);
            ~Vm ();

            void run();

        private:
            void store (Bytecode* instr);
            void store_stk ();

            void load (Bytecode* instr);
            void load_int (Bytecode* instr);
            void load_str (Bytecode* instr);
            void array_val ();

            void jump (Bytecode* instr);
            void jump (Bytecode* instr, int);

            void register_function (Bytecode* instr);
            void call_function (Bytecode* instr);
            void function_return ();

            void setup_module(Bytecode* instr);
            void module(Bytecode* instr);
            void call_module(Bytecode* instr);

            template<class Func>
            void math (Func fun);

            std::string module_path (const std::string&);

            void math_operation (int_operation, str_operation);
            void bool_operation (int_operation, str_bool_operation);

            void pop ();
        private:
            std::stack<esl::MemoryObject<esl::Content>*> stack_;
            std::vector<Bytecode*> code_;
            esl::Runtime* runtime_;

            static const std::string path_lib_[];
    };
}

# include "vm.hxx"

#endif /* !VM_HH */
