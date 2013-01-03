#ifndef TYPE_HH
# define TYPE_HH

# include <string>
# include <map>

# include "../content.hh"
# include "../gc/memory-object.hh"
# include "../delegate.hh"

enum Visibility
{
    PUBLIC,
    PROTECTED,
    PRIVATE
};

namespace esl
{
    using Method = MemoryObject<esl::DelegateBase>;

    class Type : public Content
    {
        public:
            Type ();
            ~Type ();

            virtual MemoryObject<Content>* print (const Params&) = 0;
            virtual std::string type_name_get() const = 0;

            void register_method (const std::string&, Method*, Visibility);
        protected:
            std::map<std::string, std::pair<Method*, Visibility>> method_;
            std::map<std::string,
                     std::pair<MemoryObject<esl::Content>*,
                               Visibility>> attribut_;
    };
}

#endif /* !TYPE_HH */
