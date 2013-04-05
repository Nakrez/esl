/// @date 05/04/2013

#ifndef DICTIONARY_HH
# define DICTIONARY_HH

# include <string>
# include <vector>
# include <list>

namespace misc
{
    template <class Key, class Data>
    class Dictionary
    {
        typedef std::pair<const Key, Data*> internal_data;
        typedef std::list<internal_data> internal_list;
        public:
            Dictionary();
            ~Dictionary();

            bool insert(const Key& key, Data* data);
            Data* get(const Key& key);

        private:
            void resize(std::vector<internal_list>** old,
                        unsigned new_size);
            bool insert(std::vector<internal_list>** map,
                        const internal_data& data);

        private:
            std::vector<internal_list>* map_;
            unsigned content_number_;
            std::hash<Key> hash_;

    };
} // namespace misc

# include <iostream>
# include <misc/dictionary.hxx>

#endif /* !DICTIONARY_HH */
