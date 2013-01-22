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

esl::FileObject::~FileObject ()
{
    if (data_.is_open())
        data_.close();
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

int esl::FileObject::is_open () const
{
    return data_.is_open();
}

void esl::FileObject::close ()
{
    data_.close();
}

std::string esl::FileObject::read_line ()
{
    if (!data_.is_open())
        throw esl::Exception("Can not read a file that is not open");
    std::string result;
    std::getline(data_, result);

    return result;
}

std::string esl::FileObject::read_all ()
{
    if (!data_.is_open())
        throw esl::Exception("Can not read a file that is not open");

    std::stringstream buffer;
    buffer << data_.rdbuf();

    return buffer.str();
}

void esl::FileObject::seek_beg ()
{
    data_.seekg(0, std::ios::beg);
    data_.seekp(0, std::ios::beg);
}

void esl::FileObject::seek_end ()
{
    data_.seekg(0, std::ios::end);
    data_.seekp(0, std::ios::end);
}

int esl::FileObject::eof () const
{
    return data_.eof();
}
