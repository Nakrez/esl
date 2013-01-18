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
