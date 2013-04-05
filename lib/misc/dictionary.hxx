#ifndef DICTIONARY_HXX
# define DICTIONARY_HXX

# include <misc/dictionary.hh>

namespace misc
{
    template <class Key, class Data>
    Dictionary<Key, Data>::Dictionary()
        : map_(new std::vector<internal_list>(128, internal_list()))
        , content_number_(0)
    {
    }

    template <class Key, class Data>
    Dictionary<Key, Data>::~Dictionary()
    {
        for (unsigned i = 0; i < map_->size(); ++i)
        {
            for (auto elem : (*map_)[i])
                    elem.second->decr();
        }

        delete map_;
    }

    template <class Key, class Data>
    inline bool Dictionary<Key, Data>::insert(const Key& key, Data* data)
    {
        return insert(&map_, internal_data(key, data));
    }

    template <class Key, class Data>
    inline Data* Dictionary<Key, Data>::get(const Key& key)
    {
        unsigned hash = hash_(key) % map_->size();

        if (!(*map_)[hash].size())
            return nullptr;

        for (auto elem : (*map_)[hash])
        {
            if (elem.first == key)
                return elem.second;
        }

        return nullptr;
    }

    template <class Key, class Data>
    bool Dictionary<Key, Data>::insert(std::vector<internal_list>** map,
                                       const internal_data& data)
    {
        unsigned hash = hash_(data.first) % (*map)->size();

        if ((*map)->size() == content_number_)
            resize(map, (*map)->size() * 2);

        if ((**map)[hash].size())
        {
            // Check for existing
            for (auto elem : (**map)[hash])
            {
                if (elem.first == data.first)
                    return false; // no insertion element already present
            }
        }

        (**map)[hash].push_front(data);
        ++content_number_;

        return true;
    }

    template <class Key, class Data>
    void Dictionary<Key, Data>::resize(std::vector<internal_list>** old,
                                       unsigned new_size)
    {
        std::vector<internal_list>* new_table;

        new_table = new std::vector<internal_list>(new_size, internal_list());

        for (unsigned i = 0; i < (*old)->size(); ++i)
        {
            for (auto elem : (**old)[i])
                insert(&new_table, elem);
        }

        delete *old;
        *old = new_table;
    }
} // namespace misc

#endif /* !DICTIONARY_HXX */
