#include "function.hh"

esl::Function::Function (int pc)
    : pc_ (pc)
    , callback_ (nullptr)
{

}

esl::Function::Function (esl::DelegateBase* callback)
    : pc_ (-1)
    , callback_ (callback)
{

}

esl::Function::~Function ()
{
    if (callback_)
        delete callback_;
}

esl::MemContent esl::Function::call (esl::Context* context,
                                     const esl::Params& params) const
{
    if (callback_) /* External call */
        return callback_->Call(params);
    else
    {
        context->pc_set(pc_ + 1);
        return nullptr;
    }
}
