/**
 ** \file misc/unique.hxx
 ** \brief Inline implementation of misc::unique.
 */

#ifndef MISC_UNIQUE_HXX
# define MISC_UNIQUE_HXX

# include <misc/unique.hh>

namespace misc
{
  // FIXME DONE

  template<typename  T, class C>
  typename unique<T, C>::object_set_type&
  unique<T, C>::object_set_instance ()
  {
    static object_set_type myset = object_set_type();

    return myset;
  }

  template<typename  T, class C>
  inline unique<T, C>::~unique()
  {
  }

  template<typename  T, class C>
  inline unique<T, C>::unique (const data_type& s)
    : obj_ (&(*(object_set_instance().insert(s).first)))
  {

  }

  template <typename  T, class C>
  inline const typename unique<T, C>::data_type&
  unique<T, C>::object_get () const
  {
    return *obj_;
  }

  template <typename  T, class C>
  inline unique<T, C>::operator const typename unique<T, C>::data_type&
  () const
  {
    return *obj_;
  }

  template <typename  T, class C>
  inline typename unique<T, C>::object_size_type
  unique<T, C>::object_map_size ()
  {
    object_set_type& myset = object_set_instance();

    return myset.size();
  }

  //END OF FIXME

  template <typename  T, class C>
  inline typename unique<T, C>::value_type&
  unique<T, C>::operator= (const value_type& rhs)
  {
    if (this != &rhs)
      obj_ = rhs.obj_;
    return *this;
  }

  template <typename T, class C>
  inline bool
  unique<T, C>::operator== (const value_type& rhs) const
  {
    return obj_ == rhs.obj_;
  }

  template <typename T, class C>
  inline bool
  unique<T, C>::operator!= (const value_type& rhs) const
  {
    return !operator== (rhs);
  }

  template <typename T, class C>
  inline bool
  unique<T, C>::operator< (const value_type& rhs) const
  {
    C cmp;
    return cmp (*obj_, *rhs.obj_);
  }

  template <typename T, class C>
  inline std::ostream&
  operator<< (std::ostream& ostr, const unique<T, C>& the)
  {
    return ostr << the.object_get ();
  }

}

#endif // !MISC_UNIQUE_HXX
