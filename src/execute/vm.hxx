template<class Func>
void esl::Vm::math(Func fun)
{
    esl::ContentObject* obj1 = nullptr;
    esl::ContentObject* obj2 = nullptr;
    esl::ContentObject* obj_ret = nullptr;
    esl::Value* v1 = nullptr;
    esl::Value* v2 = nullptr;
    esl::Value* v_ret = nullptr;

    obj1 = static_cast<esl::ContentObject*>(this->stack_->top());

    if (obj1 == nullptr || obj1->type_get() != O_VALUE)
        throw MathException();

    v1 = static_cast<esl::Value*>(obj1->content_get());

    if (obj1 == nullptr || v1 == nullptr)
        throw MathException();

    this->stack_->pop();

    obj2 = static_cast<esl::ContentObject*>(this->stack_->top());

    if (obj2 == nullptr || obj2->type_get() != O_VALUE)
        throw MathException();

    v2 = static_cast<esl::Value*>(obj2->content_get());

    if (v2 == nullptr)
        throw MathException();

    this->stack_->pop();

    int *op1 = static_cast<int*>(v1->content_get());
    int *op2 = static_cast<int*>(v2->content_get());

    if (op1 == nullptr || op2 == nullptr)
        throw MathException();

    int *result = new int;
    *result = fun(*op2, *op1);

    v_ret = new esl::Value(O_INT, result);
    obj_ret = new esl::ContentObject(O_VALUE, v_ret);

    this->stack_->push(obj_ret);
}

