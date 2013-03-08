#ifndef BYTECODE_FWD_HH
# define BYTECODE_FWD_HH

namespace bytecode
{
    class Bytecode;

    class Pop;

    class Operation;
    class BracketOp;
    class NewObject;

    class StoreVar;
    class StoreAttr;
    class StoreArray;

    class LoadVar;
    class LoadStr;
    class LoadInt;
    class LoadFloat;
    class LoadAttr;
    class LoadModule;

    class OpenModule;

    class CallModule;
    class CallMethod;
    class CallFunction;

    class StartClass;
    class EndClass;
    class RegisterAttribut;
} // namespace bytecode

#endif /* !BYTECODE_FWD_HH */