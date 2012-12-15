#ifndef COMPILER_HH
# define COMPILER_HH

# include <string>
# include <vector>
# include <iostream>
# include <fstream>

# include "../utils/bytecode.hh"
# include "../utils/ast.hh"
# include "../utils/utils.hh"

namespace esl
{
    class Compiler
    {
        public:
            Compiler(Ast* ast);
            ~Compiler();

            void compile();
            void export_bytecode(const std::string &filename);

            std::vector<Bytecode*>* get_bytecode();

        private:
            std::vector<Bytecode*>* compile(Ast*);
            std::vector<Bytecode*>* compile_statements(Ast*);
            std::vector<Bytecode*>* compile_assignement(Ast*);
            std::vector<Bytecode*>* compile_arith(Ast*, instr);
            std::vector<Bytecode*>* compile_loop(Ast*, instr);
            std::vector<Bytecode*>* compile_number(Ast*);
            std::vector<Bytecode*>* compile_identifier(Ast*);
            std::vector<Bytecode*>* compile_if(Ast*);
            std::vector<Bytecode*>* compile_function(Ast*);
            std::vector<Bytecode*>* compile_call(Ast*);
            std::vector<Bytecode*>* compile_list(Ast*);
            std::vector<Bytecode*>* compile_import(Ast*);
            std::vector<Bytecode*>* compile_return(Ast*);
            std::vector<Bytecode*>* compile_module_call(Ast*);

            Bytecode* make_call_instruction(Ast*);

        private:
            Ast* gen_ast_;
            std::vector<Bytecode*>* byte_code_;
    };
}
#endif /* COMPILER_HH */
