#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <set>

class common {
    public:
        static inline HANDLE stdhandle;

        static inline uint64_t tracktime;

        static inline std::wstring modengine;
        static inline std::wstring homedir;
        static inline std::wstring moddir;
        
        static inline uint64_t time() {
            auto ms = std::chrono::duration_cast< std::chrono::microseconds >( std::chrono::system_clock::now().time_since_epoch() ).count();
            auto diff = ms - tracktime;
            tracktime = ms;

            return diff;
        }

        static inline const bool exclusive = true;
        static inline void locateconsole() {
            ::AllocConsole();

            if ( !exclusive ) {
                FILE* out;
                freopen_s( &out, "CON", "w", stdout );
                return;
            }
            
            ::SetConsoleActiveScreenBuffer (
                stdhandle = ::CreateConsoleScreenBuffer(
                    GENERIC_READ | GENERIC_WRITE,
                    FILE_SHARE_READ | FILE_SHARE_WRITE,
                    NULL,
                    CONSOLE_TEXTMODE_BUFFER,
                    NULL
                )
            );
        }

        static inline const bool debug = true;
        static inline std::wstring nodebug;

        template < typename... T >
        static inline void write( T... content ) {
            std::wstringstream wss;
            wss << L"twye has ";
            ( wss << ... << content ) << "\n\n";

            if ( !debug )
                nodebug += wss.str();
            else if ( !exclusive )
                ::printf( fromw( wss.str() ).c_str() );
            else
                ::WriteConsoleW( stdhandle, wss.str().c_str(), ( DWORD )wss.str().size(), NULL, NULL );
        }

        static inline std::pair< std::string, size_t > replace( std::string string, std::vector< std::pair< std::string, std::string > > pattern, bool file, std::set< std::string > careful = {} ) {
            std::string content = string;

            if ( file ) {
                std::ifstream inputFile( string );

                std::stringstream ss;
                ss << inputFile.rdbuf();
                content = ss.str();
                
                inputFile.close();
            }

            auto result = common::aho::replacetext( content, pattern, careful );

            if ( file ) {
                std::ofstream outputFile( string, std::ios::trunc );
                outputFile << result.first;
                outputFile.close();
            }

            return { content, result.second };
        }

        static inline std::string fromw( std::wstring string ) {
            std::string result( string.length(), 0 );
            std::transform( string.begin(), string.end(), result.begin(), [] ( wchar_t c ) { return ( char )c; } );
            return result;
        }
    
    class params {
        public: static uint64_t parammain();
    };

    class hks {
        public:
            static void hksmain();
    };

    class aho {
        public:
            static std::pair< std::string, size_t > replacetext( std::string content, std::vector< std::pair< std::string, std::string > > pattern, std::set< std::string > careful );
    };

    class twye {
        public:
    };
};