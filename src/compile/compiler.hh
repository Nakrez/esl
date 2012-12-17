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

            std::vector<Bytecode*> get_bytecode();

        private:
            void compile(Ast*);
            void compile_statements(Ast*);
            void compile_assignement(Ast*);
            void compile_operation(Ast*, instr);
            void compile_loop(Ast*, instr);
            void compile_number(Ast*);
            void compile_identifier(Ast*);
            void compile_if(Ast*);
            void compile_function(Ast*);
            void compile_call(Ast*);
            void compile_list(Ast*);
            void compile_import(Ast*);
            void compile_return(Ast*);
            void compile_module_call(Ast*);

        private:
            Ast* gen_ast_;
            std::vector<Bytecode*> byte_code_;
    };
}
#endif /* COMPILER_HH */
