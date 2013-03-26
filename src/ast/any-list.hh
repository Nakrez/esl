#ifndef ANY_LIST_HH
# define ANY_LIST_HH

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
            std::list<T*>& list_get();

            void push_back(T*);

            virtual void accept(Visitor&);
            virtual void accept(ConstVisitor&) const;

        protected:
            std::list<T*> list_;
    };
} // namespace ast

# include <ast/any-list.hxx>

#endif /* !ANY_LIST_HH */
