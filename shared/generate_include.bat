@echo off
setlocal

set "output_file=%MGR_PLUGIN_SDK%\shared\include_all_headers.h"

> "%output_file%" echo #pragma once
echo Initializing %output_file%...

echo Processing shared directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\shared\*.h" /b /a:-d') do (
    if /i not "%%~nxF"=="include_all_headers.h" (
        echo #include ^<%%~nxF^>
    )
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

echo Processing SafeHook directory...
for /f "tokens=*" %%F in ('dir "%MGR_PLUGIN_SDK%\SafeHook\*.h" /b /a:-d') do (
    echo #include ^<%%~nxF^>
) >> "%output_file%"

echo All specified directories processed.
echo The header file "%output_file%" has been created/updated.

endlocal