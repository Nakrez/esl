#ifndef SCOPED_MAP_HXX
# define SCOPED_MAP_HXX

# include <misc/scoped-map.hh>

namespace misc
{
    template<class Key, class Data>
    ScopedMap<Key, Data>::ScopedMap()
    {
        scope_begin();
    }

    template<class Key, class Data>
    ScopedMap<Key, Data>::~ScopedMap()
    {}

    template<class Key, class Data>
    void ScopedMap<Key, Data>::add(Key k, Data d)
    {
        map_.back()[k] = d;
    }

    template<class Key, class Data>
    const Data& ScopedMap<Key, Data>::get(Key k) const
    {
        return map_.back().at(k);
    }

    template<class Key, class Data>
    void ScopedMap<Key, Data>::scope_begin()
    {
        map_.push_back(std::map<Key, Data>(map_.back()));
    }

    template<class Key, class Data>
    void ScopedMap<Key, Data>::scope_end()
    {
        map_.pop_back();
    }
} // namespace misc

#endif /* !SCOPED_MAP_HXX */
