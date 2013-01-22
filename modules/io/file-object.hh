#ifndef FILE_OBJECT_HH
# define FILE_OBJECT_HH

# include <fstream>
# include <string>

# include "../../lib/type/object.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/content.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class FileObject : public Object
    {
        public:
            FileObject ();
            FileObject (const std::string& filename);
            FileObject (const std::string& filename, const std::string& mode);
            ~FileObject ();

            void open (const std::string& filename);
            void open (const std::string& filename, const std::string& mode);

            void close ();
            int is_open () const;

        private:
            std::fstream data_;
    };
}

#endif /* !FILE_OBJECT_HH */
