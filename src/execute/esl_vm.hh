#ifndef ESL_VM_H_
# define ESL_VM_H_

# include <vector>
# include <stack>

# include <execute/esl_stack_obj.hh>
# include <execute/esl_context.hh>
# include <utils/esl_bytecode.hh>

class esl_vm
{
    public:
        esl_vm(std::vector<esl_bytecode *> *);
        ~esl_vm();

        void run();

    private:
        std::vector<esl_bytecode *> *code;
        int                         pc;
        esl_context                 *current_context;
        std::stack<esl_stack_obj *> *stack;
};

#endif /* !ESL_VM_H_ */
