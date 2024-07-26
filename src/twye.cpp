#include "Aho-Corasick.cpp"
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
        if ( std::filesystem::exists( ( common::modengine.erase( pos ) + L"\\modengine2_launcher.exe" ).c_str() ) )
            return true;

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
            common::write( L"found Modengine at ", common::modengine, L" in ", common::time(), L" microseconds" );
            
            common::hks::hksmain();
        } else common::write( L"not found a modengine directory, and will not apply parts of the mod!" );
        
        ::CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )&::core, NULL, 0, NULL );
    }
    return TRUE;
}