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
    glEnable(GL_POINT_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1000, 0, 500);
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
    float Pheta, Pheta2, Pheta3,Pheta4, Vo, time, time_top, d1, d2, d3, Uox1, Uox2, Uox3;
    Vo = 60;
    Pheta = 60;
    Pheta2 = 30;
    Pheta3 = 40;
    Pheta4 = 50;
    time = (2 * Vo * sin(Pheta * PI / 180)) / g;
    time_top = time/2;
    d1 = 500;
    d2 = 650;
    d3 = 800;

    Uox1 = (d1 - Vo * cos(Pheta * PI / 180) * 2)/2;
    Uox2 = (d2 - Vo * cos(Pheta * PI / 180)*  time_top)/time_top;
    Uox3 = (d3 - Vo * cos(Pheta * PI / 180) * 8)/8;


    for(float t=0; t < 12 ; t += 0.0005)
    {
        float x1 = (Vo * cos(Pheta * PI / 180) * t);
        float y1 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        float x2 = (d1 - Uox1 * t);
        float y2 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        float x3 = (d2 - Uox2 * t);
        float y3 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        float x4 = (d3 - Uox3 * t);
        float y4 = (Vo * sin(Pheta * PI / 180) * t - 0.5 * g * t * t);

        glBegin(GL_POINTS);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glVertex2d(x4, y4);

        if  (x1+0.1 >= x4 && x4+0.1 >= x1)
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
