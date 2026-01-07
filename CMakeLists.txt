cmake_minimum_required(VERSION 3.28)

#Use LLVM for C++ modules but with system headers for SFML compatibility
if(APPLE)
        set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
        set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
endif()
set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

#Add system compiler paths for SFML compatibility
set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")
#set(CMAKE_OSX_DEPLOYMENT_TARGET "15.0")

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

#The project name is set to MyRocket
project(MyRocket VERSION 1.0.0 LANGUAGES CXX)

#Require C++ 20(more compatible with SFML)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CXX_STANDARD_REQUIRED ON) # Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON) # Re-enable C++ modules

#Find required packages
find_package(fmt CONFIG REQUIRED)
find_package(ftxui CONFIG REQUIRED)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network CONFIG REQUIRED)

#the name of the executable will be the same as the project name.
add_executable(${PROJECT_NAME} src/main.cpp src/functions-basics/compare_impl.cpp src/functions-basics/math_impl.cpp)

#Include directories
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#Add system include paths for SFML compatibility with LLVM
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
                ${CMAKE_OSX_SYSROOT}/usr/include
                ${CMAKE_OSX_SYSROOT}/System/Library/Frameworks
        )
endif()

#Add C++ module sources using FILE_SET
target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        src/utilities.ixx
        src/pointers/pointers_1.ixx
        src/pointers/pointers_2.ixx
        src/pointers/pointers_3.ixx
        src/pointers/pointers_4.ixx
        src/basic/random_numbers.ixx
        src/basic/fortune_tellter.ixx
        src/basic/secuences_challenge.ixx
        src/memory/dynamic_memory_allocation_1.ixx
        src/memory/shared_pointers.ixx
        src/memory/unique_pointers.ixx
        src/memory/references.ixx
        src/memory/pointer_challenge.ixx
        src/chars/handling_c_strings.ixx
        src/chars/handling_characters.ixx
        src/chars/handling_std_strings.ixx
        src/string/string_literals.ixx
        src/string/string_views.ixx
        src/string/charachter_challenges.ixx
        src/ftxui/ftxui_challenge1.ixx
        src/ftxui/ftxui_challenge2.ixx
        src/functions-basics/compare.ixx
        src/functions-basics/math.ixx
        src/passing-parameters/parameters.ixx
        src/attributes-static-vars-recursion/attributes.ixx
        src/attributes-static-vars-recursion/recursion.ixx
        src/attributes-static-vars-recursion/static_vars.ixx
        src/function-overloading/overloading_1.ixx
        src/function-overloading/overloading_2.ixx
        src/function-overloading/overloading_4.ixx

)

#Link required libraries
target_link_libraries(${PROJECT_NAME}
        PRIVATE fmt::fmt
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        PRIVATE SFML::Graphics
        PRIVATE SFML::Audio
        PRIVATE SFML::Network
        PRIVATE SFML::Window
        PRIVATE SFML::System
)

#Add macOS frameworks for SFML
if(APPLE)
        target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo" "-framework CoreFoundation")
endif()
