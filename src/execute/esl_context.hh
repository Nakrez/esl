#ifndef ESL_CONTEXT_H_
# define ESL_CONTEXT_H_

# include <string>
# include <unordered_map>

# include <execute/esl_variable.hh>

class esl_context
{
    public:
        esl_context();
        ~esl_context();

        esl_variable *get_variable(std::string);
        int get_function(std::string);
        void set_variable(const std::string &, esl_variable *);
        void set_function(const std::string &, int);

    private:
        std::unordered_map<std::string, esl_variable *>  *variables;
        std::unordered_map<std::string, int>             *functions;
};

#endif /* !ESL_CONTEXT_H_ */
