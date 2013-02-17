#ifndef AST_HH
# define AST_HH

# include <string>
# include <list>
# include <iostream>
# include <fstream>

# include <utils/ro-data.hh>
# include <utils/token.hh>

# include <parser/location.hh>

namespace ast
{
    class Ast
    {
        public:
            Ast(const yy::location& location);
            virtual ~Ast();

            const yy::location& location_get() const;
            void location_set(const yy::location& location);

        protected:
            yy::location location_;
    };
}

# include <ast/ast.hxx>

#endif /* AST_HH */
