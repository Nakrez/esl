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

/* Getter */
int esl_ast::get_id()
{
    return id_ast;
}

token esl_ast::get_token()
{
    return tok;
}

std::string *esl_ast::get_content()
{
    return content;
}

esl_ast *esl_ast::get_fson()
{
    return this->fson;
}

esl_ast *esl_ast::get_rbro()
{
    return this->rbro;
}

/* Setter */
void esl_ast::set_id(int id)
{
    id_ast = id;
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

int esl_ast::unique_id(int reset)
{
    static int id = 0;

    if (reset)
        id = 0;
    else
        ++id;

    return id;
}

void esl_ast::add(token tok, const std::string &content)
{
    add(new esl_ast(tok, content));
}

void esl_ast::print_node(esl_ast *node, std::ofstream &file)
{
    file << "N_" << node->get_id() << " [label=\"";
    file << token_string[node->get_token()];

    if (*(node->get_content()) != std::string(""))
        file << ", " << node->get_content()->c_str();

    file << "\"]" << std::endl;
}

void esl_ast::print_sons(esl_ast *sons, int id_father, std::ofstream &file)
{
    esl_ast *temp = NULL;

    if (sons != NULL)
    {
        temp = sons;
        do
        {
            temp->set_id(unique_id(0));
            print_node(temp, file);
            file << "N_" << id_father << " -- N_" << temp->get_id() << std::endl;
            print_sons(temp->fson, temp->get_id(), file);
            temp = temp->rbro;
        }
        while (temp);
    }
}

void esl_ast::print()
{
    std::ofstream file;

    unique_id(1);

    file.open("tree.dot", std::ios::out);

    file << "graph ast {" << std::endl;

    set_id(unique_id(0));
    print_node(this, file);
    print_sons(this->fson, this->get_id(), file);
    file << "}" << std::endl;

    file.close();
}

/* Static members */

esl_ast *esl_ast::create_node(token tok, const std::string &content)
{
    return new esl_ast(tok, content);
}

esl_ast *esl_ast::ast_from_list(std::list<esl_ast *> *l)
{
    esl_ast *ast = new esl_ast(STATEMENTS, "");

    for (std::list<esl_ast *>::iterator i = l->begin(); i != l->end(); ++i)
        ast->add(*i);

    delete l;

    return ast;
}
