/**
 ** \file misc/symbol.hxx
 ** \brief Inline implementation of misc::symbol.
 */

#ifndef MISC_SYMBOL_HXX
# define MISC_SYMBOL_HXX

# include <misc/symbol.hh>

namespace misc
{

  //FIXME DONE

  inline const std::string& symbol::name_get () const
  {
    return object_get();
  }

  inline symbol& symbol::operator= (const symbol& rhs)
  {
    if (this != &rhs)
      obj_ = rhs.obj_;
    return *this;
  }

  inline bool symbol::operator== (const symbol& rhs) const
  {
    return obj_ == rhs.obj_;
  }

  inline bool symbol::operator!= (const symbol& rhs) const
  {
    return !operator== (rhs);
  }

  inline std::ostream& operator<< (std::ostream& ostr, const symbol& the)
  {
    return ostr << the.object_get();
  }

  //END OF FIXME
}

#endif // !MISC_SYMBOL_HXX
