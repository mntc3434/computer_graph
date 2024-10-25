#include <GL/glut.h>
#include<math.h>

// Initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.3f, 0.5f, 0.1f); // Background color
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10); // Set the coordinate system
}
void drawLine() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.5, 1.0); // Black line color
    glBegin(GL_LINES);
    glVertex2f(-5.0, 0.0); // Starting point
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(5.0, 0.0);  // Ending point
    glEnd();
    glFlush();
}
// circle example
void drawCircle() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); // Blue color
    float radius = 5.0;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(radius * cos(theta), radius * sin(theta));
    }
    glEnd();
    glFlush();
} // transleation example

float tx = 2.0f, ty = 3.0f;
void drawTranslatedSquare() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();
    glPushMatrix();
    glTranslatef(tx, ty, 0.0f); // Apply translation
    glColor3f(1.0, 0.0, 0.0); // Red square
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glPopMatrix();
    glFlush();
}
/* void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP: ty += 0.5f; break;
    case GLUT_KEY_DOWN: ty -= 0.5f; break;
    case GLUT_KEY_LEFT: tx -= 0.5f; break;
    case GLUT_KEY_RIGHT: tx += 0.5f; break;
    }
    glutPostRedisplay();
}  */
void keyboard(int key, int x, int y) {
    switch (key) {
    case 'W': ty += 0.5f; break;
    case 'S': ty -= 0.5f; break;
    case 'A': tx -= 0.5f; break;
    case 'D': tx += 0.5f; break;
    }
    glutPostRedisplay();
}
// this is for scaling example
float sx = 1.5f, sy = 0.5f;

void drawScaledTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0, -1.0);
    glVertex2f(2.0, -1.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    //glTranslatef(5, 0, 0.0f);
    glPushMatrix();
    glScalef(sx, sy, 1.0f); // Apply scaling
    glColor3f(0.0, 1.0, 0.0); // Green triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0, -1.0);
    glVertex2f(2.0, -1.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    glPopMatrix();
    glFlush();
}
// rotation example 
float angle = 0.0f; // Rotate by 45 degrees

void drawRotatedTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0); // Apply rotation
    glColor3f(1.0, 0.5, 0.0); // Orange triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0, -1.0);
    glVertex2f(2.0, -1.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    glPopMatrix();
    glFlush();
}
// shering exampl or destorshion
float shx = 1.0f;

void drawShearedRectangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f); // Move it to avoid clipping
    GLfloat shearMatrix[16] = {
        1,  shx, 0, 0,
        0,  1,   0, 0,
        0,  0,   1, 0,
        0,  0,   0, 1
    };
    glMultMatrixf(shearMatrix); // Shear
    glColor3f(0.0, 0.0, 1.0); // Blue rectangle
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(3.0, -1.0);
    glVertex2f(3.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
    glPopMatrix();
    glFlush();
}
// this is for reflecton example 

void drawReflectedTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.0, 0.0); // Purple triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0, -1.0);
    glVertex2f(2.0, -1.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    glPushMatrix();
    glScalef(1.0, -1.0, 1.0); // Reflection on the -axis 
    glColor3f(0.5, 0.0, 0.5); // Purple triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0, -1.0);
    glVertex2f(2.0, -1.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    glPopMatrix();
    glFlush();
}

//Event handling for mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        sx += 0.1f;
        sy += 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        sx -= 0.1f;
        sy -= 0.1f;
    }
    glutPostRedisplay();
}

// this is for creating bounsing ball 
float posX = -10.0f;
float speed = 0.1f;
void drawBouncingRect() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5); // Purple rectangle
    glPushMatrix();
    glTranslatef(posX, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void update(int value) {
    posX += speed;
    if (posX > 10.0f || posX < -10.0f) speed = -speed; // Reverse direction
    glutPostRedisplay();
    glutTimerFunc(15, update, 0);
}
// Main function to create a window
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Primitive and Transformation Demo");
    init();
    glutDisplayFunc(drawCircle);
    glutDisplayFunc(drawBouncingRect);
    glutTimerFunc(15, update, 0);
  //glutSpecialFunc(keyboard);//this is for arrow keys and spasal keys like f1 and other 
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
