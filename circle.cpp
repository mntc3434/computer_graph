#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the window with the background color

    float cx = 0.0f;  // Center X coordinate
    float cy = 0.0f;  // Center Y coordinate
    float radius = 0.5f;  // Radius of the circle
    int num_segments = 100;  // Number of segments to approximate the circle

    // Start drawing the circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);  // Color of the circle (red)
    glVertex2f(cx, cy);  // Center of the circle

    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * PI * i / num_segments;  // Calculate the angle for each segment
        float x = cx + cos(angle) * radius;  // X coordinate of the point
        float y = cy + sin(angle) * radius;  // Y coordinate of the point
        glVertex2f(x, y);  // Define the vertex
    }

    glEnd();
    glFlush();  // Execute the OpenGL commands
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Circle");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);  // Register the display callback
    glutMainLoop();  // Enter the event-processing loop
    return 0;
}
