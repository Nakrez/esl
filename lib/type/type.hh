#ifndef TYPE_HH
# define TYPE_HH

# include <string>
# include <map>

# include "../exception.hh"
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
            virtual ~Type ();

            virtual MemoryObject<Content>* print (const Params&) = 0;
            virtual std::string type_name_get() const = 0;

            virtual MemoryObject<Content>* plus_op (const Params&);
            virtual MemoryObject<Content>* minus_op (const Params&);
            virtual MemoryObject<Content>* mul_op (const Params&);
            virtual MemoryObject<Content>* div_op (const Params&);
            virtual MemoryObject<Content>* mod_op (const Params&);

            void register_method (const std::string&, Method*, Visibility);
            MemoryObject<Content>* call_method (const std::string&,
                                                const esl::Params&);
        protected:
            std::map<std::string, std::pair<Method*, Visibility>> method_;
            std::map<std::string,
                     std::pair<MemoryObject<esl::Content>*,
                               Visibility>> attribut_;
    };
}

#endif /* !TYPE_HH */
