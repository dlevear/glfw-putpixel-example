// For build system, see https://github.com/dlevear/glfw-putpixel-example
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
using std::cout, std::endl;
using std::string, std::to_string;

// Globals
float* canvas;
float prev_draw = 0; // for calculating fps

// Use put_pixel() to set the color of the pixels
void put_pixel(int row, int col, float r, float g, float b);

// Initialization function to contain some GLFW calls. Call once.
GLFWwindow* init();

// Drawing function to contain GLFW calls. Call once per frame.
void update_window(GLFWwindow* window);

int main() {
    // Locals
    GLFWwindow* window = init();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Handling events, e.g. key presses
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }

        // Pixel updates
        // (drawing a 100 x 100 pink rectangle for example)
        for (int col=0; col < 100; col++) {
            for (int row=0; row < 100; row++) {
                put_pixel(row, col, 0.99, 0.41, 0.70);
            }
        }

        update_window(window);
    }

    glfwTerminate();
    delete [] canvas;
    return 0;
}

void put_pixel(int row, int col, float r, float g, float b) {
    if (row >= 480 || col >= 640 || row < 0 || col < 0) {
        cout << "(row,col) = (" << row << "," << col << ") is not valid for putPixel()" << endl;
        return;
    }
    canvas[640*3*(480-1-row) + 3*col + 0] = r;
    canvas[640*3*(480-1-row) + 3*col + 1] = g;
    canvas[640*3*(480-1-row) + 3*col + 2] = b;
}

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

    // Initializing canvas
    canvas = new float[640*480*3];
    for (int col=0; col < 640; col++) {
        for (int row=0; row < 480; row++) {
            put_pixel(row, col, 1, 1, 1);
        }
    }

    return window;
}

void update_window(GLFWwindow* window) {
    // Calculating fps
    double elapsed = glfwGetTime() - prev_draw;
    double fps = 1/elapsed;
    string title = "fps: " + to_string((int) fps);
    glfwSetWindowTitle(window, title.c_str());
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(640, 480, GL_RGB, GL_FLOAT, (void*) canvas);
    glfwSwapBuffers(window);
    prev_draw = glfwGetTime();
}


