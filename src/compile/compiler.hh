#ifndef COMPILER_HH
# define COMPILER_HH

# include <iostream>
# include <vector>

# include <ast/visitor.hh>
# include <misc/indent.hh>
# include <bytecode/bytecode.hh>

namespace compile
{
    class Compiler : public ast::Visitor
    {
        public:
            using ast::Visitor::operator();

            Compiler();
            virtual ~Compiler();

            const std::vector<bytecode::Bytecode*>& bytecode_get() const;

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
            std::vector<bytecode::Bytecode*> bytecode_;
    };
} // namespace compile

# include <compile/compiler.hxx>

#endif /* !COMPILER_HH*/
