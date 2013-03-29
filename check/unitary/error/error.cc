#include <iostream>
#include <sstream>
#include <assert.h>

#include <misc/error.hh>

int main()
{
    {
        misc::Error test;
        std::stringstream ref;

        /* ----
         * Test OTHER
         * ----- */

        test.exit_on_error();

        test << misc::Error::OTHER
             << "No error" << std::endl;

        ref << "No error" << std::endl;

        assert(test.error_code_get() == misc::Error::OTHER);
        assert(test.msg_get() == ref.str());
    }

    /* ----
     * Test SCAN
     * ----- */

    {
        misc::Error test;
        std::stringstream ref;

        test << misc::Error::SCAN
             << "Scan error" << std::endl;

        ref << "Scan error" << std::endl;

        try {
            test.exit_on_error();
        }
        catch (misc::Error& e)
        {
            assert(e.error_code_get() == misc::Error::SCAN);
            assert(e.msg_get() == ref.str());
        }
    }

    /* -----
     * Test PARSE
     * ----- */

    // Reset error
    {
        misc::Error test;
        std::stringstream ref;

        test << misc::Error::PARSE
             << "Parse error" << std::endl;

        ref << "Parse error" << std::endl;

        try {
            test.exit_on_error();
        }
        catch (misc::Error& e)
        {
            assert(e.error_code_get() == misc::Error::PARSE);
            assert(e.msg_get() == ref.str());
        }
    }

    /* -----
     * Test COMPILE
     * ----- */

    {
        misc::Error test;
        std::stringstream ref;

        test << misc::Error::COMPILE
             << "Compile error" << std::endl;

        ref << "Compile error" << std::endl;

        try {
            test.exit_on_error();
        }
        catch (misc::Error& e)
        {
            assert(e.error_code_get() == misc::Error::COMPILE);
            assert(e.msg_get() == ref.str());
        }
    }

    /* -----
     * Test EXEC
     * ----- */

    {
        misc::Error test;
        std::stringstream ref;

        test << misc::Error::EXEC
            << "Exec error" << std::endl;

        ref << "Exec error" << std::endl;

        try {
            test.exit_on_error();
        }
        catch (misc::Error& e)
        {
            assert(e.error_code_get() == misc::Error::EXEC);
            assert(e.msg_get() == ref.str());
        }
    }

    /* -----
     * Test OTHER
     * ----- */

    {
        misc::Error test;
        std::stringstream ref;

        test << misc::Error::OTHER
             << "Other error" << std::endl;

        ref << "Other error" << std::endl;

        try {
            test.exit_on_error();
        }
        catch (misc::Error& e)
        {
            assert(e.error_code_get() == misc::Error::OTHER);
            assert(e.msg_get() == ref.str());
        }
    }

    {
        misc::Error error;

        error << misc::Error::OTHER << misc::Error::PARSE;

        assert(error.error_code_get() == misc::Error::PARSE);
    }

    {
        misc::Error error;

        error << misc::Error::PARSE << misc::Error::OTHER;

        assert(error.error_code_get() == misc::Error::PARSE);
    }

    {
        misc::Error error;
        misc::Error other;
        std::stringstream ref;

        error << misc::Error::PARSE << "test" << std::endl;
        other = error;
        ref << "test" << std::endl;

        assert(error.error_code_get() == misc::Error::PARSE);
        assert(error.msg_get() == ref.str());
    }
}
