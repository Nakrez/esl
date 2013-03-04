/// @file src/utils/bytecode.hh
/// @brief Def of all instructions supported + class Bytecode which contains
//         a bytecode instruction (with param)
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 29/11/2012

#ifndef BYTECODE_H_
# define BYTECODE_H_

# include <parser/location.hh>

# include <bytecode/visitor.hh>

namespace bytecode
{
    class Bytecode
    {
        public:
            Bytecode (const yy::location& location);
            ~Bytecode ();

            const yy::location& location_get() const;

            virtual void accept(const Visitor& visitor) const = 0;

        protected:
            yy::location location_;
    };
} // namespace bytecode

# include <bytecode/bytecode.hxx>

#endif /* BYTECODE_H_ */
