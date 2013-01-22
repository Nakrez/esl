#include "file.hh"
#include "../../lib/type/string-object.hh"
#include "../../lib/type/int-object.hh"
#include "file-object.hh"

esl::File::File ()
    : Type ("file")
{
}

esl::File::~File ()
{
}

void esl::File::init()
{
    esl::Squeleton* squeleton = esl::Squeleton::get();

    init_basics();

    squeleton->register_method (name_, "open",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::open)));
    squeleton->register_method (name_, "close",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::close)));
}

esl::MemoryObject<esl::Content>* esl::File::construct (const Params& params)
{
    esl::FileObject* file = nullptr;

    if (params.count() == 1)
        file = new esl::FileObject();
    else
    {
    }

    return new esl::MemoryObject<esl::Content>(file);
}

esl::MemoryObject<esl::Content>* esl::File::print (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::File::to_string (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::StringObject("File"));
}

esl::MemoryObject<esl::Content>* esl::File::open (const esl::Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (params.count() == 1 || params.count() > 3)
        throw esl::Exception("Method open takes 1 or 2 parameter(s)");

    if (params.count() == 2)
    {
        esl::MemoryObject<esl::Content>* object1 = params.get_params(2);
        esl::StringObject* param1 = dynamic_cast<esl::StringObject*>(object1->data_get());

        if (!param1)
            throw esl::Exception("First parameter of open must be a string");

        file->open(param1->data_get());
    }
    else
    {
        esl::MemoryObject<esl::Content>* object1 = params.get_params(2);
        esl::StringObject* param1 = dynamic_cast<esl::StringObject*>(object1->data_get());
        esl::MemoryObject<esl::Content>* object2 = params.get_params(3);
        esl::StringObject* param2 = dynamic_cast<esl::StringObject*>(object2->data_get());

        if (!param1)
            throw esl::Exception("First parameter of open must be a string");
        if (!param2)
            throw esl::Exception("Second parameter of open must be a string");

        file->open(param1->data_get(), param2->data_get());
    }

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(file->is_open()));
}

esl::MemoryObject<esl::Content>* esl::File::close (const esl::Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (file->is_open())
        file->close();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}
