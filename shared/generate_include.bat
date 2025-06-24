@echo off
setlocal

set "output_file=include_all_headers.h"

> "%output_file%" echo.
echo Initializing %output_file%...

echo Processing shared directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\shared\*.h" /b /a:-d') do (
    echo #include ^<%%~nxF^>
) >> "%output_file%"

echo Processing game/Criware directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\game\Criware\*.h" /b /a:-d') do (
    echo #include ^<%%~nxF^>
) >> "%output_file%"

echo Processing game/Havok directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\game\Havok\*.h" /b /a:-d') do (
    echo #include ^<%%~nxF^>
) >> "%output_file%"

echo Processing game directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\game\*.h" /b /a:-d') do (
    echo #include ^<%%~nxF^>
) >> "%output_file%"

echo All specified directories processed.
echo The header file "%output_file%" has been created/updated.

endlocal