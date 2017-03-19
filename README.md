## Computer Graphics and Visualization Lab (VTU)

### Installing on Linux
#### On Debian based systems
You can install the required dependencies using the following commands

    sudo apt-get update
    sudo apt-get install freeglut3
    sudo apt-get install freeglut3-dev
    sudo apt-get install binutils-gold
    sudo apt-get install g++ cmake
    sudo apt-get install libglew-dev
    sudo apt-get install g++
    sudo apt-get install mesa-common-dev
    sudo apt-get install build-essential
    sudo apt-get install libglew1.5-dev libglm-dev
    sudo apt-get install libxmu-dev libxi-dev
    
#### On Arch based systems
    pacman -S mesa

### Compiling the code (without CMake)

    g++ file.c -lglut -lGL -lGLEW -lGLU -o compiledFileName
### Executing the  code (without CMake)

    ./compiledFileName
    
### Compiling and running projects using CMake
   Incase you want to use CMake to compile, run and manage your CG projects then use the following commands.
   In the CMakeLists.txt file file provided in this repo, add the following lines to the end of the file
   
        add_executable(executableName file.c) //Create an executable for the file.
        target_link_libraries(executableName ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ) // Link the libraries to the executable

   Create a build folder in your present directory
    
        cd ~/10CSL67
        mkdir build
        
   Using CMake precompile the rewuired project
    
        cd ~/10CSL67/build
        cmake ..
      
   In the build directory compile the project
        
        cd ~/10CSL67/build
        make
   
   Now run the program using the executable name given earlier in the build directory
   
        cd ~/10CSL67/build
        ./executableName
   
