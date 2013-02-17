/// date 17 Feb 2013
#ifndef VAR_DEC_LIST_HH
# define VAR_DEC_LIST_HH

# include <list>

# include <ast/var-dec.hh>

namespace ast
{
    class VarDecList : public Ast
    {
        public:
            VarDecList(const yy::location& location);
            VarDecList(const yy::location& location,
                       std::list<VarDec*>* list);
            ~VarDecList();

            const std::list<VarDec*>& list_get() const;

            virtual void accept(Visitor& visitor);

        protected:
            std::list<VarDec*>* list_;
    };
} // namespace ast

# include <ast/var-dec-list.hxx>

#endif /* !VAR_DEC_LIST_HH */
