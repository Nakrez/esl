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

namespace esl
{
    class Vm
    {
        public:
            Vm (const std::vector<Bytecode*>&);
            ~Vm ();

            void run();

        private:
            void pop ();
            void store (Bytecode* instr);
            void load (Bytecode* instr);
            void load_cst (Bytecode* instr);
            void jump (Bytecode* instr);
            void jump (Bytecode* instr, int);
            void register_function (Bytecode* instr);
            void call_function (Bytecode* instr);
            void function_return ();
            void print ();
            void decr_obj (void*);
            void incr_obj (void*);
            void setup_module(Bytecode* instr);
            void module(Bytecode* instr);
            void call_module(Bytecode* instr);

            template<class Func>
            void math(Func fun);

        private:
            std::vector<Bytecode*> code_;
            esl::Runtime* runtime_;
            std::stack<esl::ContentObject*>* stack_;
    };
}

# include "vm.hxx"

#endif /* !VM_HH */
