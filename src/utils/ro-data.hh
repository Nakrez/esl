/// @file ro-data.hh
/// @brief Implementation of read only data used in ESL
///        (string/integer constant, identifier)
/// @author Baptiste Covolato <b.covolato@gmail.com>
/// @date 24 Dec 2012

#ifndef RO_DATA_HH
# define RO_DATA_HH

# include <string>
# include <vector>
# include <algorithm>
# include <iostream>

namespace esl
{
    class RoData
    {
        using DataIt = std::vector<std::string*>::iterator;

        public:
            static RoData* instance_get ();
            static void instance_delete ();

            unsigned int store (std::string* data, bool& exist);
            std::string* get (unsigned int key) const;

            const std::vector<std::string*>& stored_get () const;

        private:
            RoData ();
            ~RoData ();

            std::vector<std::string*> stored_;

            static RoData* instance_;
    };
}

std::ostream& operator<< (std::ostream& os, const esl::RoData& rodata);

#endif /* !RO_DATA_HH */
