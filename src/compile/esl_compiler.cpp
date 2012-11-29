#include <compile/esl_compiler.hh>

esl_compiler::esl_compiler(esl_ast *ast)
{
    this->gen_ast = ast;
}

esl_compiler::~esl_compiler()
{

}

void esl_compiler::compile()
{
    this->byte_code = compile(this->gen_ast);
}

void esl_compiler::export_bytecode(const std::string &filename)
{
    std::vector<esl_bytecode *>::iterator begin = this->byte_code->begin();
    std::vector<esl_bytecode *>::iterator end = this->byte_code->end();
    std::ofstream file;
    int line = 0;

    file.open(filename.c_str(), std::ios::out);

    for (; begin != end; ++begin, ++line)
    {
        file << line << " " << instr_string[(*begin)->get_type()] << " ";

        if ((*begin)->get_param())
        {
            /* INT */
            if ((*begin)->get_type_param() == 1)
                file << *((int *)((*begin)->get_param())) << std::endl;
            else /* STRING */
                file << *((std::string *)((*begin)->get_param())) << std::endl;
        }
        else
            file << std::endl;
    }

    file.close();
}

/* Private Members */

std::vector<esl_bytecode *> *esl_compiler::compile(esl_ast *ast)
{
    if (ast == NULL)
        return NULL;

    switch (ast->get_token())
    {
        case STATEMENTS: return compile_statements(ast->get_fson());
        case ASSIGNEMENT: return compile_assignement(ast);
        case ADD: return compile_addition(ast);
        case NUMBER: return compile_number(ast);
    }

    return NULL;
}

std::vector<esl_bytecode *> *esl_compiler::compile_statements(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = new std::vector<esl_bytecode *>;
    std::vector<esl_bytecode *> *ret_code = NULL;

    while (ast)
    {
        if ((ret_code = compile(ast)) != NULL)
           code->insert(code->end(), ret_code->begin(), ret_code->end());

        ast = ast->get_rbro();
    }

    return code;
}

std::vector<esl_bytecode *> *esl_compiler::compile_assignement(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = NULL;

    code = compile(ast->get_fson()->get_rbro());

    code->push_back(new esl_bytecode(STORE,
                                     2, /* STRING */
                                     new std::string(*(ast->get_fson()->get_content()))));

    return code;
}

std::vector<esl_bytecode *> *esl_compiler::compile_addition(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = NULL;
    std::vector<esl_bytecode *> *ret_code = NULL;

    code = compile(ast->get_fson());

    ret_code = compile(ast->get_fson()->get_rbro());

    code->insert(code->end(), ret_code->begin(), ret_code->end());

    code->push_back(new esl_bytecode(ARITH_ADD, 0, NULL));

    return code;
}

std::vector<esl_bytecode *> *esl_compiler::compile_number(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = new std::vector<esl_bytecode *>;
    int *value = new int;

    *value = utils::atoi(*(ast->get_content()));

    code->push_back(new esl_bytecode(LOAD_CST, 1, value));

    return code;
}
