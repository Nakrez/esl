#ifndef BYTECODE_ALL_HH
# define BYTECODE_ALL_HH

# include <bytecode/bytecode.hh>
# include <bytecode/pop.hh>

# include <bytecode/operation.hh>
# include <bytecode/bracket-op.hh>
# include <bytecode/new-object.hh>

# include <bytecode/store-var.hh>
# include <bytecode/store-attr.hh>
# include <bytecode/store-array.hh>

# include <bytecode/load-var.hh>
# include <bytecode/load-str.hh>
# include <bytecode/load-int.hh>
# include <bytecode/load-float.hh>
# include <bytecode/load-attr.hh>
# include <bytecode/load-module.hh>
# include <bytecode/open-module.hh>

# include <bytecode/call-module.hh>
# include <bytecode/call-method.hh>
# include <bytecode/call-function.hh>

# include <bytecode/start-class.hh>
# include <bytecode/end-class.hh>
# include <bytecode/register-attribut.hh>
# include <bytecode/register-function.hh>
# include <bytecode/inherit.hh>

# include <bytecode/jump.hh>
# include <bytecode/jump-true.hh>

#endif /* !BYTECODE_ALL_HH */
