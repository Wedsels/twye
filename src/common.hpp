#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <vector>
#include <set>

class common {
    public:
        static std::wstring modengine;
        static std::wstring moddir;
        
        static uint64_t time();

        static const bool exclusive = false;
        static void locateconsole();

        template <typename... T>
        static void write( T... content );

        static std::pair<std::string, size_t> replace( std::string string, std::vector<std::pair<std::string, std::string>> pattern, bool file, std::set<std::string> careful );
        
        static std::string fromw( std::wstring string );
    
    class params {
        public: static uint64_t parammain();
    };

    class hks {
        public:
            static void hksmain();
    };

    class aho {
        public:
            static std::pair<std::string, size_t> replacetext( std::string content, std::vector<std::pair<std::string, std::string>> pattern, std::set<std::string> careful );
    };

    class twye {
        public:
    };
};