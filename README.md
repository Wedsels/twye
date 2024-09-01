# INSTALLATION

- Put the twye.dll within the modengine directory.

- edit modengine config_eldenring.toml to include the relative location to the twye.dll

- - If you want the mod to automatically update itself
>     external_dlls = [
>          "Relative/Folder/Path/To/twye_updater.dll",

- - Else
>     external_dlls = [
>          "Relative/Folder/Path/To/twye.dll",




###### Uses https://github.com/Dasaav-dsv/libER & https://github.com/ividyon/EldenRingHKS