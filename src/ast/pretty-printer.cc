#include <ast/pretty-printer.hh>
#include <ast/all.hh>

namespace ast
{
    PrettyPrinter::PrettyPrinter(std::ostream& stream)
        : Visitor()
        , stream_(stream)
    {}

    void PrettyPrinter::operator()(IntExp& exp)
    {
        stream_ << exp.value_get();
    }

    void PrettyPrinter::operator()(InstrList& list)
    {
        for (auto elem : list.list_get())
        {
            elem->accept(*this);
            stream_ << std::endl;
        }
    }
} // namespace ast
