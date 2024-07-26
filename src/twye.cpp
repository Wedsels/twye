#include "ahocorasick.cpp"
#include "common.cpp"
#include "params.cpp"
#include "hks.cpp"

#include <coresystem/cs_param.hpp>
#include <filesystem>

bool modpath( HINSTANCE hinstDll ) {
    common::time();
    
    LPWSTR dllFilepath = new WCHAR[512];
    ::GetModuleFileNameW( hinstDll, dllFilepath, 512 );

    std::wstringstream wss;
    wss << dllFilepath;
    common::modengine = wss.str();

    size_t pos = 0;
    while ( ( pos = common::modengine.find_last_of( '\\' ) ) != std::wstring::npos )
        if ( std::filesystem::exists( ( common::modengine.erase( pos ) + L"\\config_eldenring.toml" ).c_str() ) ) {
            common::modengine += L"\\";

            std::wifstream inputFile( common::modengine + L"config_eldenring.toml" );

            std::wstringstream wss;
            wss << inputFile.rdbuf();
            std::wstring content = wss.str();
            
            inputFile.close();

            size_t offset = content.find( L"\nmods = [" );
            if ( offset == std::string::npos ) common::moddir = common::modengine + L"mod\\";
            offset = content.find( L"path = \"", offset );
            if ( offset == std::string::npos ) common::moddir = common::modengine + L"mod\\";
            offset += 8;

            std::wstring path = content.substr( offset, content.find( L"\"", offset ) - offset  );
            
            if ( path.find( L":\\" ) == std::string::npos ) common::moddir = common::modengine + path;
            else common::moddir = path;

            common::moddir += L"\\";
            
            return true;
        }

    return false;
}

void core() {
    from::CS::SoloParamRepository::wait_for_params( -1 );
    
    common::write( L"modified game parameters", L" in ", common::params::parammain(), L" microseconds" );
    
    ::Sleep( 2500 );

    HWND consoleWindow = ::GetConsoleWindow();
    ::FreeConsole();
    ::PostMessageW(consoleWindow, WM_CLOSE, 0, 0);
}

BOOL DllMain( HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved ) {
    if ( fdwReason == DLL_PROCESS_ATTACH ) {
        common::locateconsole();

        if ( 0 == 0 ) common::write( L"its version up-to-date" );
        else common::write( L"its version out-of-date" );

        if ( ::modpath( hinstDll ) ) {
            common::write( L"found Modengine at ", common::modengine, L"\nAnd the mod directory at ", common::moddir, L"\nIn ", common::time(), L" microseconds" );
            
            common::hks::hksmain();
        } else common::write( L"not found a modengine directory, and will not apply parts of the mod!" );
        
        ::CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )&::core, NULL, 0, NULL );
    }
    return TRUE;
}