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
setx MGR_PLUGIN_SDK "%CD%\\"
setx MGR_PLUGIN_SDK_GAME_PATH "%gameDir%\\"
cls
echo Installed.
pause >nul
