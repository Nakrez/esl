#ifndef COMPILER_HH
# define COMPILER_HH

# include <iostream>
# include <vector>
# include <climits>

# include <misc/symbol.hh>
# include <misc/scoped-map.hh>
# include <misc/error.hh>

# include <execute/executable.hh>

# include <ast/default-visitor.hh>

# include <bytecode/all.hh>

namespace compile
{
    class Compiler : public ast::DefaultConstVisitor
    {
        public:
            using ast::DefaultConstVisitor::operator();

            Compiler();
            virtual ~Compiler();

            execute::Executable& exec_get();
            const misc::Error& error_get() const;

        /* Visitor Implementation */
        public:
            virtual void operator()(const ast::AstList&);

            virtual void operator()(const ast::IntExp&);
            virtual void operator()(const ast::StringExp&);
            virtual void operator()(const ast::OpExp&);
            virtual void operator()(const ast::FunctionCallExp&);
            virtual void operator()(const ast::ReturnExp&);
            virtual void operator()(const ast::BreakExp&);
            virtual void operator()(const ast::ContinueExp&);
            virtual void operator()(const ast::NewExp&);
            virtual void operator()(const ast::AssignExp&);

            virtual void operator()(const ast::IfInstr&);
            virtual void operator()(const ast::ElseInstr&);
            virtual void operator()(const ast::WhileInstr&);
            virtual void operator()(const ast::InstrList&);
            virtual void operator()(const ast::ImportInstr&);

            virtual void operator()(const ast::VarId&);
            virtual void operator()(const ast::AttributVar&);
            virtual void operator()(const ast::MethodCallVar&);
            virtual void operator()(const ast::ModuleCallVar&);
            virtual void operator()(const ast::ModuleAttributVar&);
            virtual void operator()(const ast::ArrayVar&);

            virtual void operator()(const ast::FunctionDec&);
            virtual void operator()(const ast::VarDec&);
            virtual void operator()(const ast::MethodDec&);
            virtual void operator()(const ast::AttributDec&);
            virtual void operator()(const ast::ClassDec&);
            virtual void operator()(const ast::DecList&);

        protected:
            template<typename List> void compile_list(const List& l);

            int ro_data_get(const std::string& str);
            int addr_get(const std::string& str,
                         misc::ScopedMap<misc::symbol, int>& scope,
                         int& scope_addr,
                         bool error = false);

        protected:
            execute::Executable exec_;

            /// Allows compiler to treat variable as local variable
            bool local_;
            bool module_;

            // Scope
            misc::ScopedMap<misc::symbol, int> var_scope_;
            misc::ScopedMap<misc::symbol, int> glob_scope_;

            // Next addr to assign
            int var_addr_;
            int glob_addr_;

            // Rodata management
            std::map<std::string, int> ro_data_;
            int ro_data_counter_;

            misc::Error error_;

            bool assign_;
    };
} // namespace compile

# include <compile/compiler.hxx>

#endif /* !COMPILER_HH*/
