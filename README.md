# Air battle game using [SFML](https://www.sfml-dev.org)

I. Install CMake
================
Install CMake, preferably CMake-GUI (www.cmake.org or the cmake-gui package in Linux).

II. Install SFML
================
Download SFML 2 (www.sfml-dev.org). We recommend using a precompiled version of SFML which can be directly downloaded.

It is also possible to build SFML yourself, in this case make sure that it is *installed* (make install, or compile the INSTALL project). Refer to the online tutorials for more details.

Eventually, you should have a directory with at least the subdirectories "include" and "lib" that contain headers and binaries of the SFML library, for example C:\SFML in Windows or /usr/local in Linux.

III. Generate the build configuration
=====================================
1. Go to directory containing this Readme.md file

2. From terminal (Linux) or from Visual Studio Developer Command Line Tool (Windows) enter command below
    #### cmake -G "Unix Makefiles"  (for Linux)
    #### cmake -G "NMake Makefiles" (for Windows)

3. For g++ or clang, this will be a Makefile. In the terminal, type "make install".
   If you use MinGW on Windows, you might have to type "mingw32-make install" instead.
   
   Since, project is cmake based. You can create projects easily for Visual Studio, Code::Blocks or any other IDEs.
