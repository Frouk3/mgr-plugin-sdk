# mgr-plugin-sdk
Plugin SDK for Metal Gear Rising: Revengeance.

# Compiling
Right now this is usable as a library that helps you inject and edit the game's memory. <br />
Language: C++ <br />
File type: Dynamic Link Library <br />
File extension: .asi<br />

## Installing
In order to install, download the code. <br />
Code -> [Download ZIP](https://github.com/Frouk3/mgr-plugin-sdk/archive/refs/heads/main.zip) <br />
IDEs:
* [Visual Studio 2022](https://visualstudio.microsoft.com/vs/)
* [Visual Studio Code](https://code.visualstudio.com/)

When using Visual Studio Code you can't compile your project into .asi mod. (unless you use an external compiler) <br/>

Firstly, after downloading the ZIP you need to unpack it in the folder where the SDK will be located, make sure that this folder will not move. (create new folder if necessary)<br/>
After unpacking, make sure to run "install.bat".<br/>
And after that, you should be successful to run the framework.<br/>

## Usage
The SDK works on an event basis. <br/>
To begin working, create a class with a constructor to be your plugin:<br/>
```cpp
class MyPlugin
{
public:
    MyPlugin()
    {
    }
} plugin;
```
The constructor will be your main() function.

To hook into the game's events, you can subscribe to them:<br/>
```cpp
Events::OnTickEvent += MyTickEvent;
Events::OnGameStartupEvent += MyLoadEvent;
```

## Making a mod

There's example how to make a basic mod for the game, but, the code itself and SDK will change with some time.<br/>
Download [MGR Plugin SDK Framework](https://github.com/user-attachments/files/18560011/MGRPluginFramework.zip)<br />
Use it to make mods with the SDK.

You can view some sample projects in the [examples/](https://github.com/Frouk3/mgr-plugin-sdk/tree/main/examples) folder.