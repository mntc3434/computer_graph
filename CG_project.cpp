
#include <GL/glut.h>
#include <iostream>
..
// Camera position and angles
float cameraX = 0.0f, cameraY = 1.0f, cameraZ = 7.0f; // Position
float cameraAngleX = 0.0f, cameraAngleY = 0.0f;       // Rotation angles

// Light position
GLfloat lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // Light source moved up
GLfloat lightIntensity = 1.0f; // Intensity for the main light
GLfloat secondLightIntensity = 0.5f; // Intensity for the second light (dimming)

// Light toggles
bool lightOn = true;
bool secondLightOn = true;

// Function to setup lighting
void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // Main light

    // Ambient, diffuse, and specular light settings for the first light
    GLfloat lightAmbient[] = { 0.1f, 0.1f, 0.3f, 1.0f }; // Cool ambient light
    GLfloat lightDiffuse[] = { 0.9f * lightIntensity, 0.9f * lightIntensity, 0.9f * lightIntensity, 1.0f }; // White diffuse light
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular highlight

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Setup second light if it's enabled
    if (secondLightOn) {
        glEnable(GL_LIGHT1); // Second light
        GLfloat secondLightDiffuse[] = { 0.8f * secondLightIntensity, 0.8f * secondLightIntensity, 0.8f * secondLightIntensity, 1.0f };
        GLfloat secondLightPos[] = { 0.0f, 2.5f, 0.0f, 1.0f }; // Position for the second light
        glLightfv(GL_LIGHT1, GL_DIFFUSE, secondLightDiffuse);
        glLightfv(GL_LIGHT1, GL_POSITION, secondLightPos);
    }
    else {
        glDisable(GL_LIGHT1); // Disable second light if off
    }
}

// Function to toggle light on and off
void toggleLight() {
    lightOn = !lightOn;
    if (lightOn) {
        glEnable(GL_LIGHT0); // Enable main light
    }
    else {
        glDisable(GL_LIGHT0); // Disable main light
    }
}

// Function to adjust second light intensity (dimming effect)
void adjustSecondLight() {
    secondLightIntensity = (secondLightIntensity == 1.0f) ? 0.2f : 1.0f; // Toggle between 100% and 20% brightness
    setupLighting(); // Reapply the lighting settings
}

void drawRoom() {
    glPushMatrix();

    // Floor
    GLfloat ambint4[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambint4);
    glBegin(GL_QUADS);
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, 5.0f);
    glVertex3f(-5.0f, 0.0f, 5.0f);
    glEnd();

    // Walls
    GLfloat ambint3[] = { 0.7f, 0.7f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambint3);
    glBegin(GL_QUADS);

    // Front wall
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);

    // Back wall
    glVertex3f(-5.0f, 0.0f, 5.0f);
    glVertex3f(5.0f, 0.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);

    // Left wall with photo frame
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(-5.0f, 0.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);

    // Right wall with window
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);

    // Ceiling
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);

    glEnd();

    glPopMatrix();
}

void drawLightSource() {
    glPushMatrix();
    GLfloat ambint1[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambint1); // Yellow for light
    glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f); // Rotate cone to point downward
    glutSolidCone(0.3, 0.8, 20, 20); // Spike-shaped cone
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    
        // Camera transformation
        glRotatef(cameraAngleY, 1.0f, 0.0f, 0.0f); // Vertical rotation
    glRotatef(cameraAngleX, 0.0f, 1.0f, 0.0f); // Horizontal rotation
    glTranslatef(-cameraX, -cameraY, -cameraZ); // Move the camera

    drawRoom();
    drawLightSource();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    const float moveSpeed = 0.2f;
    const float rotateSpeed = 2.0f;

    switch (key) {
    case 'w': // Move forward
        cameraZ -= moveSpeed;
        break;
    case 's': // Move backward
        cameraZ += moveSpeed;
        break;
    case 'a': // Move left
        cameraX -= moveSpeed;
        break;
    case 'd': // Move right
        cameraX += moveSpeed;
        break;
    case 'l': // Toggle light on/off
        toggleLight();
        break;
    case 't': // Toggle second light intensity (dimming effect)
        adjustSecondLight();
        break;
    case 27: // Escape key to exit
        exit(0);
    }

    setupLighting(); // Reapply the lighting settings
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    const float rotateSpeed = 2.0f;

    if (key == GLUT_KEY_LEFT) {
        cameraAngleX -= rotateSpeed;
    }
    if (key == GLUT_KEY_RIGHT) {
        cameraAngleX += rotateSpeed;
    }
    if (key == GLUT_KEY_UP) {
        cameraAngleY -= rotateSpeed;
    }
    if (key == GLUT_KEY_DOWN) {
        cameraAngleY += rotateSpeed;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Room with Lighting");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    setupLighting();

    glutMainLoop();
    return 0;
}
