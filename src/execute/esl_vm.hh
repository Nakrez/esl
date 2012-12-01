#ifndef ESL_VM_H_
# define ESL_VM_H_

# include <vector>

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
};

#endif /* !ESL_VM_H_ */
