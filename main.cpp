#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
using std::cout, std::endl;
using std::string, std::to_string;

// Globals
float* image;
float prev_draw = 0; // for calculating fps

// Initialization function to contain some GLFW calls
GLFWwindow* init() {
    // Readying GLFW and Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    return window;
}

// Drawing function to contain GLFW calls
void draw(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(640, 480, GL_RGB, GL_FLOAT, (void*) image);
    glfwSwapBuffers(window);
}

// Use this to draw anything
void put_pixel(int row, int col, float r, float g, float b) {
    if (row >= 480 || col >= 640 || row < 0 || col < 0) {
        cout << "(row,col) = (" << row << "," << col << ") is not valid for putPixel()" << endl;
        return;
    }
    image[640*3*(480-1-row) + 3*col + 0] = r;
    image[640*3*(480-1-row) + 3*col + 1] = g;
    image[640*3*(480-1-row) + 3*col + 2] = b;
}

int main() {
    // Initializing image
    image = new float[640*480*3];
    for (int col=0; col < 640; col++) {
        for (int row=0; row < 480; row++) {
            put_pixel(row, col, 1, 1, 1);
        }
    }

    GLFWwindow* window = init();
    while (!glfwWindowShouldClose(window)) {
        // Calculating fps
        double elapsed = glfwGetTime() - prev_draw;
        double fps = 1/elapsed;
        string title = "fps: " + to_string((int) fps);
        glfwSetWindowTitle(window, title.c_str());

        // Events
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }

        // Drawing a 100 x 100 pink rectangle for example
        for (int col=0; col < 100; col++) {
            for (int row=0; row < 100; row++) {
                put_pixel(row, col, 0.99, 0.41, 0.70);
            }
        }

        // Drawing
        prev_draw = glfwGetTime();
        draw(window);
    }

    glfwTerminate();
    delete [] image;
    return 0;
}


