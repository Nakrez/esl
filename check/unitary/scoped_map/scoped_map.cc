#include <string>
#include <assert.h>
#include <misc/scoped-map.hh>

int main()
{
    misc::ScopedMap<std::string, int> map;

    map.add("foo", 2);
    map.add("bar", 5);

    assert(map.get("foo") == 2);
    assert(map.get("bar") == 5);

    map.scope_begin();
    {
        map.add("foo", 20);
        map.add("foobar", 29);

        assert(map.get("foo") == 20);
        assert(map.get("foobar") == 29);
        assert(map.get("bar") == 5);
    }
    map.scope_end();

    assert(map.get("foo") == 2);
    assert(map.get("bar") == 5);

    return 0;
}
