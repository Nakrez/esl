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
    squeleton->register_method (name_, "is_open",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::is_open)));

    squeleton->register_method (name_, "close",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::close)));

    squeleton->register_method (name_, "read_line",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::read_line)));

    squeleton->register_method (name_, "read_all",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::read_all)));

    squeleton->register_method (name_, "seek_beg",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::seek_beg)));

    squeleton->register_method (name_, "seek_end",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::seek_end)));

    squeleton->register_method (name_, "eof",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::eof)));

    squeleton->register_method (name_, "write",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::write)));

    squeleton->register_method (name_, "write_newline",
                                new Function(new Delegate<esl::File>(this,
                                                                     &esl::File::write_newline)));
}

esl::GCObject* esl::File::construct (const Params& params)
{
    esl::FileObject* file = nullptr;

    if (params.count() == 1)
        file = new esl::FileObject();
    else
    {
    }

    return new esl::GCObject(file);
}

esl::GCObject* esl::File::print (const esl::Params&)
{
    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::File::to_string (const esl::Params&)
{
    return new esl::GCObject (new esl::StringObject("File"));
}

esl::GCObject* esl::File::open (const esl::Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (params.count() == 1 || params.count() > 3)
        throw esl::Exception("Method open takes 1 or 2 parameter(s)");

    if (params.count() == 2)
    {
        esl::GCObject* object1 = params.get_params(2);
        esl::StringObject* param1 = dynamic_cast<esl::StringObject*>(object1->data_get());

        if (!param1)
            throw esl::Exception("First parameter of open must be a string");

        file->open(param1->data_get());
    }
    else
    {
        esl::GCObject* object1 = params.get_params(2);
        esl::StringObject* param1 = dynamic_cast<esl::StringObject*>(object1->data_get());
        esl::GCObject* object2 = params.get_params(3);
        esl::StringObject* param2 = dynamic_cast<esl::StringObject*>(object2->data_get());

        if (!param1)
            throw esl::Exception("First parameter of open must be a string");
        if (!param2)
            throw esl::Exception("Second parameter of open must be a string");

        file->open(param1->data_get(), param2->data_get());
    }

    return new esl::GCObject (new esl::IntObject(file->is_open()));
}

esl::GCObject* esl::File::is_open (const esl::Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    return new esl::GCObject (new esl::IntObject(file->is_open()));
}

esl::GCObject* esl::File::close (const esl::Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (file->is_open())
        file->close();

    return new esl::GCObject (new esl::IntObject(0));
}
esl::GCObject* esl::File::read_line (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    return new esl::GCObject (new esl::StringObject(file->read_line()));
}

esl::GCObject* esl::File::read_all (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    return new esl::GCObject (new esl::StringObject(file->read_all()));
}

esl::GCObject* esl::File::seek_beg (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    file->seek_beg();

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::File::seek_end (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    file->seek_end();

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::File::write (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (params.count() != 2)
        throw esl::Exception("write_newline method takes 1 argument");

    esl::StringObject* buf = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!buf)
        throw esl::Exception("First parameter of write_newline must be a string");

    file->write(buf->data_get());

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::File::eof (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    return new esl::GCObject (new esl::IntObject(file->eof()));
}

esl::GCObject* esl::File::write_newline (const Params& params)
{
    esl::FileObject* file = dynamic_cast<esl::FileObject*>(params.get_params(1)->data_get());

    if (params.count() != 2)
        throw esl::Exception("write_newline method takes 1 argument");

    esl::StringObject* buf = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!buf)
        throw esl::Exception("First parameter of write_newline must be a string");

    file->write_newline(buf->data_get());

    return new esl::GCObject (new esl::IntObject(0));
}
