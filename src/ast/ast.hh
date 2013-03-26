#ifndef AST_HH
# define AST_HH

# include <string>
# include <list>
# include <iostream>
# include <fstream>

# include <parser/location.hh>

# include <ast/fwd.hh>

namespace ast
{
    class Ast
    {
        public:
            Ast(const yy::location& location);
            virtual ~Ast();

            const yy::location& location_get() const;
            yy::location& location_get();

            void location_set(const yy::location& location);

            virtual void accept(Visitor& visitor) = 0;
            virtual void accept(ConstVisitor& visitor) const = 0;

        protected:
            yy::location location_;
    };
}

# include <ast/ast.hxx>

#endif /* AST_HH */
