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

unsigned int esl::RoData::store (std::string* data,
                                 bool& exist)
{
    DataIt it = std::find (stored_.begin (),
                           stored_.end (),
                           data);

    exist = it != stored_.end ();

    if (!exist)
    {
        stored_.push_back (data);
        return stored_.size ();
    }
    else
        return it - stored_.begin ();
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

    os << "; RO DATA SECTION" << std::endl;

    for (auto str : rodata.stored_get ())
    {
        std::cout << i << "->" << *str << std::endl;
        ++i;
    }

    os << "; END RODATA SECTION" << std::endl;

    return os;
}
