#include <iostream>
#include <sstream>
#include <assert.h>

#include <misc/dictionary.hh>

struct Test
{
    Test(const std::string& str) : str_(str) {}
    ~Test() {}

    void decr() { delete this; }
    std::string str_;
};

int main()
{
    misc::Dictionary<std::string, Test> dic;

    for (unsigned i = 0; i < 1500; ++i)
    {
        std::string test;

        test += std::to_string(i);

        assert(dic.insert(test, new Test(test)));
    }

    for (unsigned i = 0; i < 1500; ++i)
    {
        std::string test;

        test += std::to_string(i);

        Test* temp = dic.get(test);

        assert(temp != nullptr);
        assert(temp->str_ == test);
    }
}
