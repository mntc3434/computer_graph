#include <GL/glut.h>
....
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    glBegin(GL_TRIANGLES); // Start drawing triangles
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glVertex2f(-0.5f, -0.5f);glColor3f(1, 0, 0);// Vertex 1
    glVertex2f(0.5f, -0.5f); glColor3f(0, 1, 0);  // Vertex 2
    glVertex2f(0.0f, 0.5f); glColor3f(0, 0, 1);   // Vertex 3
    glEnd();

    glFlush(); // Render the triangle
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Drawing Triangles");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up the coordinate system
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
