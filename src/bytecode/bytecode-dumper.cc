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
        unsigned counter = 0;

        for (auto instr : code)
        {
            ostr_ << counter++ << " ";
            instr->accept(*this);
        }
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
        ostr_ << "BRACKET_OP" << std::endl;
    }

    void BytecodeDumper::operator()(const NewObject& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const StoreVar& byte)
    {
        ostr_ << "STORE_VAR " << byte.data_get() << std::endl;
    }

    void BytecodeDumper::operator()(const StoreAttr& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const StoreArray& byte)
    {
        ostr_ << "STORE_ARRAY" << std::endl;
    }

    void BytecodeDumper::operator()(const StoreLocal& byte)
    {
        ostr_ << "STORE_LOCAL " << byte.addr_get() << std::endl;
    }


    void BytecodeDumper::operator()(const LoadVar& byte)
    {
        ostr_ << "LOAD_VAR " << byte.addr_get() << std::endl;
    }

    void BytecodeDumper::operator()(const LoadLocal& byte)
    {
        ostr_ << "LOAD_LOCAL " << byte.addr_get() << std::endl;
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
        // FIXME
    }

    void BytecodeDumper::operator()(const LoadModule& byte)
    {
        ostr_ << "LOAD_MODULE " << byte.data_get()
              << " ;ro_data " << ro_data_[byte.data_get()] << std::endl;
    }

    void BytecodeDumper::operator()(const OpenModule& byte)
    {
        ostr_ << "OPEN_MODULE " << byte.data_get()
              << " ;ro_data " << ro_data_[byte.data_get()] << std::endl;
    }

    void BytecodeDumper::operator()(const CallModule& byte)
    {
        ostr_ << "LOAD_MODULE " << byte.data_get()
              << " ;ro_data " << ro_data_[byte.data_get()] << std::endl;
    }

    void BytecodeDumper::operator()(const CallMethod& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const CallFunction& byte)
    {
        ostr_ << "CALL_FUNCTION " << byte.addr_get() << std::endl;
    }

    void BytecodeDumper::operator()(const StartClass& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const EndClass& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const RegisterAttribut& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const RegisterFunction& byte)
    {
        ostr_ << "REGISTER_FUNCTION " << byte.data_get() << std::endl;
    }

    void BytecodeDumper::operator()(const Inherit& byte)
    {
        // FIXME
    }

    void BytecodeDumper::operator()(const Jump& byte)
    {
        ostr_ << "JUMP " << byte.offset_get() << std::endl;
    }

    void BytecodeDumper::operator()(const JumpTrue& byte)
    {
        ostr_ << "JUMP_TRUE " << byte.offset_get() << std::endl;
    }

    void BytecodeDumper::operator()(const JumpFalse& byte)
    {
        ostr_ << "JUMP_FALSE " << byte.offset_get() << std::endl;
    }

    void BytecodeDumper::operator()(const Return& byte)
    {
        ostr_ << "RETURN" << std::endl;
    }

    void BytecodeDumper::operator()(const Delim& byte)
    {
        ostr_ << "DELIM" << std::endl;
    }
} // namespace bytecode
