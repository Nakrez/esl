#ifndef ESL_CONTEXT_H_
# define ESL_CONTEXT_H_

# include <string>
# include <unordered_map>

# include <utils/esl_value.hh>

class esl_context
{
    public:
        esl_context();
        ~esl_context();

        esl_value *get_variable(std::string);
        size_t get_function(std::string);
        size_t get_pc();
        void set_variable(const std::string &, esl_value *);
        void set_function(const std::string &, size_t);
        void set_pc(size_t);
        void incr_pc(size_t);

    private:
        std::unordered_map<std::string, esl_value *>            *variables;
        std::unordered_map<std::string, size_t>                 *functions;
        size_t                                                  pc;
};

#endif /* !ESL_CONTEXT_H_ */
