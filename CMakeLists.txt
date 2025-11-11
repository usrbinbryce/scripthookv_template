cmake_minimum_required(VERSION 3.10.0)
project(scripthookv_template LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# Set intermediate directory
set(CMAKE_OBJECT_FILE_DIRECTORY ${CMAKE_BINARY_DIR}/tmp/${CMAKE_BUILD_TYPE})

# Source files
set(SOURCES
    src/keyboard.cpp
    src/main.cpp
    src/script.cpp
)

# Header files (for IDE support)
set(HEADERS
    extern/scripthookv/inc/main.h
    extern/scripthookv/inc/enums.h
    extern/scripthookv/inc/natives.hpp
    extern/scripthookv/inc/types.h
    src/keyboard.h
    src/script.h
)

# Create shared library (DLL)
add_library(scripthookv_template SHARED ${SOURCES} ${HEADERS})

# Set output extension to .asi
set_target_properties(scripthookv_template PROPERTIES
    SUFFIX ".asi"
    OUTPUT_NAME "scripthookv_template"
)

# Include directories
target_include_directories(scripthookv_template PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/scripthookv/inc
)

# Link libraries
target_link_libraries(scripthookv_template PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/scripthookv/lib/ScriptHookV.lib
)

# Preprocessor definitions
target_compile_definitions(scripthookv_template PRIVATE
    WIN32
    NDEBUG
    _WINDOWS
    _USRDLL
    scripthookv_template_EXPORTS
)

# Set Release as default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Release-specific settings
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Warning level: Level3 (/W3)
    target_compile_options(scripthookv_template PRIVATE
        /W3
    )
    
    # Optimization: MaxSpeed (/O2)
    target_compile_options(scripthookv_template PRIVATE
        /O2
    )
    
    # Whole program optimization (/GL)
    target_compile_options(scripthookv_template PRIVATE
        /GL
    )
    
    # Runtime library: MultiThreaded (/MT)
    target_compile_options(scripthookv_template PRIVATE
        /MT
    )
    
    # Floating point model: Fast
    target_compile_options(scripthookv_template PRIVATE
        /fp:fast
    )
    
    # Function level linking
    target_compile_options(scripthookv_template PRIVATE
        /Gy
    )
    
    # Intrinsic functions
    target_compile_options(scripthookv_template PRIVATE
        /Oi
    )
    
    # Linker: Whole program optimization (/LTCG)
    target_link_options(scripthookv_template PRIVATE
        /LTCG
    )
    
    # Linker: Enable COMDAT folding
    target_link_options(scripthookv_template PRIVATE
        /OPT:REF
    )
    
    # Linker: Optimize references
    target_link_options(scripthookv_template PRIVATE
        /OPT:ICF
    )
    
    # No debug info
    target_link_options(scripthookv_template PRIVATE
        /DEBUG:NONE
    )
endif()
