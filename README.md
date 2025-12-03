# Introduction

## What is this?
This is a basic C++ program to demonstrate some bare-bones graphics programming. The idea is to do everything through just a `put_pixel()` function.

It works on Mac and Windows thanks to a cross-platform API called GLFW.

## How do I build and run it?
Just run `sh build.sh` to build and run the project. 

You need to first install `cmake`, which is a build system commonly used for C++ projects. If you have Python installed, you can simply run `pip install cmake`. Alternatively, Windows users who use [scoop](https://scoop.sh) can run `scoop install cmake`, and Mac users who use [homebrew](https://brew.sh) can run `brew install cmake`. If none of those apply, then you can download it yourself from [CMake's downloads page](https://cmake.org/download/).

# Appendix

## Linux
I didn't test this on Linux yet. You might need to install some more GLFW dependencies for that to work.

## Why aren't you using OpenGL 3+ like a normal person?
The `glDrawPixels()` function is not Modern OpenGL and so I had to use a lower OpenGL version (2.1) and silence deprecations for it to work. It's pretty cool that you can do this without GLAD! The only external dependency is GLFW (and `cmake` for building).

This is just for educational purposes.
