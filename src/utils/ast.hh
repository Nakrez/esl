#ifndef AST_HH
# define AST_HH

# include <string>
# include <list>
# include <iostream>
# include <fstream>

# include "ro-data.hh"
# include "token.hh"

namespace esl
{
    class Ast
    {
        public:
            Ast();
            Ast(token tok);
            Ast(token tok, std::string* content);
            Ast(token tok, Ast* content);
            Ast(token tok, int content);
            ~Ast();

            void print();
            void add(Ast *ast);
            void add(token tok, std::string *content);

            Ast *create_node(token tok, std::string *content);

            int get_id();
            token get_token();
            int get_content();
            Ast *get_fson();
            Ast *get_rbro();

            void set_id(int id);
            void set_token(token tok);

            static Ast *ast_from_list(std::list<Ast *> *);

        private:
            void print_sons(Ast *sons, int id_father, std::ofstream &file);
            void print_node(Ast *node, std::ofstream &file);

        private:
            static int unique_id(int reset);

        private:
            int id_ast_;
            token tok_;
            int content_;
            Ast *rbro_;
            Ast *fson_;
    };
}
#endif /* ESL_AST_H_ */
