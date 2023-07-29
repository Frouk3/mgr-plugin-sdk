@echo off
echo BEFORE RUNNING THIS SCRIPT, MAKE SURE YOU MOVE THE PLUGIN SDK FOLDER IN FOLDER THAT YOU WON'T DELETE
echo Press enter to continue...
pause >nul
if defined MGR_PLUGIN_SDK (
cls
echo Variable MGR_PLUGIN_SDK is already defined, do you want to continue?
echo It will overwrite the path
echo Press enter to continue...
pause >nul
)
cls
setx MGR_PLUGIN_SDK "%CD%\\"
pause >nul