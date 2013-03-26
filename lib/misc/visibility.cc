#include <misc/visibility.hh>

namespace misc
{
    std::ostream& operator<< (std::ostream& ostr, const visibility& v)
    {
        switch (v)
        {
            case PUBLIC:
                ostr << "public";
                break;
            case PRIVATE:
                ostr << "private";
                break;
            case PROTECTED:
                ostr << "protected";
                break;
            default:
                ostr << "public";
        }

        return ostr;
    }
} // namespace misc
