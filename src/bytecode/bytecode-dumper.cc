# include <bytecode/bytecode-dumper.hh>

namespace bytecode
{
    BytecodeDumper::BytecodeDumper(std::ostream& ostr,
                                   const std::vector<std::string>& ro_data)
        : ostr_(ostr)
        , ro_data_(ro_data)
    {}

    BytecodeDumper::~BytecodeDumper()
    {}

    void BytecodeDumper::dump(const std::vector<Bytecode*>& code)
    {
        for (auto instr : code)
            instr->accept(*this);
    }

    void BytecodeDumper::operator()(const Pop& byte)
    {
        ostr_ << "POP" << std::endl;
    }

    void BytecodeDumper::operator()(const Operation& byte)
    {
        ostr_ << "OPERATION " << byte.op_get() << " ;" <<
              byte.string_op() << std::endl;;
    }

    void BytecodeDumper::operator()(const BracketOp& byte)
    {

    }

    void BytecodeDumper::operator()(const NewObject& byte)
    {

    }

    void BytecodeDumper::operator()(const StoreVar& byte)
    {
        ostr_ << "STORE_VAR " << byte.data_get()
              << " ;ro_data " << ro_data_[byte.data_get()] << std::endl;
    }

    void BytecodeDumper::operator()(const StoreAttr& byte)
    {

    }

    void BytecodeDumper::operator()(const StoreArray& byte)
    {

    }

    void BytecodeDumper::operator()(const StoreLocal& byte)
    {
        ostr_ << "STORE_LOCAL " << byte.addr_get() << std::endl;
    }


    void BytecodeDumper::operator()(const LoadVar& byte)
    {

    }

    void BytecodeDumper::operator()(const LoadLocal& byte)
    {

    }

    void BytecodeDumper::operator()(const LoadStr& byte)
    {
        ostr_ << "LOAD_STR " << byte.data_get()
              << " ;ro_data " << ro_data_[byte.data_get()] << std::endl;
    }

    void BytecodeDumper::operator()(const LoadInt& byte)
    {
        ostr_ << "LOAD_INT " << byte.value_get() << std::endl;
    }

    void BytecodeDumper::operator()(const LoadFloat& byte)
    {

    }

    void BytecodeDumper::operator()(const LoadAttr& byte)
    {

    }

    void BytecodeDumper::operator()(const LoadModule& byte)
    {

    }

    void BytecodeDumper::operator()(const OpenModule& byte)
    {

    }

    void BytecodeDumper::operator()(const CallModule& byte)
    {

    }

    void BytecodeDumper::operator()(const CallMethod& byte)
    {

    }

    void BytecodeDumper::operator()(const CallFunction& byte)
    {

    }

    void BytecodeDumper::operator()(const StartClass& byte)
    {

    }

    void BytecodeDumper::operator()(const EndClass& byte)
    {

    }

    void BytecodeDumper::operator()(const RegisterAttribut& byte)
    {

    }

    void BytecodeDumper::operator()(const RegisterFunction& byte)
    {

    }

    void BytecodeDumper::operator()(const Inherit& byte)
    {

    }

    void BytecodeDumper::operator()(const Jump& byte)
    {

    }

    void BytecodeDumper::operator()(const JumpTrue& byte)
    {

    }

    void BytecodeDumper::operator()(const JumpFalse& byte)
    {

    }


    void BytecodeDumper::operator()(const Return& byte)
    {

    }


    void BytecodeDumper::operator()(const Delim& byte)
    {

    }

} // namespace bytecode
