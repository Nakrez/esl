#ifndef LIBPARSER_HH
# define LIBPARSER_HH

# include <string>

# include <misc/error.hh>

# include <parser/driver.hh>

# include <ast/libast.hh>

namespace parser
{
    misc::Error parse_input_file(const std::string& name);
} // namespace parser

#endif /* !LIBPARSER_HH */
