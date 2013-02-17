#include "ast.hh"

namespace ast
{
    /* Constuctors & destructor */
    Ast::Ast()
    {
        this->tok_ = EMPTY;
        this->rbro_ = nullptr;
        this->fson_ = nullptr;
        this->content_ = -1;
    }

    Ast::Ast(const yy::location& location)
        : location_(location)
    {}

    Ast::Ast(token tok)
    {
        this->tok_ = tok;
        this->rbro_ = nullptr;
        this->fson_ = nullptr;
        this->content_ = -1;
    }

    Ast::Ast(token tok, int content)
    {
        this->tok_ = tok;
        this->rbro_ = nullptr;
        this->fson_ = nullptr;
        this->content_ = content;
    }

    Ast::Ast(token tok, std::string *content)
    {
        this->tok_ = tok;
        this->rbro_ = nullptr;
        this->fson_ = nullptr;
        this->content_ = -1;

        bool temp = false;

        content_ = esl::RoData::instance_get()->store(content, temp);

        if (temp)
            delete content;
    }

    Ast::Ast(token tok, Ast* son)
    {
        this->tok_ = tok;
        this->rbro_ = nullptr;
        this->fson_ = nullptr;
        this->content_ = -1;

        add(son);
    }


    Ast::~Ast()
    {
        delete rbro_;
        delete fson_;
    }

    /* Getter */
    int Ast::get_id()
    {
        return id_ast_;
    }

    token Ast::get_token()
    {
        return this->tok_;
    }

    int Ast::get_content()
    {
        return this->content_;
    }

    Ast *Ast::get_fson()
    {
        return this->fson_;
    }

    Ast *Ast::get_rbro()
    {
        return this->rbro_;
    }

    /* Setter */
    void Ast::set_id(int id)
    {
        id_ast_ = id;
    }

    void Ast::set_token(token tok)
    {
        this->tok_ = tok;
    }

    /* Public members */
    void Ast::add(Ast *ast)
    {
        Ast *temp = nullptr;

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

    int Ast::unique_id(int reset)
    {
        static int id = 0;

        if (reset)
            id = 0;
        else
            ++id;

        return id;
    }

    void Ast::add(token tok, std::string *content)
    {
        add(new Ast(tok, content));
    }

    void Ast::print_node(Ast *node, std::ofstream &file)
    {
        file << "N_" << node->get_id() << " [label=\"";
        file << token_string[node->get_token()];

        file << "\"]" << std::endl;
    }

    void Ast::print_sons(Ast *sons, int id_father, std::ofstream &file)
    {
        Ast *temp = nullptr;

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

    void Ast::print()
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

    Ast *Ast::create_node(token tok, std::string *content)
    {
        return new Ast(tok, content);
    }

    Ast *Ast::ast_from_list(std::list<Ast *> *l)
    {
        Ast *ast = new Ast(STATEMENTS);

        for (std::list<Ast *>::iterator i = l->begin(); i != l->end(); ++i)
            ast->add(*i);

        delete l;

        return ast;
    }
}
