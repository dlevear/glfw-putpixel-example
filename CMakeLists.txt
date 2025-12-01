cmake_minimum_required(VERSION 3.16)

# (optional) these lines stop cmake generating a `make install` target which just reduces number of generated files
set(CMAKE_SKIP_INSTALL_RULES ON)
set(GLFW_INSTALL OFF)

# (optional) Setting some useful CXX_FLAGS 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(MyProject)

# Source for this next line: https://stackoverflow.com/questions/9460242/how-to-compile-glut-opengl-project-with-cmake-and-kdevelop-in-linux
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

# Inspiration for this next line: https://github.com/SasLuca/GLFWCMakeTemplate/blob/main/CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_MakeAvailable(glfw)

add_executable(app main.cpp)

target_link_libraries(app ${OPENGL_LIBRARIES})
target_link_libraries(app glfw)


# Optional line for windows so you can double click the icon without opening a console
# set(CMAKE_EXE_LINKER_FLAGS "-Wl,--subsystem=windows")

