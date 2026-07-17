@echo off
setlocal EnableExtensions

set "ROOT=%~dp0"
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT:~0,-1%"

set "MGR_PLUGIN_SDK=%ROOT%"
set "MGR_PLUGIN_SDK_GAME_PATH=%ROOT%"

call "%ROOT%\shared\generate_include.bat"
if errorlevel 1 exit /b %ERRORLEVEL%

if defined TEMP (
    set "BUILD_DIR=%TEMP%\mgr-plugin-sdk-ci-build"
) else (
    set "BUILD_DIR=%ROOT%\.ci-build"
)
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set "SMOKE_CPP=%BUILD_DIR%\include_smoke_test.cpp"
set "SMOKE_OBJ=%BUILD_DIR%\include_smoke_test.obj"

> "%SMOKE_CPP%" (
    echo #include "../shared/include_all_headers.h"
    echo int main^(^) { return 0; }
)

where cl >nul 2>nul
if errorlevel 1 (
    set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
    if not exist "%VSWHERE%" (
        echo cl.exe was not found and vswhere.exe is unavailable.
        exit /b 1
    )

    set "VCVARSALL="
    for /f "usebackq delims=" %%I in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -find VC\Auxiliary\Build\vcvarsall.bat`) do (
        set "VCVARSALL=%%I"
    )

    if not defined VCVARSALL (
        echo Unable to locate a Visual Studio C++ toolchain.
        exit /b 1
    )

    call "%VCVARSALL%" x86
    if errorlevel 1 exit /b %ERRORLEVEL%
)

cl /nologo /std:c++20 /permissive- /EHsc /W3 /MT /c ^
    /Fo"%SMOKE_OBJ%" ^
    /I"%ROOT%\shared" ^
    /I"%ROOT%\shared\dxsdk" ^
    /I"%ROOT%\shared\injector" ^
    /I"%ROOT%\shared\injector\gvm" ^
    /I"%ROOT%\game" ^
    /I"%ROOT%\game\Criware" ^
    /I"%ROOT%\game\Havok" ^
    /I"%ROOT%\SafeHook" ^
    /I"%ROOT%\SafeHook\hde" ^
    /DWIN32 /D_WINDOWS /D_USRDLL /DINJECTOR_GVM_DUMMY ^
    "%SMOKE_CPP%"
if errorlevel 1 exit /b %ERRORLEVEL%

echo Test build succeeded.

endlocal
exit /b 0