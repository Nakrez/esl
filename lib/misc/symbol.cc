/**
 ** \file symbol/symbol.cc
 ** \brief Implementation of misc::symbol.
 */

#include <misc/symbol.hh>

namespace misc
{
  symbol::symbol (const std::string& s)
    : unique<std::string> (s)
  {}

  symbol::symbol (const char* s)
    : unique<std::string> (std::string (s))
  {}

  symbol::~symbol ()
  {}

  symbol::string_size_type symbol::string_map_size ()
  {
    return object_map_size ();
  }
} // namespace symbol
