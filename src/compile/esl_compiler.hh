#ifndef ESL_COMPILER_H_
# define ESL_COMPILER_H_

# include <string>
# include <vector>
# include <iostream>
# include <fstream>

# include <utils/esl_bytecode.hh>
# include <utils/esl_ast.hh>
# include <utils/utils.hh>

class esl_compiler
{
    public:
        esl_compiler(esl_ast *ast);
        ~esl_compiler();

        void compile();
        void export_bytecode(const std::string &filename);

    private:
        std::vector<esl_bytecode *> *compile(esl_ast *);
        std::vector<esl_bytecode *> *compile_statements(esl_ast *);
        std::vector<esl_bytecode *> *compile_assignement(esl_ast *);
        std::vector<esl_bytecode *> *compile_arith(esl_ast *, enum instr);
        std::vector<esl_bytecode *> *compile_number(esl_ast *);

    private:
        esl_ast     *gen_ast;
        std::vector<esl_bytecode *> *byte_code;
};

#endif /* ESL_COMPILER_H_ */
