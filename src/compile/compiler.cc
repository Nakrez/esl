#include "compiler.hh"

esl::Compiler::Compiler(esl::Ast *ast)
{
    this->gen_ast_ = ast;
}

esl::Compiler::~Compiler()
{
    for (std::vector<esl::Bytecode *>::iterator i = this->byte_code_->begin();
         i != byte_code_->end(); ++ i)
        delete *i;

    delete this->byte_code_;
}

/* Getter */
std::vector<esl::Bytecode *> *esl::Compiler::get_bytecode()
{
    return this->byte_code_;
}

void esl::Compiler::compile()
{
    this->byte_code_ = compile(this->gen_ast_);
    this->byte_code_->push_back(new esl::Bytecode(NOP, new esl::Value(O_NIL,
                                                                      NULL)));
}

void esl::Compiler::export_bytecode(const std::string &filename)
{
    std::vector<esl::Bytecode *>::iterator begin = this->byte_code_->begin();
    std::vector<esl::Bytecode *>::iterator end = this->byte_code_->end();
    std::ofstream file;
    int line = 0;

    file.open(filename.c_str(), std::ios::out);

    for (; begin != end; ++begin, ++line)
    {
        file << line << " " << instr_string[(*begin)->get_type()] << " ";

        if ((*begin)->get_param()->type_get() != O_NIL)
        {
            /* INT */
            if ((*begin)->get_param()->type_get() == O_INT)
                file << *((int *)((*begin)->get_param()->content_get()))
                     << std::endl;
            else /* STRING */
                file << *((std::string *)((*begin)->get_param()->content_get()))
                     << std::endl;
        }
        else
            file << std::endl;
    }

    file.close();
}

/* Private Members */

std::vector<esl::Bytecode *> *esl::Compiler::compile(esl::Ast *ast)
{
    if (ast == NULL)
        return NULL;

    switch (ast->get_token())
    {
        case STATEMENTS: return compile_statements(ast->get_fson());
        case ASSIGNEMENT: return compile_assignement(ast);
        case ADD: return compile_arith(ast, ARITH_ADD);
        case MINUS: return compile_arith(ast, ARITH_MINUS);
        case MUL: return compile_arith(ast, ARITH_MUL);
        case DIV: return compile_arith(ast, ARITH_DIV);
        case MOD: return compile_arith(ast, ARITH_MOD);
        case EQ: return compile_arith(ast, BOOL_EQ);
        case DIFF: return compile_arith(ast, BOOL_DIFF);
        case LT: return compile_arith(ast, BOOL_LT);
        case LE: return compile_arith(ast, BOOL_LE);
        case GT: return compile_arith(ast, BOOL_GT);
        case GE: return compile_arith(ast, BOOL_GE);
        case NUMBER: return compile_number(ast);
        case EXPR: return compile(ast->get_fson());
        case ID: return compile_identifier(ast);
        case IF: return compile_if(ast);
        case FUNCTION_DECL: return compile_function(ast);
        case FUNCTION_CALL: return compile_call(ast);
        case LIST: return compile_list(ast);
        case RETURN_STM: return compile_return(ast);
        case WHILE: return compile_loop(ast, JUMP_IF_FALSE);
        case UNTIL: return compile_loop(ast, JUMP_IF_TRUE);
        default : return NULL; /* TODO: Throw exception */
    }

    return NULL;
}

std::vector<esl::Bytecode*>* esl::Compiler::compile_loop(Ast* ast, instr i)
{
    std::vector<esl::Bytecode *> *code = new std::vector<esl::Bytecode *>;
    std::vector<esl::Bytecode *> *ret_code = nullptr;
    int* jump_addr = new int;

    code = compile(ast->get_fson());

    code->push_back(new esl::Bytecode(i, new esl::Value(O_INT, jump_addr)));

    ret_code = compile(ast->get_fson()->get_rbro());
    code->insert(code->end(), ret_code->begin(), ret_code->end());

    *jump_addr = code->size();

    delete ret_code;

    code->push_back(new esl::Bytecode(JUMP, new esl::Value(O_INT,
                                                           new int(-code->size()))));

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_statements(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = new std::vector<esl::Bytecode *>;
    std::vector<esl::Bytecode *> *ret_code = NULL;

    while (ast)
    {
        ret_code = compile(ast);
        code->insert(code->end(), ret_code->begin(), ret_code->end());

        if (ast->get_token() == EXPR ||
            ast->get_token() == ASSIGNEMENT ||
            ast->get_token() == FUNCTION_CALL)
            code->push_back(new esl::Bytecode(POP, new esl::Value(O_NIL,
                                                                  NULL)));

        ret_code->clear();
        delete ret_code;

        ast = ast->get_rbro();
    }

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_return(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = NULL;

    code = compile(ast->get_fson());
    code->push_back(new esl::Bytecode(RETURN, new esl::Value(O_NIL, NULL)));

    return code;
}

std::vector<esl::Bytecode*>* esl::Compiler::compile_list(esl::Ast* ast)
{
    std::vector<esl::Bytecode*>* code = new std::vector<esl::Bytecode*>;
    std::vector<esl::Bytecode*>* ret_code = nullptr;
    esl::Ast* temp_ast = nullptr;
    std::string* value = nullptr;

    temp_ast = ast->get_fson();

    while (temp_ast)
    {
        if (temp_ast->get_token() == ID)
        {
            value = new std::string(*(temp_ast->get_content()));
            code->push_back(new esl::Bytecode(STORE, new esl::Value(O_STRING,
                                                                    value)));
            code->push_back(new esl::Bytecode(POP, new esl::Value(O_NIL,
                                                                  nullptr)));
        }
        else
        {
            ret_code = compile(temp_ast);
            code->insert(code->end(), ret_code->begin(), ret_code->end());
            delete ret_code;
        }
        temp_ast = temp_ast->get_rbro();
    }

    return code;
}

std::vector<esl::Bytecode*>* esl::Compiler::compile_function(esl::Ast* ast)
{
    std::vector<esl::Bytecode*>* code = new std::vector<esl::Bytecode*>;
    std::vector<esl::Bytecode*>* ret_code = nullptr;
    esl::Bytecode* jump = nullptr;
    int* jump_addr = new int;
    int avoid = 1;
    std::string* value = nullptr;

    *jump_addr = 0;

    /* If there is param LOAD them in the stack */
    if (ast->get_fson()->get_token() != EMPTY)
    {
        ret_code = compile_list(ast->get_fson());
        *jump_addr = ret_code->size() + 1;
        avoid = 0;
    }

    value = new std::string(*(ast->get_content()));

    /* Add instruction MAKE_FUNCTION */
    code->push_back(new esl::Bytecode(MAKE_FUNCTION, new esl::Value(O_STRING,
                                                                    value)));

    /*
    ** Add instruction JUMP after MAKE_FUNCTION
    ** The adress will be calculate after code compilation
    */
    jump = new esl::Bytecode(JUMP, new esl::Value(O_INT, nullptr));

    code->push_back(jump);

    /* Add the param code to the generate code */
    if (ret_code)
    {
        code->insert(code->end(), ret_code->begin(), ret_code->end());
        delete ret_code;
    }

    /* Get the code of the function */
    ret_code = compile(ast->get_fson()->get_rbro());

    /*
    ** Calculate the JUMP adress
    ** The +1 is to JUMP after RETURN instruction
    */

    *jump_addr += ret_code->size() + 1 + avoid;

    jump->get_param()->content_set(jump_addr);

    /* Add the function code to the generate code */

    code->insert(code->end(), ret_code->begin(), ret_code->end());

    /* Add instruction RETURN */
    code->push_back(new esl::Bytecode(RETURN, new esl::Value(O_INT,
                                                             new int(0))));

    delete ret_code;

    return code;
}

esl::Bytecode *esl::Compiler::make_call_instruction(esl::Ast *ast)
{
    std::string *value = NULL;

    if (*(ast->get_content()) == std::string("print"))
        return new esl::Bytecode(PRINT, new esl::Value(O_NIL, NULL));

    value = new std::string(*(ast->get_content()));

    return new esl::Bytecode(CALL_FUNCTION, new esl::Value(O_STRING, value));
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_call(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = new std::vector<esl::Bytecode *>;
    std::vector<esl::Bytecode *> *ret_code = NULL;
    esl::Ast                     *temp_ast = NULL;

    /* Load args */
    if (ast->get_fson())
        temp_ast = ast->get_fson()->get_fson();

    if (temp_ast)
    {
        ret_code = compile(ast->get_fson());
        code->insert(code->end(), ret_code->begin(), ret_code->end());
        delete ret_code;
    }

    /* Build call instruction (check special code for built in) */
    code->push_back(make_call_instruction(ast));

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_if(esl::Ast *ast)
{
    std::vector<esl::Bytecode*>* code = new std::vector<esl::Bytecode *>;
    std::vector<esl::Bytecode*> *ret_code = NULL;
    esl::Bytecode* jump = new esl::Bytecode(JUMP_IF_FALSE,
                                            new esl::Value(O_INT, NULL));
    int* jump_next = NULL;

    ret_code = compile(ast->get_fson());
    code->insert(code->end(), ret_code->begin(), ret_code->end());
    delete ret_code;

    code->push_back(jump);

    ret_code = compile(ast->get_fson()->get_rbro());
    code->insert(code->end(), ret_code->begin(), ret_code->end());

    jump_next = new int;
    *jump_next = ret_code->size() + 2;
    jump->get_param()->content_set(jump_next);

    delete ret_code;

    if (ast->get_fson()->get_rbro()->get_rbro())
    {
        jump = new esl::Bytecode(JUMP, new esl::Value(O_INT, NULL));
        code->push_back(jump);

        ret_code = compile(ast->get_fson()->get_rbro()->get_rbro());
        code->insert(code->end(), ret_code->begin(), ret_code->end());

        jump_next = new int;
        *jump_next = ret_code->size() + 1;
        jump->get_param()->content_set(jump_next);


        delete ret_code;
    }

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_assignement(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = nullptr;
    std::string                 *value = nullptr;

    code = compile(ast->get_fson()->get_rbro());

    value = new std::string(*(ast->get_fson()->get_content()));

    code->push_back(new esl::Bytecode(STORE, new esl::Value(O_STRING, value)));

    return code;
}

std::vector<esl::Bytecode*>* esl::Compiler::compile_arith (esl::Ast* ast,
                                                           enum instr i)
{
    std::vector<esl::Bytecode*>* code = nullptr;
    std::vector<esl::Bytecode*>* ret_code = nullptr;

    code = compile(ast->get_fson());

    ret_code = compile(ast->get_fson()->get_rbro());

    code->insert(code->end(), ret_code->begin(), ret_code->end());

    code->push_back(new esl::Bytecode(i, new esl::Value(O_NIL, nullptr)));

    delete ret_code;

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_number(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = new std::vector<esl::Bytecode *>;

    int *value = new int;

    *value = esl::Utils::atoi(*(ast->get_content()));

    code->push_back(new esl::Bytecode(LOAD_CST, new esl::Value(O_INT, value)));

    return code;
}

std::vector<esl::Bytecode *> *esl::Compiler::compile_identifier(esl::Ast *ast)
{
    std::vector<esl::Bytecode *> *code = new std::vector<esl::Bytecode *>;

    std::string* value = new std::string(ast->get_content()->c_str());

    code->push_back(new esl::Bytecode(LOAD, new esl::Value(O_STRING, value)));

    return code;

}
