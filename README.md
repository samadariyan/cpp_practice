# C++23 Fundamentals with Projects & Algorithms

> **Stop learning C++ the wrong way.** Master it like professionals do - with real projects, modern tools, and industry practices.

This repository contains the complete source code and projects for the comprehensive C++23 Fundamentals course available on [Udemy](https://www.udemy.com/course/cpp23-fundamentals-projects-algorithms/?couponCode=ENDMARCH2025).

## 🚀 Why This is the ONLY C++ Course You Need

Don't waste time with outdated tutorials and toy examples. This course teaches C++ the way it's actually used in industry:

- **Real-World Projects**, Not Toy Examples
- **Professional Tools** Used in Industry
- **Modern C++ Features** (C++11 through C++23)
- **Industry-Standard Practices**
- **Comprehensive Project Structure**

## 🎯 What Sets This Course Apart

### 💪 Beyond Basic Tutorials
- Build **structured, multi-file projects** from day one
- Learn **professional development workflows** used in industry
- Master **modern build systems** and package management
- Deep dive into **debugging** and much more! 

### 🛠️ Professional Tool Stack
- **Modern CMake** for build management
- **vcpkg** for package management
- **Industry-standard debugging** tools
- **Third-party library** integration
- **Complete IDE setup** and optimization

## 📚 What You'll Master

### 1. Complete C++ Evolution
- Master features from C++11 through C++23
- Work with and improve legacy codebases
- Write future-proof, modern C++ code
- Understand the "why" behind each feature

### 2. Professional Development
- Build systems with Modern CMake
- Package management with vcpkg
- Debugging workflows
- Code organization and best practices

### 3. Real-World Applications
- GUI development with SFML/ftxui
- Modern file handling with std::filesystem
- Game development fundamentals
- Data structures and algorithms

### 4. Advanced Concepts
- Smart pointers and RAII
- Move semantics optimization
- Memory management
- STL containers and algorithms

## 🎯 Perfect For

- **Complete Beginners** wanting to learn C++ the right way
- **Self-Taught Developers** struggling with best practices
- **Students & CS Majors** seeking practical skills
- **Professional Developers** from Python/Java/C#
- **Game Developers** needing C++ expertise
- **Systems Programmers** requiring performance
- **Anyone Serious** about professional C++ development

## 💼 Industry-Ready Skills

Learn what employers actually need:
- ✅ Modern C++ (C++11 through C++23)
- ✅ Professional build systems
- ✅ Package management
- ✅ Real project structure
- ✅ Debugging techniques
- ✅ Best practices & patterns

## 📊 Course Stats

- ⭐ 4.8/5 Rating
- 📚 60.5 hours of content
- 🎯 103 comprehensive lectures
- 💻 18 hands-on exercises
- 🏆 Certificate of completion
- 📱 Mobile & TV access
- 🔄 Lifetime updates

> "Not just another C++ course—it's your complete pathway to professional C++ development."

## Getting Started

Follow our comprehensive environment setup guide below to get started with modern C++ development across any platform.

# C++23 Masterclass Development Environment Setup

Quick Setup Links:
- [Windows Setup Guide](#windows-setup)
- [Linux Setup Guide](#linux-setup-ubuntu-2404)
- [macOS Setup Guide](#macos-setup)
- [Docker Setup Guide](#docker-setup-alternative-for-any-platform) (Recommended for consistent environment)

This guide explains how to set up your development environment for the C++23 Masterclass course across different platforms.

> 🐳 **Why Docker?** Using Docker provides a consistent, pre-configured environment that works identically across all platforms. It eliminates "works on my machine" issues and gives you instant access to the latest C++ tools without complex setup. Perfect for both beginners and professionals!

## Common Requirements

All platforms require these core tools:
- CMake (3.28.0 or higher)
- Ninja build system
- Git
- vcpkg package manager
- Visual Studio Code with extensions:
  - C++ extensions (either Microsoft C++ or Clangd + CodeLLDB)
  - CMake Tools
  - CMake
  - Docker (optional)
  - Dev Containers (optional)

## Windows Setup

1. **Install Visual Studio 2022**
   - Download from [Visual Studio Website](https://visualstudio.microsoft.com/downloads/)
   - Select "Desktop development with C++" workload
   - This provides the MSVC compiler (cl.exe)

2. **Install CMake**
   - Download latest version from [CMake's official site](https://cmake.org/download/)
   - Ensure CMake is added to system PATH during installation
   - Verify with `cmake --version`

3. **Install Ninja**
   - Download via [WinLibs](https://winlibs.com/)
   - Add Ninja to system PATH
   - Verify with `ninja --version`

4. **Install Git**
   - Download from [Git's official site](https://git-scm.com/)
   - Add to system PATH during installation
   - Configure user name and email

5. **Install vcpkg**
   ```powershell
   git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
   cd C:\vcpkg
   .\bootstrap-vcpkg.bat
   ```
   - Set VCPKG_ROOT environment variable to C:\vcpkg

## Linux Setup (Ubuntu 24.04)

1. **Install Clang 19**
   ```bash
   wget https://apt.llvm.org/llvm.sh
   chmod +x llvm.sh
   sudo ./llvm.sh 19 all
   ```
   Configure as default compiler:
   ```bash
   sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-19 100
   sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-19 100
   ```

2. **Install CMake**
   ```bash
   # Download and install latest CMake
   wget https://github.com/Kitware/CMake/releases/download/v3.31.6/cmake-3.31.6-linux-x86_64.sh
   chmod +x cmake-3.31.6-linux-x86_64.sh
   sudo ./cmake-3.31.6-linux-x86_64.sh --prefix=/opt/cmake-3.31.6 --skip-license
   sudo update-alternatives --install /usr/bin/cmake cmake /opt/cmake-3.31.6/bin/cmake 100
   ```

3. **Install Ninja**
   ```bash
   sudo apt-get update
   sudo apt-get install wget unzip
   wget https://github.com/ninja-build/ninja/releases/download/v1.12.1/ninja-linux.zip
   unzip ninja-linux.zip
   sudo mv ninja /usr/bin/ninja
   sudo chmod +x /usr/bin/ninja
   ```

4. **Install vcpkg**
   ```bash
   git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
   cd ~/vcpkg
   ./bootstrap-vcpkg.sh
   ```
   Add to ~/.bashrc:
   ```bash
   export VCPKG_ROOT=~/vcpkg
   export PATH=$VCPKG_ROOT:$PATH
   ```

## macOS Setup

1. **Install Xcode Command Line Tools**
   ```bash
   xcode-select --install
   ```

2. **Install CMake**
   - Download from [CMake's official site](https://cmake.org/download/)
   - Install the .dmg file

3. **Install Ninja**
   ```bash
   brew install ninja
   ```

4. **Install vcpkg**
   ```bash
   git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
   cd ~/vcpkg
   ./bootstrap-vcpkg.sh
   ```
   Add to ~/.zshrc:
   ```bash
   export VCPKG_ROOT="$HOME/vcpkg"
   export PATH="$HOME/vcpkg:$PATH"
   ```

## Docker Setup (Alternative for any platform)

If you prefer a containerized environment or need access to the latest C++ features:

1. **Install Docker**
   - Windows/Mac: Install Docker Desktop
   - Linux: Install via package manager
   ```bash
   sudo apt install docker    # Ubuntu
   sudo dnf install docker   # Fedora
   sudo pacman -S docker    # Arch
   ```

2. **Pull and Run Container**
   ```bash
   docker pull dgakwaya/gcc-clang:latest
   docker run -it --name cpp_dev -v <path_to_code>:/workspace dgakwaya/gcc-clang:latest
   ```

   The container includes:
   - GCC 14.2.0
   - Clang 19.1.7
   - CMake 3.31.6
   - Ninja 1.12.1
   - vcpkg
   - GDB 13.1 and LLDB 19.1.7

3. **Connect VS Code**
   - Install Remote-Containers extension
   - Click green button in bottom-left corner
   - Select "Attach to Running Container"
   - Choose cpp_dev container
   - Open /workspace in the container

## Verification

After installation, verify your setup:
```bash
# Windows
cl.exe /?
cmake --version
ninja --version
vcpkg --version

# Linux/macOS
clang --version
cmake --version
ninja --version
vcpkg --version
```

## Project Structure
All projects in this course follow this basic structure:
```
project/
  ├── CMakeLists.txt
  ├── CMakePresets.json
  ├── main.cpp
  ├── utilities.ixx (or .h/.cpp for header projects)
  ├── vcpkg.json
  └── build/
```

## Debugging Setup

To enable debugging in your projects, you'll need to configure a launch.json file in VS Code. The file should point to your project's compiled binary. The default binary paths vary by operating system and compiler. Here are the typical paths (replace "ProjectName" with your actual project name):

- Windows (MSVC): `build/cl/Debug/ProjectName.exe`
- Linux/macOS (Clang): `build/linux-clang/Debug/ProjectName`
- Docker (Clang): `build/linux-clang/Debug/ProjectName`

Detailed instructions for configuring launch.json are provided in the course videos for each project.