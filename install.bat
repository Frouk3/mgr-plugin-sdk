@echo off
echo BEFORE RUNNING THIS SCRIPT, MAKE SURE YOU MOVE THE PLUGIN SDK FOLDER IN FOLDER THAT YOU WON'T DELETE
pause

cls
echo Locating the game directory...
set "gameDir=%MGR_PLUGIN_SDK_GAME_PATH%"

for /f "delims=" %%i in ('powershell -command "(New-Object -ComObject Shell.Application).BrowseForFolder(0, 'Select your game directory', 0, 0).Self.Path"') do set "gameDir=%%i"

if not defined gameDir (
    echo No directory selected. Exiting installer.
    exit /b
)

if not exist "%gameDir%" (
    echo Invalid game directory. Exiting installer.
    exit /b
)
cls
echo What mod loader you use?(Frouk's Mod Loader(ML) or Rising Mod Manager(RMM))
set /p qWhichModLoader=""
set "outputDir=%gameDir%\scripts\\"
set usesModLoader=0
if /I "%qWhichModLoader%"=="frouk's mod loader" (
    set "outputDir=%gameDir%\mods\\"
    set usesModLoader=1
) 
if /I "%qWhichModLoader%"=="fml" (
    set "outputDir=%gameDir%\mods\\"
    set usesModLoader=1
)
if /I "%qWhichModLoader%"=="ml" (
    set "outputDir=%gameDir%\mods\\"
    set usesModLoader=1
)
if /I "%qWhichModLoader%"=="rising mod manager" (
    set "outputDir=%gameDir%\Mods\\"
    set usesModLoader=1
)
if /I "%qWhichModLoader%"=="rmm" (
    set "outputDir=%gameDir%\Mods\\"
    set usesModLoader=1
)
cls
setx MGR_PLUGIN_SDK "%CD%\\"
setx MGR_PLUGIN_SDK_GAME_PATH "%gameDir%\\"
setx MGR_PLUGIN_SDK_SCRIPT_OUTPUT_DIR "%outputDir%"
setx MGR_PLUGIN_SDK_USES_MODLOADER "%usesModLoader%"
cls
echo Installed.
pause >nul