#include <parser/command.hh>

namespace parser
{
    void parse_file()
    {
        parse_input_file(main_filename).exit_on_error();
    }
} // namespace parser
