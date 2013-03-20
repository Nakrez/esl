#ifndef SCOPED_MAP_HH
# define SCOPED_MAP_HH

# include <list>
# include <map>

namespace misc
{
    template<class Key, class Data>
    class ScopedMap
    {
        public:
            ScopedMap();
            ~ScopedMap();

            void add(Key k, Data d);
            const Data& get(Key k) const;

            void scope_begin();
            void scope_end();

        private:
            std::list<std::map<Key, Data>> map_;
    };
} // namespace misc

# include <misc/scoped-map.hxx>

#endif /* !SCOPED_MAP_HH */
