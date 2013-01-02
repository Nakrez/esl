#include "compiler.hh"

esl::Compiler::Compiler(esl::Ast *ast)
{
    this->gen_ast_ = ast;
}

esl::Compiler::~Compiler()
{
    for (std::vector<esl::Bytecode *>::iterator i = this->byte_code_.begin();
         i != byte_code_.end(); ++ i)
        delete *i;
}

/* Getter */
std::vector<esl::Bytecode *> esl::Compiler::get_bytecode()
{
    return this->byte_code_;
}

void esl::Compiler::compile()
{
    compile(this->gen_ast_);
    this->byte_code_.push_back(new esl::Bytecode(NOP));
}

void esl::Compiler::export_bytecode(const std::string &filename)
{
    std::vector<esl::Bytecode *>::iterator begin = this->byte_code_.begin();
    std::vector<esl::Bytecode *>::iterator end = this->byte_code_.end();
    std::ofstream file;
    int line = 0;

    file.open(filename.c_str(), std::ios::out);

    file << *RoData::instance_get();

    for (; begin != end; ++begin, ++line)
    {
        file << line << " " << **begin;
    }

    file.close();
}

/* Private Members */

void esl::Compiler::compile(esl::Ast *ast)
{
    if (ast == nullptr)
        return;

    switch (ast->get_token())
    {
        case STATEMENTS: compile_statements(ast->get_fson());
                         break;
        case ASSIGNEMENT: compile_assignement(ast);
                          break;
        case ASSIGNEMENT_ARRAY: compile_assignement_array(ast);
                          break;
        case ARRAY_AT: compile_array_at(ast);
                       break;
        case ADD: compile_operation(ast, ARITH_ADD);
                  break;
        case MINUS: compile_operation(ast, ARITH_MINUS);
                    break;
        case MUL: compile_operation(ast, ARITH_MUL);
                  break;
        case DIV: compile_operation(ast, ARITH_DIV);
                  break;
        case MOD: compile_operation(ast, ARITH_MOD);
                  break;
        case EQ: compile_operation(ast, BOOL_EQ);
                 break;
        case DIFF: compile_operation(ast, BOOL_DIFF);
                   break;
        case LT: compile_operation(ast, BOOL_LT);
                 break;
        case LE: compile_operation(ast, BOOL_LE);
                 break;
        case GT:  compile_operation(ast, BOOL_GT);
                  break;
        case GE:  compile_operation(ast, BOOL_GE);
                  break;
        case OR:  compile_operation(ast, BOOL_OR);
                  break;
        case AND:  compile_operation(ast, BOOL_AND);
                   break;
        case NUMBER:  compile_number(ast);
                      break;
        case STRING:  compile_string(ast);
                      break;
        case EXPR:  compile(ast->get_fson());
                    break;
        case ID:  compile_identifier(ast);
                  break;
        case IF:  compile_if(ast);
                  break;
        case FUNCTION_DECL:  compile_function(ast);
                             break;
        case FUNCTION_CALL:  compile_call(ast);
                             break;
        case LIST:  compile_list(ast);
                    break;
        case LIST_ID:  compile_list_id(ast);
                       break;
        case RETURN_STM:  compile_return(ast);
                          break;
        case WHILE:  compile_loop(ast, JUMP_IF_FALSE);
                     break;
        case UNTIL:  compile_loop(ast, JUMP_IF_TRUE);
                     break;
        case IMPORT:  compile_import(ast);
                      break;
        case MODULE_CALL:  compile_module_call(ast);
                           break;
        default : break;
    }
}

void esl::Compiler::compile_assignement_array(Ast* ast)
{
    esl::Ast* temp_ast = ast->get_fson()->get_rbro()->get_fson()->get_fson();

    compile(ast->get_fson()->get_rbro()->get_rbro());

    compile(ast->get_fson());

    while (temp_ast)
    {
        compile(temp_ast);
        byte_code_.push_back(new esl::Bytecode(ARRAY_VAL));
        temp_ast = temp_ast->get_rbro();
    }

    byte_code_.push_back(new esl::Bytecode(STORE_STK));
    byte_code_.push_back(new esl::Bytecode(POP));
}

void esl::Compiler::compile_array_at(Ast* ast)
{
    esl::Ast* temp_ast = ast->get_fson()->get_rbro()->get_fson();

    compile(ast->get_fson());

    while (temp_ast)
    {
        compile(temp_ast);
        byte_code_.push_back(new esl::Bytecode(ARRAY_VAL));
        temp_ast = temp_ast->get_rbro();
    }
}

void esl::Compiler::compile_module_call(Ast* ast)
{
    byte_code_.push_back(new esl::Bytecode(DELIM));

    if (ast->get_fson() && ast->get_fson()->get_fson())
        compile(ast->get_fson()->get_fson());

    /* Build call instruction (check special code for built in) */
    byte_code_.push_back(new esl::Bytecode(MODULE, ast->get_content()));
    byte_code_.push_back(new esl::Bytecode(CALL_MODULE,
                                           ast->get_fson()->get_content()));
}

void esl::Compiler::compile_loop(Ast* ast, instr i)
{
    esl::Bytecode* instruction_back = nullptr;
    esl::Bytecode* instruction_false = nullptr;
    int jump_addr_back = 0;
    int jump_addr_false = 0;

    jump_addr_back = byte_code_.size();

    compile(ast->get_fson());

    jump_addr_false = byte_code_.size();

    instruction_false = new esl::Bytecode(i);
    byte_code_.push_back(instruction_false);

    compile(ast->get_fson()->get_rbro());

    jump_addr_back = - (byte_code_.size() - jump_addr_back);

    instruction_back = new esl::Bytecode(JUMP, jump_addr_back);

    jump_addr_false = byte_code_.size() - jump_addr_false + 1;
    instruction_false->set_param(jump_addr_false);

    byte_code_.push_back(instruction_back);
}

void esl::Compiler::compile_statements(esl::Ast* ast)
{
    while (ast)
    {
        compile(ast);

        if (ast->get_token() == EXPR ||
            ast->get_token() == ASSIGNEMENT ||
            ast->get_token() == FUNCTION_CALL ||
            ast->get_token() == MODULE_CALL)
            byte_code_.push_back(new esl::Bytecode(POP));
        ast = ast->get_rbro();
    }
}

void esl::Compiler::compile_return(esl::Ast* ast)
{
    compile(ast->get_fson());
    byte_code_.push_back(new esl::Bytecode(RETURN));
}

void esl::Compiler::compile_list_id(esl::Ast* ast)
{
    esl::Ast* temp_ast = nullptr;

    temp_ast = ast->get_fson();

    while (temp_ast)
    {
        byte_code_.push_back(new esl::Bytecode(STORE,
                                               temp_ast->get_content()));
        byte_code_.push_back(new esl::Bytecode(POP));

        temp_ast = temp_ast->get_rbro();
    }
}

void esl::Compiler::compile_list(esl::Ast* ast)
{
    esl::Ast* temp_ast = nullptr;

    temp_ast = ast->get_fson();

    while (temp_ast)
    {
        compile(temp_ast);

        temp_ast = temp_ast->get_rbro();
    }
}

void esl::Compiler::compile_function(esl::Ast* ast)
{
    esl::Bytecode* jump = nullptr;
    int jump_addr = 0;
    int code_size;
    int avoid = 1;

    code_size = byte_code_.size();

    byte_code_.push_back(new esl::Bytecode(MAKE_FUNCTION, ast->get_content()));

    /*
    ** Add instruction JUMP after MAKE_FUNCTION
    ** The adress will be calculate after code compilation
    */
    jump = new esl::Bytecode(JUMP);

    byte_code_.push_back(jump);

    /* If there is param LOAD them in the stack */
    if (ast->get_fson()->get_token() != EMPTY)
    {
        compile_list_id(ast->get_fson());
        jump_addr = byte_code_.size() - code_size - 1;
        avoid = 0;
    }

    code_size = byte_code_.size();

    /* Get the code of the function */
    compile(ast->get_fson()->get_rbro());

    /*
    ** Calculate the JUMP adress
    ** The +1 is to JUMP after RETURN instruction
    */

    jump_addr += byte_code_.size() - code_size + 1 + avoid;
    jump->set_param(jump_addr);

    /* Add instruction RETURN */
    byte_code_.push_back(new esl::Bytecode(RETURN));
}

void esl::Compiler::compile_call(esl::Ast* ast)
{
    esl::Ast *temp_ast = nullptr;

    /* Load args */
    if (ast->get_fson())
        temp_ast = ast->get_fson()->get_fson();

    byte_code_.push_back(new esl::Bytecode(DELIM));

    if (temp_ast)
        compile(ast->get_fson());

    /* Build call instruction (check special code for built in) */
    byte_code_.push_back(new esl::Bytecode(CALL_FUNCTION, ast->get_content()));
}

void esl::Compiler::compile_if(esl::Ast *ast)
{
    int jump_next = 0;
    esl::Bytecode* jump = new esl::Bytecode(JUMP_IF_FALSE);
    compile(ast->get_fson());

    byte_code_.push_back(jump);

    jump_next = byte_code_.size();

    compile(ast->get_fson()->get_rbro());

    jump_next = byte_code_.size() - jump_next + 1 +
                ((ast->get_fson()->get_rbro()->get_rbro()) ? 1 : 0);

    jump->set_param(jump_next);

    if (ast->get_fson()->get_rbro()->get_rbro())
    {
        jump_next = 0;

        jump = new esl::Bytecode(JUMP);
        byte_code_.push_back(jump);

        jump_next = byte_code_.size();
        compile(ast->get_fson()->get_rbro()->get_rbro());

        jump_next = byte_code_.size() - jump_next + 1;
        jump->set_param(jump_next);
    }
}

void esl::Compiler::compile_assignement(esl::Ast* ast)
{
    compile(ast->get_fson()->get_rbro());

    byte_code_.push_back(new esl::Bytecode(STORE,
                                           ast->get_fson()->get_content()));
}

void esl::Compiler::compile_operation (esl::Ast* ast, enum instr i)
{
    compile(ast->get_fson());

    compile(ast->get_fson()->get_rbro());

    byte_code_.push_back(new esl::Bytecode(i));

}

void esl::Compiler::compile_number(esl::Ast *ast)
{
    byte_code_.push_back(new esl::Bytecode(LOAD_INT, ast->get_content()));
}

void esl::Compiler::compile_string(esl::Ast *ast)
{
    byte_code_.push_back(new esl::Bytecode(LOAD_STR, ast->get_content()));
}

void esl::Compiler::compile_identifier(esl::Ast *ast)
{
    byte_code_.push_back(new esl::Bytecode(LOAD, ast->get_content()));
}

void esl::Compiler::compile_import(esl::Ast *ast)
{
    byte_code_.push_back(new esl::Bytecode(OPEN, ast->get_content()));
}
