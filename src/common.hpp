#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <vector>

class common {
    public:
        static std::wstring modengine;
        
        static uint64_t time();

        static void locateconsole();

        template <typename... T>
        static void write( T... content );

        static std::pair<std::string, size_t> replace( std::string string, std::vector<std::pair<std::string, std::string>> pattern, bool file );
        
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
            static std::pair<std::string, size_t> replacetext( std::string content, std::vector<std::pair<std::string, std::string>> pattern );
    };

    class twye {
        public:
    };
};