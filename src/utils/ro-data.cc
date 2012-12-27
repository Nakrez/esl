#include "ro-data.hh"

esl::RoData* esl::RoData::instance_ = nullptr;

esl::RoData* esl::RoData::instance_get ()
{
    if (instance_ == nullptr)
        instance_ = new RoData ();

    return instance_;
}

void esl::RoData::instance_delete ()
{
    if (instance_ != nullptr)
        delete instance_;
}

esl::RoData::RoData ()
{

}

esl::RoData::~RoData ()
{
    for (auto str : this->stored_)
        delete str;

}

int esl::RoData::exists (const std::string* data) const
{
    for (unsigned int i = 0; i < stored_.size(); ++i)
        if (*(stored_.at(i)) == *data)
            return i;

    return -1;
}

unsigned int esl::RoData::store (std::string* data,
                                 bool& exist)
{
    int pos = exists(data);

    exist = true;

    if (pos == -1)
    {
        exist = false;
        stored_.push_back (data);
        return stored_.size () - 1;
    }
    else
        return pos;
}

std::string* esl::RoData::get (unsigned int key) const
{
    if (key >= this->stored_.size ())
        return nullptr;

    return this->stored_.at (key);
}

const std::vector<std::string*>& esl::RoData::stored_get () const
{
    return this->stored_;
}

std::ostream& operator<< (std::ostream& os, const esl::RoData& rodata)
{
    int i = 0;

    os << "; RO DATA SECTION (" << rodata.stored_get().size() << ")"
       << std::endl;

    for (auto str : rodata.stored_get ())
    {
        os << i << "->" << *str << std::endl;
        ++i;
    }

    os << "; END RODATA SECTION" << std::endl;

    return os;
}
