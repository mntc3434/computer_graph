#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <math.h>

...
// Camera position and angles
float cameraX = 0.0f, cameraY = 1.0f, cameraZ = 7.0f; // Position
float cameraAngleX = 0.0f, cameraAngleY = 0.0f;       // Rotation angles

//// Light position
//GLfloat lightPos[] = { 0.0f, 2.5f, 0.0f, 1.0f }; // Single light source at center
//GLfloat lightIntensity = 1.0f; // Intensity for the main light

// Texture IDs
GLuint floorTexture, wallTexture, art1, art2, art3, art4, art5, art6, art7, art8, art9, art10;

// Function to setup lighting

void setupLighting() {
    // Enable lighting
    glEnable(GL_LIGHTING);

    // Define the main light source (positioned at the center of the room)
    GLfloat lightPos[] = { 0.0f, 3.0f, 0.0f, 1.0f }; // Positional light
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Ambient light (low intensity)
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Diffuse light (white light)
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular light (highlights)

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // Enable the light
   glEnable(GL_LIGHT0);

    // Set material properties for objects in the scene
    GLfloat matAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matDiffuse[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matShininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}
void drawLightSource() {
    glPushMatrix();
    GLfloat lightColor[] = { 1.0f, 1.0f, 0.8f, 1.0f }; // Light source color
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightColor);
    glTranslatef(0.0f, 3.0f, 0.0f); // Move to light source position
    glutSolidSphere(0.2, 20, 20);   // Draw light source as a small sphere
    glPopMatrix();
}






//void drawLightSource() {
//    glPushMatrix();
//    GLfloat lightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Yellow for light
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightColor);
//    glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
//    glutSolidSphere(0.3, 20, 20); // Represent the light as a sphere
//    glPopMatrix();
//}


// Function to load textures
GLuint loadTexture(const char* filename) {
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
    if (data == nullptr) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
    return textureID;
}

void setupTextures() {
    floorTexture = loadTexture("C:/Users/User/Desktop/textur/floor.jpg");
    wallTexture = loadTexture("C:/Users/User/Desktop/textur/wall9.jpg");
    art1 = loadTexture("C:/Users/User/Desktop/textur/art1.jpg");
    art2 = loadTexture("C:/Users/User/Desktop/textur/art5.jpg");
    art3 = loadTexture("C:/Users/User/Desktop/textur/art9.jpg");
    art4 = loadTexture("C:/Users/User/Desktop/textur/art11.jpg");
    art5 = loadTexture("C:/Users/User/Desktop/textur/art7.jpg");
    art6 = loadTexture("C:/Users/User/Desktop/textur/art6.jpg");
    art7 = loadTexture("C:/Users/User/Desktop/textur/art2.jpg");
    art8 = loadTexture("C:/Users/User/Desktop/textur/art12.jpg");
    art9 = loadTexture("C:/Users/User/Desktop/textur/art3.jpg");
    art10 = loadTexture("C:/Users/User/Desktop/textur/art10.jpg");

    glEnable(GL_TEXTURE_2D);
}


void drawRoom() {
    glPushMatrix();

    // Floor
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 0.0f, 5.0f);
    glEnd();

    // Walls
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    glBegin(GL_QUADS);

    // Front wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f);

    // Back wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f);

    // Left wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f);

    // Right wall
    glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 0.0f, -5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f);

    // Ceiling
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 5.0f, -5.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 5.0f, -5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, wallTexture); // Reuse wall texture for the mid-wall
    glBegin(GL_QUADS);

    // Mid-wall front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -2.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 2.0f, -2.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 2.0f);

   

    glEnd();

    glPopMatrix();
}

void drawFrames() {
    GLfloat frameColor1[] = { 0.8f, 0.5f, 0.2f, 1.0f }; // Brown
    GLfloat frameColor2[] = { 0.6f, 0.8f, 0.3f, 1.0f }; // Green

    // Front wall (one large frame)
    glPushMatrix();
   // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor1);
    glBindTexture(GL_TEXTURE_2D, art1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.0f, 1.0f, -4.9f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(3.0f, 1.0f, -4.9f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(3.0f, 4.0f, -4.9f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.0f, 4.0f, -4.9f);
    glEnd();
    glPopMatrix();

    // Back wall (one large frame)
    glPushMatrix();
   // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor1);
    glBindTexture(GL_TEXTURE_2D, art2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.0f, 1.0f, 4.9f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(3.0f, 1.0f, 4.9f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(3.0f, 4.0f, 4.9f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.0f, 4.0f, 4.9f);
    glEnd();
    glPopMatrix();

    // Left wall (two frames facing right wall)
    glPushMatrix();
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(-4.9f, 1.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art3);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(-4.9f, 1.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art4);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Right wall (two frames facing left wall)
    glPushMatrix();
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(4.9f, 1.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art5);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(4.9f, 1.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art6);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Middle frames
    // First set
    glPushMatrix();
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(0.1f, 0.5f, 1.3f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art7);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
   // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(0.1f, 0.5f, -0.3f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art8);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();
    //second set
    glPushMatrix();
   // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(-0.1f, 0.5f, 1.3f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art9);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
   // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frameColor2);
    glTranslatef(-0.1f, 0.5f, -0.3f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, art10);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Camera transformation
    glRotatef(cameraAngleY, 1.0f, 0.0f, 0.0f); // Vertical rotation
    glRotatef(cameraAngleX, 0.0f, 1.0f, 0.0f); // Horizontal rotation
    glTranslatef(-cameraX, -cameraY, -cameraZ); // Move the camera
   
    // Optionally, in your display function
    drawLightSource();

    drawRoom();
    drawFrames(); // Add frames to the walls
    //drawLightSource();

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
    case 27: // Escape key to exit
        exit(0);
    }

    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    const float rotateSpeed = 2.0f;

    if (key == GLUT_KEY_LEFT) {
        cameraAngleX -= rotateSpeed;
    }
    else if (key == GLUT_KEY_RIGHT) {
        cameraAngleX += rotateSpeed;
    }
    else if (key == GLUT_KEY_UP) {
        cameraAngleY -= rotateSpeed;
    }
    else if (key == GLUT_KEY_DOWN) {
        cameraAngleY += rotateSpeed;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Room with Frames and Light Source");

    glEnable(GL_DEPTH_TEST);
    setupLighting();
    setupTextures();


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
