#include "ast.hh"

/* Constuctors & destructor */
esl::Ast::Ast()
{
    this->tok_ = EMPTY;
    this->rbro_ = nullptr;
    this->fson_ = nullptr;
}

esl::Ast::Ast(token tok, const std::string &content)
{
    this->tok_ = tok;
    this->content_ = new std::string(content);
    this->rbro_ = nullptr;
    this->fson_ = nullptr;
}

esl::Ast::~Ast()
{
    delete content_;
    delete rbro_;
    delete fson_;
}

/* Getter */
int esl::Ast::get_id()
{
    return id_ast_;
}

token esl::Ast::get_token()
{
    return this->tok_;
}

std::string *esl::Ast::get_content()
{
    return this->content_;
}

esl::Ast *esl::Ast::get_fson()
{
    return this->fson_;
}

esl::Ast *esl::Ast::get_rbro()
{
    return this->rbro_;
}

/* Setter */
void esl::Ast::set_id(int id)
{
    id_ast_ = id;
}

void esl::Ast::set_token(token tok)
{
    this->tok_ = tok;
}

/* Public members */
void esl::Ast::add(esl::Ast *ast)
{
    esl::Ast *temp = nullptr;

    if (this->tok_ == EMPTY)
    {
        this->tok_ = ast->tok_;
        this->content_ = ast->content_;
        this->rbro_ = ast->rbro_;
        this->fson_ = ast->fson_;
        delete ast;
    }
    else if (this->fson_ == nullptr)
        this->fson_ = ast;
    else
    {
        temp = this->fson_;

        while (temp->rbro_ != nullptr)
            temp = temp->rbro_;

        temp->rbro_ = ast;
    }
}

int esl::Ast::unique_id(int reset)
{
    static int id = 0;

    if (reset)
        id = 0;
    else
        ++id;

    return id;
}

void esl::Ast::add(token tok, const std::string &content)
{
    add(new esl::Ast(tok, content));
}

void esl::Ast::print_node(esl::Ast *node, std::ofstream &file)
{
    file << "N_" << node->get_id() << " [label=\"";
    file << token_string[node->get_token()];

    if (*(node->get_content()) != std::string(""))
        file << ", " << node->get_content()->c_str();

    file << "\"]" << std::endl;
}

void esl::Ast::print_sons(esl::Ast *sons, int id_father, std::ofstream &file)
{
    esl::Ast *temp = nullptr;

    if (sons != nullptr)
    {
        temp = sons;
        do
        {
            temp->set_id(unique_id(0));
            print_node(temp, file);
            file << "N_" << id_father << " -- N_" 
                 << temp->get_id() << std::endl;
            print_sons(temp->fson_, temp->get_id(), file);
            temp = temp->rbro_;
        }
        while (temp);
    }
}

void esl::Ast::print()
{
    std::ofstream file;

    unique_id(1);

    file.open("tree.dot", std::ios::out);

    file << "graph ast {" << std::endl;

    set_id(unique_id(0));
    print_node(this, file);
    print_sons(this->fson_, this->get_id(), file);
    file << "}" << std::endl;

    file.close();
}

/* Static members */

esl::Ast *esl::Ast::create_node(token tok, const std::string &content)
{
    return new esl::Ast(tok, content);
}

esl::Ast *esl::Ast::ast_from_list(std::list<esl::Ast *> *l)
{
    esl::Ast *ast = new esl::Ast(STATEMENTS, "");

    for (std::list<esl::Ast *>::iterator i = l->begin(); i != l->end(); ++i)
        ast->add(*i);

    delete l;

    return ast;
}
