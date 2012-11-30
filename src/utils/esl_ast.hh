#ifndef ESL_AST_H_
# define ESL_AST_H_

# include <string>
# include <list>
# include <iostream>
# include <fstream>

# include <utils/token.hh>

class esl_ast
{
    public:
        esl_ast();
        esl_ast(token tok, const std::string &content);
        ~esl_ast();

        void print();
        void add(esl_ast *ast);
        void add(token tok, const std::string &content);

        esl_ast *create_node(token tok, const std::string &content);

        int get_id();
        token get_token();
        std::string *get_content();
        esl_ast *get_fson();
        esl_ast *get_rbro();

        void set_id(int id);
        void set_token(token tok);

        static esl_ast *ast_from_list(std::list<esl_ast *> *);

    private:
        void print_sons(esl_ast *sons, int id_father, std::ofstream &file);
        void print_node(esl_ast *node, std::ofstream &file);

    private:
        static int unique_id(int reset);

    private:
        int         id_ast;
        token       tok;
        std::string *content;
        esl_ast     *rbro;
        esl_ast     *fson;
};

#endif /* ESL_AST_H_ */
