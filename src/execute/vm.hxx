template<class Func>
void esl::Vm::math(Func fun)
{
    esl::Value* obj1 = nullptr;
    esl::Value* obj2 = nullptr;
    esl::Value* v_ret = nullptr;

    obj1 = static_cast<esl::Value*>(this->stack_.top());

    if (obj1 == nullptr || obj1->type_get() != O_INT)
        throw MathException();

    this->stack_.pop();

    obj2 = static_cast<esl::Value*>(this->stack_.top());

    if (obj2 == nullptr || obj2->type_get() != O_INT)
    {
        std::cout << obj2->type_get() << std::endl;
        throw MathException();
    }

    this->stack_.pop();

    int *op1 = static_cast<int*>(obj1->content_get());
    int *op2 = static_cast<int*>(obj2->content_get());

    if (op1 == nullptr || op2 == nullptr)
        throw MathException();

    int *result = new int;
    *result = fun(*op2, *op1);

    v_ret = new esl::Value(O_INT, result);

    this->stack_.push(v_ret);
}

