#include "function.hh"

namespace esl
{
    Function::Function (int pc)
        : pc_ (pc)
        , callback_ (nullptr)
    {}

    Function::Function (DelegateBase* callback)
        : pc_ (-1)
        , callback_ (callback)
    {}

    Function::~Function ()
    {
        if (callback_)
            delete callback_;
    }

    GCObject* Function::call (Context* context,
                              const Params& params) const
    {
        if (callback_) /* External call */
            return callback_->Call(params, context);
        else
        {
            context->pc_set(pc_ + 1);
            return nullptr;
        }
    }
} // namespace esl
