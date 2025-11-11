# GTA V ScriptHookV Template

A template project for creating GTA V mods using ScriptHookV. This template provides a basic structure with text rendering capabilities and keyboard input handling.

## Features

- **Text Rendering**: Example code showing how to draw text on screen
- **Keyboard Input**: Basic keyboard handler setup
- **CMake Build System**: Easy to build and configure
- **Visual Studio Support**: Ready-to-use project files

## Prerequisites

- **Visual Studio** 2019 or later (with C++ development tools)
- **CMake** 3.10 or later
- **GTA V** with ScriptHookV installed
- **ScriptHookV SDK** (included in `extern/scripthookv/`)

## Building

1. Clone or download this repository
2. Open a terminal in the project root directory
3. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
4. Generate the Visual Studio solution:
   ```bash
   cmake ..
   ```
5. Open the generated `scripthookv_template.sln` in Visual Studio
6. Build the project (F7 or Build → Build Solution)
7. The compiled `.asi` file will be in `build/bin/Debug/` or `build/bin/Release/`

## Installation

1. Copy the compiled `.asi` file from `build/bin/Debug/scripthookv_template.asi` (or Release)
2. Paste it into your GTA V installation directory (where `GTA5.exe` is located)
3. Make sure you have ScriptHookV installed (download from [dev-c.com](http://dev-c.com))
4. Launch GTA V

## Usage

When the mod is loaded, you should see "Hello from the template!" displayed on screen, centered near the top.

## Project Structure

```
template/
├── build/              # Build output (generated, not in git)
├── extern/             # External dependencies
│   └── scripthookv/   # ScriptHookV SDK
│       ├── inc/       # Header files
│       └── lib/       # Library files
├── src/               # Source code
│   ├── keyboard.cpp  # Keyboard input handling
│   ├── keyboard.h
│   ├── main.cpp      # DLL entry point
│   ├── script.cpp    # Main script logic
│   └── script.h
├── CMakeLists.txt    # CMake configuration
└── README.md         # This file
```

## Customization

### Changing the Displayed Text

Edit `src/script.cpp` and modify the string in the `update()` function:

```cpp
HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Your custom text here!");
```

### Adding More Functionality

- Add your game logic in the `update()` function in `src/script.cpp`
- Use the ScriptHookV natives from `extern/scripthookv/inc/natives.h`
- Handle keyboard input in `src/keyboard.cpp`

## Resources

- [ScriptHookV Documentation](http://dev-c.com/)
- [GTA V Native Function Database](https://alloc8or.re/gta5/nativedb/)

## License

This template is provided as-is for educational purposes. Make sure to comply with GTA V's terms of service and Rockstar's modding policies.

## Notes

- The build system is configured for Windows (Visual Studio)
- The project uses C++11 standard
- Debug builds include debug symbols, Release builds are optimized
- Make sure your GTA V version is compatible with your ScriptHookV version

