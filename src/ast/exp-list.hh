/// date 17 Feb 2013
#ifndef EXP_LIST_HH
# define EXP_LIST_HH

# include <list>

# include <ast/exp.hh>

namespace ast
{
    class ExpList : public Ast
    {
        public:
            ExpList(const yy::location& location);
            ExpList(const yy::location& location,
                    std::list<Exp*>* list);
            virtual ~ExpList();

            const std::list<Exp*>& list_get() const;

        protected:
            std::list<Exp*>* list_;
    };
} // namespace ast

# include <ast/exp-list.hxx>

#endif /* !EXP_LIST_HH */
