#include <compile/esl_compiler.hh>

esl_compiler::esl_compiler(esl_ast *ast)
{
    this->gen_ast = ast;
}

esl_compiler::~esl_compiler()
{
    for (std::vector<esl_bytecode *>::iterator i = byte_code->begin(); i !=
         byte_code->end(); ++ i)
        delete *i;

    delete byte_code;
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
    std::vector<esl_bytecode *> *code = NULL;

    if (ast == NULL)
        return NULL;

    switch (ast->get_token())
    {
        case STATEMENTS: code = compile_statements(ast->get_fson());
                         if (ast->get_fson()->get_token() == IF && ast == this->gen_ast)
                            code->push_back(new esl_bytecode(NOP, 1, NULL));
                         return code;
        case ASSIGNEMENT: return compile_assignement(ast);
        case ADD: return compile_arith(ast, ARITH_ADD);
        case MINUS: return compile_arith(ast, ARITH_MINUS);
        case MUL: return compile_arith(ast, ARITH_MUL);
        case DIV: return compile_arith(ast, ARITH_DIV);
        case MOD: return compile_arith(ast, ARITH_MOD);
        case NUMBER: return compile_number(ast);
        case EXPR: return compile(ast->get_fson());
        case ID: return compile_identifier(ast);
        case IF: return compile_if(ast);
    }

    return NULL;
}

std::vector<esl_bytecode *> *esl_compiler::compile_statements(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = new std::vector<esl_bytecode *>;
    std::vector<esl_bytecode *> *ret_code = NULL;

    while (ast)
    {
        ret_code = compile(ast);
        code->insert(code->end(), ret_code->begin(), ret_code->end());

        if (ast->get_token() == EXPR ||
            ast->get_token() == ASSIGNEMENT)
            code->push_back(new esl_bytecode(POP, 0, NULL));

        ret_code->clear();
        delete ret_code;

        ast = ast->get_rbro();
    }

    return code;
}

std::vector<esl_bytecode *> *esl_compiler::compile_if(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = new std::vector<esl_bytecode *>;
    std::vector<esl_bytecode *> *ret_code = NULL;
    esl_bytecode                *jump = new esl_bytecode(JUMP_IF_FALSE, 1, NULL);
    int                         *jump_next = NULL;

    ret_code = compile(ast->get_fson());
    code->insert(code->end(), ret_code->begin(), ret_code->end());
    delete ret_code;

    code->push_back(jump);

    ret_code = compile(ast->get_fson()->get_rbro());
    code->insert(code->end(), ret_code->begin(), ret_code->end());

    jump_next = new int;
    *jump_next = ret_code->size() + 2;
    jump->set_param(jump_next);

    delete ret_code;

    if (ast->get_fson()->get_rbro()->get_rbro())
    {
        jump = new esl_bytecode(JUMP, 1, NULL);
        code->push_back(jump);

        ret_code = compile(ast->get_fson()->get_rbro()->get_rbro());
        code->insert(code->end(), ret_code->begin(), ret_code->end());

        jump_next = new int;
        *jump_next = ret_code->size() + 1;
        jump->set_param(jump_next);


        delete ret_code;
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

std::vector<esl_bytecode *> *esl_compiler::compile_arith(esl_ast *ast,
                                                         enum instr i)
{
    std::vector<esl_bytecode *> *code = NULL;
    std::vector<esl_bytecode *> *ret_code = NULL;

    code = compile(ast->get_fson());

    ret_code = compile(ast->get_fson()->get_rbro());

    code->insert(code->end(), ret_code->begin(), ret_code->end());

    code->push_back(new esl_bytecode(i, 0, NULL));

    delete ret_code;

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

std::vector<esl_bytecode *> *esl_compiler::compile_identifier(esl_ast *ast)
{
    std::vector<esl_bytecode *> *code = new std::vector<esl_bytecode *>;

    std::string *value = new std::string(ast->get_content()->c_str());

    code->push_back(new esl_bytecode(LOAD, 2, value));

    return code;

}
