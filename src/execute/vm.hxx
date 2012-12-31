template<class Func>
void esl::Vm::math(Func fun)
{
    esl::Int* obj1 = nullptr;
    esl::Int* obj2 = nullptr;

    obj1 = dynamic_cast<esl::Int*>(this->stack_.top()->data_get());

    if (obj1 == nullptr)
        throw Exception ("Illegal operation -- Wrong type ?");

    this->stack_.pop();

    obj2 = dynamic_cast<esl::Int*>(this->stack_.top()->data_get());

    if (obj2 == nullptr)
        throw Exception ("Illegal operation -- Wrong type ?");

    this->stack_.pop();

    esl::Int* result = new esl::Int(fun(obj2->data_get(), obj1->data_get()));

    this->stack_.push(new esl::MemoryObject<esl::Content>(result));
}

