#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>

#define g 9.8
#define PI 3.14
#define ESC 27



void initialize(void)
{
    glClearColor(0, 0, 0, 0);
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1280, 0, 720);
}

static void keyPressFunc(unsigned char key, int x, int y)
{
    switch(key) {
        case ESC:
            exit(1);
    }
}

void display(void)
{
    int Pheta, Pheta2, Vo;
    Vo = 60;
    Pheta = 40;
    Pheta2 = 90 + (90 - Pheta);


    for(float t=0; t < 10 ; t += 0.005)
    {
        glBegin(GL_POINTS);
        int x1 = (Vo * cos(Pheta * PI / 180) * t);
        int y1 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        int x2 = (500 + Vo * cos(Pheta2 * PI / 180) * t);
        int y2 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        if  (x1 == x2 & y1 == y2)
      {
          break;
      }
        glEnd();
        glFlush();
    }

}




int main(int argc, char** argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("C-Lang-Project");

    glutKeyboardFunc(keyPressFunc);

    initialize();
    glutDisplayFunc(display);
    glutMainLoop();
}
