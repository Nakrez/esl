#ifndef ANY_LIST_HH
# define ANY_LIST_HH

# include <ast/visitor.hh>
# include <ast/ast.hh>

namespace ast
{
    template<class T>
    class AnyList : public Ast
    {
        public:
            AnyList(const yy::location& location);
            AnyList(const yy::location& location, T*);
            virtual ~AnyList();

            const std::list<T*>& list_get() const;
            void push_back(T*);
            void accept(Visitor&);

        protected:
            std::list<T*> list_;
    };
} // namespace ast

# include <ast/any-list.hxx>

#endif /* !ANY_LIST_HH */
