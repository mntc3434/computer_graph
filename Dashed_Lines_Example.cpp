.#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    // Enable line stipple for dashed lines
    glEnable(GL_LINE_STIPPLE);

    // Set the stipple pattern: 0x00FF means a dashed line
    glLineStipple(1, 0x00FF); // 1 means every other pixel is drawn

    // Start drawing the first dashed line
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
    glVertex2f(-0.5f, -0.5f); // Start point
    glVertex2f(0.5f, 0.5f);   // End point
    glEnd();

    // Start drawing the second dashed line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    glVertex2f(-0.5f, 0.5f); // Start point
    glVertex2f(0.5f, -0.5f);   // End point
    glEnd();

    // Disable line stipple after drawing
    glDisable(GL_LINE_STIPPLE);

    glFlush(); // Render the lines
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dashed Lines Example");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up the coordinate system
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
