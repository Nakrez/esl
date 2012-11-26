#ifndef ESL_AST_H_
# define ESL_AST_H_

# include <string>

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

    private:
        token       tok;
        std::string *content;
        esl_ast     *rbro;
        esl_ast     *fson;
};

#endif /* ESL_AST_H_ */
