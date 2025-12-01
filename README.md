# Introduction

## What is this?
This is a basic C++ program to demonstrate some bare-bones graphics programming. The idea is to do everything through just a `put_pixel()` function.

It works on Mac and Windows thanks to a cross-platform API called GLFW.

## How do I run it?
You can just run `sh build.sh` to build the project. 

Windows users need to install `cmake` first (use `scoop install cmake`), but that's all. Mac users don't need to install anything extra.

# Appendix

## Linux
I didn't test this on Linux yet. You might need to install some more GLFW dependencies for that to work.

## Why aren't you using OpenGL 3+ like a normal person?
The `glDrawPixels()` function is not Modern OpenGL and so I had to use a lower OpenGL version (2.1) and silence deprecations for it to work. It's pretty cool that you can do this without GLAD! The only external dependency is GLFW. 

This is just for educational purposes.
