#ifndef COMPILER_HH
# define COMPILER_HH

# include <iostream>
# include <vector>
# include <climits>

# include <misc/symbol.hh>
# include <misc/scoped-map.hh>

# include <execute/executable.hh>

# include <ast/visitor.hh>

# include <bytecode/all.hh>

namespace compile
{
    class Compiler : public ast::Visitor
    {
        public:
            using ast::Visitor::operator();

            Compiler();
            virtual ~Compiler();

            const execute::Executable& exec_get() const;

        /* Visitor Implementation */
        public:
            virtual void operator()(ast::AstList&);

            virtual void operator()(ast::IntExp&);
            virtual void operator()(ast::StringExp&);
            virtual void operator()(ast::OpExp&);
            virtual void operator()(ast::FunctionCallExp&);
            virtual void operator()(ast::ReturnExp&);
            virtual void operator()(ast::BreakExp&);
            virtual void operator()(ast::ContinueExp&);
            virtual void operator()(ast::NewExp&);
            virtual void operator()(ast::AssignExp&);

            virtual void operator()(ast::IfInstr&);
            virtual void operator()(ast::ElseInstr&);
            virtual void operator()(ast::WhileInstr&);
            virtual void operator()(ast::InstrList&);
            virtual void operator()(ast::ImportInstr&);

            virtual void operator()(ast::VarId&);
            virtual void operator()(ast::AttributVar&);
            virtual void operator()(ast::MethodCallVar&);
            virtual void operator()(ast::ModuleCallVar&);
            virtual void operator()(ast::ModuleAttributVar&);
            virtual void operator()(ast::ArrayVar&);

            virtual void operator()(ast::FunctionDec&);
            virtual void operator()(ast::VarDec&);
            virtual void operator()(ast::MethodDec&);
            virtual void operator()(ast::AttributDec&);
            virtual void operator()(ast::ClassDec&);
            virtual void operator()(ast::DecList&);

        protected:
            int ro_data_get(const std::string& str);

        protected:
            execute::Executable exec_;

            /// Allows compiler to treat variable as local variable
            bool local_;

            misc::ScopedMap<misc::symbol, int> var_scope_;
            int local_addr_;

            // Rodata management
            std::map<std::string, int> ro_data_;
            int ro_data_counter_;

            bool error_;
    };
} // namespace compile

# include <compile/compiler.hxx>

#endif /* !COMPILER_HH*/
