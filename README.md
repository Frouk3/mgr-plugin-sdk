# mgr-plugin-sdk
Plugin sdk for Metal Gear Rising Revengeance

# Compiling
For now, its just empty for using it as SDK, download it, and move it to the project you will make <br />
Language: C++ <br />
File extension: .asi file <br />
## Installing
In order to install, download code <br />
Code->Download ZIP <br />
IDEs:
* Visual Studio 2022
* Visual Studio Code

When using Visual Studio Code you can't compile your project into .asi mod
## Contribution
Feel free to contribute, but make sure you will give the exact information what will you change or add <br />
About IDA database, i will put the link [here](https://drive.google.com/file/d/1TTIz8vpW4CCyaA2Bc1rhdnXtnlnGmLoy/view?usp=drivesdk)

Move the folders named "game" and "shared" into the folder of your project, then go to the Project Settings->Directories->Include Directories and include folders named "game" and "shared" and include required headers with ```#include <headername.h>``` cpp file nor source file will be included if you done everything correctly

## Making a mod
There's example how to make a basic mod for the game, but, the code itself and sdk will change with some time

## Updating SDK for existing project
To update the project, you need to download this SDK from GitHub as source code
Code->Download ZIP
Once download, extract game and shared
If there's template in your Visual Studio, move them into the plugin sdk template folder
Copy/move the folders game and shared into your project, and update(if its Visual Studio)
