#include <utils/esl_ast.hh>

/* Constuctors & destructor */
esl_ast::esl_ast()
{
    this->tok = EMPTY;
    this->rbro = NULL;
    this->fson = NULL;
}

esl_ast::esl_ast(token tok, const std::string &content)
{
    this->tok = tok;
    this->content = new std::string(content);
    this->rbro = NULL;
    this->fson = NULL; 
}

esl_ast::~esl_ast()
{
    delete content;
    delete rbro;
    delete fson;
}

/* Public members */

void esl_ast::add(esl_ast *ast)
{
    esl_ast *temp = NULL;

    if (this->tok == EMPTY)
    {
        this->tok = ast->tok;
        this->content = ast->content;
        this->rbro = ast->rbro;
        this->fson = ast->fson;
        delete ast;
    }
    else if (this->fson == NULL)
        this->fson = ast;
    else
    {
        temp = this->fson;

        while (temp->rbro != NULL)
            temp = temp->rbro;

        temp->rbro = ast;
    }
}

void esl_ast::add(token tok, const std::string &content)
{
    add(new esl_ast(tok, content));
}

void esl_ast::print()
{
    
}

/* Static members */

esl_ast *esl_ast::create_node(token tok, const std::string &content)
{
    return new esl_ast(tok, content);
}
