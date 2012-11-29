#ifndef ESL_COMPILER_H_
# define ESL_COMPILER_H_

# include <string>
# include <vector>
# include <iostream>
# include <fstream>

# include <utils/esl_ast.hh>

class esl_compiler
{
    public:
        esl_compiler(esl_ast *ast);
        ~esl_compiler();

        void compile();
        void export_bytecode(const std::string &filename);

    private:
        esl_ast     *ast;
};

#endif /* ESL_COMPILER_H_ */
