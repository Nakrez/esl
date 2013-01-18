#include "file-object.hh"
#include "../../lib/type/int-object.hh"

esl::FileObject::FileObject ()
    : Object ("file")
{

}

esl::FileObject::FileObject (const std::string& filename)
    : Object ("file")
{
    open(filename);
}

esl::FileObject::FileObject (const std::string& filename,
                             const std::string& mode)
    : Object ("file")
{
    open(filename, mode);
}

void esl::FileObject::open (const std::string& filename)
{
    data_.open(filename, std::fstream::in);
}

void esl::FileObject::open (const std::string& filename,
                            const std::string& mode)
{
    std::ios_base::openmode flags;

    for (unsigned i = 0; i < mode.length(); ++i)
    {
        switch (mode.at(i))
        {
            case 'r':
                flags |= std::fstream::in;
                break;
            default:
                throw esl::Exception("Unrecognized option");
                break;
        }
    }

    data_.open(filename, flags);
}

esl::FileObject::~FileObject ()
{
    if (data_.is_open())
        data_.close();
}
