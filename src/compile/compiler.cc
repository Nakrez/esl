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

    // Test the type of the ast node and call the right method to compile it
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
        case ADD: compile_operation(ast, OP_ADD);
                  break;
        case MINUS: compile_operation(ast, OP_MINUS);
                    break;
        case MUL: compile_operation(ast, OP_MUL);
                  break;
        case DIV: compile_operation(ast, OP_DIV);
                  break;
        case MOD: compile_operation(ast, OP_MOD);
                  break;
        case POW: compile_operation(ast, OP_POW);
                  break;
        case EQ: compile_operation(ast, OP_EQ);
                 break;
        case DIFF: compile_operation(ast, OP_DIFF);
                   break;
        case LT: compile_operation(ast, OP_LT);
                 break;
        case LE: compile_operation(ast, OP_LE);
                 break;
        case GT:  compile_operation(ast, OP_GT);
                  break;
        case GE:  compile_operation(ast, OP_GE);
                  break;
        case OR:  compile_operation(ast, OP_OR);
                  break;
        case AND:  compile_operation(ast, OP_AND);
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
        case FUNCTION_CALL:  compile_call(ast, false);
                             break;
        case METHOD_CALL: compile_method_call(ast);
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

void esl::Compiler::compile_method_call (Ast* ast)
{
    // Compile the left part of the call (before "->")
    compile(ast->get_fson());

    // Compile the right part of the call (after "->")
    compile_call(ast->get_fson()->get_rbro(), true);
}

void esl::Compiler::compile_assignement_array (Ast* ast)
{
    // Node containing the expr inside []
    esl::Ast* temp_ast = ast->get_fson()->get_rbro()->get_fson()->get_fson();

    // Compile value received
    compile(ast->get_fson()->get_rbro()->get_rbro());

    // Compile array name
    compile(ast->get_fson());

    // Compile everything between []
    while (temp_ast)
    {
        compile(temp_ast);
        byte_code_.push_back(new esl::Bytecode(OP_BRACKET));
        temp_ast = temp_ast->get_rbro();
    }

    byte_code_.push_back(new esl::Bytecode(STORE_STK));
    // Pop the result because it's not used
    byte_code_.push_back(new esl::Bytecode(POP));
}

void esl::Compiler::compile_array_at(Ast* ast)
{
    // Node containing the expr inside []
    esl::Ast* temp_ast = ast->get_fson()->get_rbro()->get_fson();

    // Compile array name
    compile(ast->get_fson());

    // Compile everything between []
    while (temp_ast)
    {
        compile(temp_ast);
        byte_code_.push_back(new esl::Bytecode(OP_BRACKET));
        temp_ast = temp_ast->get_rbro();
    }
}

void esl::Compiler::compile_module_call(Ast* ast)
{
    // For parameter delimitation
    byte_code_.push_back(new esl::Bytecode(DELIM));

    // If the module call got params then compile it
    if (ast->get_fson() && ast->get_fson()->get_fson())
        compile(ast->get_fson()->get_fson());

    // Build call instruction
    byte_code_.push_back(new esl::Bytecode(MODULE, ast->get_content()));
    byte_code_.push_back(new esl::Bytecode(CALL_MODULE,
                                           ast->get_fson()->get_content()));
}

void esl::Compiler::compile_loop(Ast* ast, instr i)
{
    // The instruction that return to the condition
    esl::Bytecode* instruction_back = nullptr;
    // The instruction that perform the condition
    esl::Bytecode* instruction_false = nullptr;
    // The adress of the back jump
    int jump_addr_back = 0;
    // The adress if the condition is false
    int jump_addr_false = 0;

    jump_addr_back = byte_code_.size();

    compile(ast->get_fson());

    jump_addr_false = byte_code_.size();

    instruction_false = new esl::Bytecode(i);
    byte_code_.push_back(instruction_false);

    // Compile the loop code
    compile(ast->get_fson()->get_rbro());

    // Calculate jump back adress
    jump_addr_back = - (byte_code_.size() - jump_addr_back);

    instruction_back = new esl::Bytecode(JUMP, jump_addr_back);

    // Calculate jump if false adress
    jump_addr_false = byte_code_.size() - jump_addr_false + 1;
    instruction_false->set_param(jump_addr_false);

    byte_code_.push_back(instruction_back);
}

void esl::Compiler::compile_statements(esl::Ast* ast)
{
    while (ast)
    {
        compile(ast);

        // Push a pop because result is not used
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
    // Compile the expression returned
    compile(ast->get_fson());
    byte_code_.push_back(new esl::Bytecode(RETURN));
}

void esl::Compiler::compile_list_id(esl::Ast* ast)
{
    esl::Ast* temp_ast = nullptr;

    // The first id
    temp_ast = ast->get_fson();

    // Compiling all ID
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

    // The first element of the list
    temp_ast = ast->get_fson();

    // Compile all the element in the list
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

    // Get the code of the function
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

void esl::Compiler::compile_call(esl::Ast* ast, bool method)
{
    esl::Ast *temp_ast = nullptr;

    // Load args
    if (ast->get_fson())
        temp_ast = ast->get_fson()->get_fson();

    byte_code_.push_back(new esl::Bytecode(DELIM));

    // Compile args if there is some
    if (temp_ast)
        compile(ast->get_fson());

    // If the call is a method call
    if (method)
        byte_code_.push_back(new esl::Bytecode(CALL_METHOD,
                                               ast->get_content()));
    else
        byte_code_.push_back(new esl::Bytecode(CALL_FUNCTION,
                                               ast->get_content()));
}

void esl::Compiler::compile_if(esl::Ast *ast)
{
    int jump_next = 0;
    esl::Bytecode* jump = new esl::Bytecode(JUMP_IF_FALSE);
    compile(ast->get_fson());

    byte_code_.push_back(jump);

    jump_next = byte_code_.size();

    compile(ast->get_fson()->get_rbro());

    // Calculate the jump if the if is false
    jump_next = byte_code_.size() - jump_next + 1 +
                ((ast->get_fson()->get_rbro()->get_rbro()) ? 1 : 0);

    jump->set_param(jump_next);

    // If there is a else or a else if
    if (ast->get_fson()->get_rbro()->get_rbro())
    {
        jump_next = 0;

        // Jump to avoid else/else if, if the if condition is true
        jump = new esl::Bytecode(JUMP);
        byte_code_.push_back(jump);

        jump_next = byte_code_.size();

        //Compile else if/else
        compile(ast->get_fson()->get_rbro()->get_rbro());

        jump_next = byte_code_.size() - jump_next + 1;
        jump->set_param(jump_next);
    }
}

void esl::Compiler::compile_assignement(esl::Ast* ast)
{
    // Compile the value assigned
    compile(ast->get_fson()->get_rbro());

    byte_code_.push_back(new esl::Bytecode(STORE,
                                           ast->get_fson()->get_content()));
}

void esl::Compiler::compile_operation (esl::Ast* ast, enum instr i)
{
    // Compile left operand
    compile(ast->get_fson());

    // Compile right operand
    compile(ast->get_fson()->get_rbro());

    // Add the operation's bytecode
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
