#include "common.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>

std::wstring common::modengine;

HANDLE stdhandle;
uint64_t tracktime;

uint64_t common::time() {
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::system_clock::now().time_since_epoch() ).count();
    auto diff = ms - tracktime;
    tracktime = ms;

    return diff;
}

void common::locateconsole() {
    ::AllocConsole();

    HWND consoleWindow = ::GetConsoleWindow();

    LONG_PTR style = ::GetWindowLongPtrW(consoleWindow, GWL_STYLE );
    style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );
    ::SetWindowLongPtrW( consoleWindow, GWL_STYLE, style );

    short h = 800;
    short w = 600;
    ::SetWindowPos(
        consoleWindow,
        HWND_TOPMOST,
        ( ::GetSystemMetrics( SM_CXSCREEN ) - h ) / 2,
        ( ::GetSystemMetrics( SM_CYSCREEN ) - w ) / 2,
        h,
        w,
        NULL
    );
    
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

template <typename... T>
void common::write( T... content ) {
    std::wstringstream wss;
    wss << L"twye has ";
    ( wss << ... << content ) << "\n\n";
    
    ::WriteConsoleW( stdhandle, wss.str().c_str(), (DWORD)wss.str().size(), NULL, NULL );
}

std::pair<std::string, size_t> common::replace( std::string string, std::vector<std::pair<std::string, std::string>> pattern, bool file ) {
    std::string content = string;

    if ( file ) {
        std::ifstream inputFile( string );

        std::stringstream ss;
        ss << inputFile.rdbuf();
        content = ss.str();
        
        inputFile.close();
    }

    auto result = common::aho::replacetext( content, pattern );

    if ( file ) {
        std::ofstream outputFile( string, std::ios::trunc );
        outputFile << result.first;
        outputFile.close();
    }

    return { content, result.second };
}

std::string common::fromw( std::wstring string ) {
    std::string result( string.length(), 0 );
    std::transform( string.begin(), string.end(), result.begin(), [] ( wchar_t c ) { return (char)c; } );
    return result;
}