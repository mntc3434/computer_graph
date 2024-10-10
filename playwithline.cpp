#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    glBegin(GL_LINE_STRIP); // Start drawing a pentagon
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    glVertex2f(0.0f, 0.0f);   // Top vertex
    glVertex2f(0.5f, -0.5f); // Right top vertex
    glVertex2f(-0.5, -0.5f); // Right bottom vertex
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(-0.5, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0, 0.0);
    // Left bottom vertex
   // Left top vertex
    glEnd();

    glFlush(); // Render the pentagon
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pentagon");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // Set up the coordinate system
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
