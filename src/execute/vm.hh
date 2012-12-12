#ifndef VM_HH
# define VM_HH

# include <vector>
# include <stack>

# include "../../lib/content-object.hh"
# include "../../lib/executable-context.hh"
# include "../../lib/params.hh"
# include "../../lib/empty-stack-exception.hh"
# include "../../lib/math-exception.hh"
# include "../utils/bytecode.hh"

namespace esl
{
    class Vm
    {
        public:
            Vm (std::vector<Bytecode* > *);
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

            void math(int (*op)(int, int));
        private:
            std::vector<Bytecode*>* code_;
            esl::Runtime* runtime_;
            std::stack<esl::ContentObject*>* stack_;
    };
}

#endif /* !VM_HH */
