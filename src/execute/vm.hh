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
            Vm (const std::vector<Bytecode*>&);
            ~Vm ();

            void run();

        private:
            void store (Bytecode* instr);
            void store_stk ();

            void load (Bytecode* instr);
            void load_int (Bytecode* instr);
            void load_str (Bytecode* instr);

            void jump (Bytecode* instr);
            void jump (Bytecode* instr, int);

            void register_function (Bytecode* instr);
            void call_function (Bytecode* instr);
            void function_return ();

            void setup_module(Bytecode* instr);
            void module(Bytecode* instr);
            void call_module(Bytecode* instr);

            std::string module_path (const std::string&);

            void operation (const std::string&);

            void call_method (Bytecode* bytecode);

            void pop ();
            void add_delim ();

        private:
            std::stack<esl::MemoryObject<esl::Content>*> stack_;
            std::vector<Bytecode*> code_;
            esl::Context* runtime_;

            static const std::string path_lib_[];
    };
}

#endif /* !VM_HH */
