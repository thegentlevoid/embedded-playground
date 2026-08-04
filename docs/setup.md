# Setting up the development environment

Installing development tools used for writing, compiling, debugging, and managing C projects.

## Environment

* OS: Windows
* Compiler: GCC
* Editor: VS Code
* Build System: CMake
* Version Control: Git

---

# Installation

## MSYS2

MSYS2 provides a Unix-like environment and package manager for Windows.

Download:

https://www.msys2.org/

Install GCC:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Verify:

```bash
gcc --version
```

GCC location:

```
C:\msys64\ucrt64\bin\gcc.exe
```

Add to Windows PATH:

```
C:\msys64\ucrt64\bin
```

---

## Git

Download:

https://git-scm.com/

Verify:

```bash
git --version
```

---

## VS Code

Download:

https://code.visualstudio.com/

Recommended extensions:

* C/C++ (Microsoft)
* CMake Tools
* GitLens

---

## CMake

Download:

https://cmake.org/download/

Verify:

```bash
cmake --version
```

---

## GDB

Included with MSYS2 GCC package.

Verify:

```bash
gdb --version
```

---

# GCC Commands

Compile:

```bash
gcc main.c -o program.exe
```

Run:

```bash
./program.exe
```

Compile with warnings:

```bash
gcc main.c -Wall -Wextra -o program.exe
```

Compile with debug symbols:

```bash
gcc main.c -g -o program.exe
```

---

# GDB Commands

Start debugger:

```bash
gdb program.exe
```

Common commands:

```
break main
run
next
step
print variable
continue
quit
```

---

# Build Systems

## Make

Used for automating builds through Makefiles.

Check installation:

```bash
make --version
```

---

## CMake

Generates build files for projects.

Example workflow:

```bash
cmake -B build
cmake --build build
```

---

# Future Embedded Tools

Tools to add later:

* ARM GNU Toolchain
* OpenOCD
* ST-Link tools
* J-Link tools
* Ninja
* Cortex-Debug extension
