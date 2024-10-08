#include <GL/glut.h>

// Rotation angles
float angleX = 0.0f, angleY = 0.0f;

// Function to draw a colorful cube
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Top face (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face (yellow)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Right face (cyan)
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Left face (magenta)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glEnd();
}

// Render function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // Eye position
        0.0, 0.0, 0.0,  // Look-at position
        0.0, 1.0, 0.0); // Up vector

    glRotatef(angleX, 1.0, 0.0, 0.0); // Rotate cube on X-axis
    glRotatef(angleY, 0.0, 1.0, 0.0); // Rotate cube on Y-axis

    drawCube();  // Draw the cube

    glutSwapBuffers();  // Swap the front and back buffer (for double buffering)
}

// Function to update the rotation angles
void update(int value) {
    angleX += 2.0f;
    angleY += 2.0f;

    if (angleX > 360) angleX -= 360;
    if (angleY > 360) angleY -= 360;

    glutPostRedisplay();  // Tell GLUT to redraw the screen
    glutTimerFunc(16, update, 0); // Call update every 16ms (~60FPS)
}

// Function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set the viewport to cover the new window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);  // Set perspective projection
    glMatrixMode(GL_MODELVIEW);
}

// Initialize OpenGL settings
void init() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glClearColor(0.1, 0.1, 0.1, 1.0); // Set the background color
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Enable depth testing
    glutInitWindowSize(600, 600);
    glutCreateWindow("Colorful Rotating Cube");

    init();  // Initialize OpenGL

    glutDisplayFunc(display);  // Set display callback
    glutReshapeFunc(reshape);  // Set reshape callback
    glutTimerFunc(25, update, 0);  // Set update function for animation

    glutMainLoop();
    return 0;
}
