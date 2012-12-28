#ifndef VM_HH
# define VM_HH

# include <vector>
# include <stack>

# include "../../lib/content-object.hh"
# include "../../lib/executable-context.hh"
# include "../../lib/params.hh"
# include "../../lib/empty-stack-exception.hh"
# include "../../lib/math-exception.hh"
# include "../../lib/module.hh"
# include "../utils/bytecode.hh"
# include "../utils/ro-data.hh"
# include "operation.hh"

namespace esl
{
    class Vm
    {
        using int_operation = int (*)(const int*, const int*);
        using str_operation = std::string (*)(const std::string*,
                                              const std::string*);
        using str_bool_operation = int (*)(const std::string*,
                                           const std::string*);

        public:
            Vm (const std::vector<Bytecode*>&);
            ~Vm ();

            void run();

        private:
            void store (Bytecode* instr);
            void load (Bytecode* instr);
            void load_int (Bytecode* instr);
            void load_str (Bytecode* instr);
            void jump (Bytecode* instr);
            void jump (Bytecode* instr, int);
            void register_function (Bytecode* instr);
            void call_function (Bytecode* instr);
            void function_return ();
            void print ();
            void setup_module(Bytecode* instr);
            void module(Bytecode* instr);
            void call_module(Bytecode* instr);

            template<class Func>
            void math (Func fun);

            void math_operation (int_operation, str_operation);
            void bool_operation (int_operation, str_bool_operation);
            void operation (esl::Value*& obj1, esl::Value*& obj2);
        private:
            std::stack<esl::ContentObject*> stack_;
            std::vector<Bytecode*> code_;
            esl::Runtime* runtime_;
    };
}

# include "vm.hxx"

#endif /* !VM_HH */
