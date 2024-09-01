#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <sstream>

BOOL DllMain( HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved ) {
    if ( fdwReason == DLL_PROCESS_ATTACH ) {
        LPSTR dllFilepath = new CHAR[512];
        ::GetModuleFileNameA( hinstDll, dllFilepath, 512 );

        std::stringstream ss;
        ss << dllFilepath;
        std::string path = ss.str().erase( ss.str().find_last_of( '\\' ) );

        std::string command = "for /f \"tokens=* delims=\" %a in ('curl -s \"https://api.github.com/repos/Wedsels/twye/releases/latest\" ^| jq -r \".tag_name\"') do curl -L \"https://github.com/Wedsels/twye/releases/download/%a/twye.dll\" -o \"" + path + "/twye.dll\"";

        ::system( command.c_str() );
        LoadLibraryA( ( path + "/twye.dll" ).c_str() );
    }
    return TRUE;
}