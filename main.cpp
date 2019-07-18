#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "stdio.h"
#include "math.h"
#include <stdlib.h>

float view_rotx = 0.0f, view_roty = 180.0f;
float R_Z=0.0f, R_X=0.0f, R_Y=0.0f;
float T_Z=-4.0f, T_X=0.0f, T_Y=-0.0f;
float rot=1, pindah=0.0f;

int oldMouseX, oldMouseY;

void initGL(){
glShadeModel(GL_FLAT);

 float ambient[] = {1.0f,1.0f,1.0f,1.0f};
 float diffuse[] = {1.0f,1.0f,1.0f,1.0f};
 float specular[] = {0.2f,1.0f,0.2f,1.0f};
 float position[] = {20.0f,30.0f,20.0f,0.0f};

 glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
 glLightfv(GL_LIGHT0, GL_POSITION, position);
 glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

 float mambient[] ={0.1745f, 0.01175f, 0.01175f, 0.55f};
 float mdiffuse[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
 float mspecular[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
 float mshine =76.8f;

 glMaterialfv(GL_FRONT,GL_AMBIENT,mambient);
 glMaterialfv(GL_FRONT,GL_DIFFUSE,mdiffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,mspecular);
        glMaterialf (GL_FRONT,GL_SHININESS,mshine);

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);
    }



    void timer(int value){
         glutPostRedisplay();
         glutTimerFunc(15, timer, 0);
     }

    void mouseControl(int button, int state, int x, int y){
        oldMouseX = x;
        oldMouseY = y;
    }

    void mouseMotion(int x, int y){
        int getX = x;
        int getY = y;
        float thetaY = 360.0f*(getX - oldMouseX)/640;
        float thetaX = 360.0f*(getY - oldMouseY)/480;
        oldMouseX = getX;
        oldMouseY = getY;
        view_rotx += thetaX;
        view_roty += thetaY;
    }
     void reshape(GLsizei width, GLsizei height){
         if (height == 0) height = 1;
         GLfloat aspect = (GLfloat)width / (GLfloat)height;
        glViewport(30, 6, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, aspect, 1.0f, 20.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void tube(){
    float BODY_LENGTH=0.5f;
    float BODY_RADIUS=0.8f;
    int SLICES=6;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah

    }

void tube2(){
    float BODY_LENGTH=3.0f;
    float BODY_RADIUS=0.4f;
    int SLICES=30;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah

    }

void spring(){
    double radius=0.4;
    double t=1;
    double phi=3.14159265358979323846;
    double sudut,sudutAsli,x,y,z,tambah;
    tambah=t/1550;
    y=0;sudut=0;
    glTranslatef(0.0f, 0.0f, 0.6f);
    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
        while(y<=2.2f){
            sudutAsli=(sudut*phi/180);
            x=cos(sudutAsli)*radius;
            z=sin(sudutAsli)*radius;
            glVertex3d(z,x,y);
            y=y+tambah; sudut++;
        }
    glEnd();

}

void donat()
{
    float BODY_LENGTH=0.6f;
    float BODY_RADIUS1=0.4f;
    float BODY_RADIUS2=0.6f;
    int SLICES=120;
    int STACKS=120;
        GLUquadric *q = gluNewQuadric();
        glTranslatef(3.0f, 0.0f, -0.6f);
        gluDisk(q, BODY_RADIUS1, BODY_RADIUS2, SLICES, STACKS);
        gluCylinder(q, BODY_RADIUS2, BODY_RADIUS2, 0.6f, SLICES, STACKS);
        gluCylinder(q, BODY_RADIUS1, BODY_RADIUS2, 0.6f, SLICES, STACKS);
        glTranslatef(0.0f, 0.0f, 0.6f);
        gluDisk(q, BODY_RADIUS1, BODY_RADIUS2, SLICES, STACKS);
}

void donat1()
{
    float BODY_LENGTH=0.6f;
    float BODY_RADIUS1=0.6f;
    float BODY_RADIUS2=0.8f;
    int SLICES=6;
    int STACKS=120;
        GLUquadric *q = gluNewQuadric();
        glTranslatef(3.0f, 0.0f, -0.6f);
        gluDisk(q, BODY_RADIUS1, BODY_RADIUS2, SLICES, STACKS);
        gluCylinder(q, BODY_RADIUS2, BODY_RADIUS2, 0.6f, SLICES, STACKS);
        gluCylinder(q, BODY_RADIUS1, BODY_RADIUS2, 0.6f, SLICES, STACKS);
        glTranslatef(0.0f, 0.0f, 0.6f);
        gluDisk(q, BODY_RADIUS1, BODY_RADIUS2, SLICES, STACKS);
}

    void display_pen(){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glTranslatef(5.0f,0.0f, -15.0f);
        glRotatef(view_rotx, 1.0f, 0.0f, 0.0f);
        glRotatef(view_roty, 0.0f, 1.0f, 0.0f);
        glRotatef(90,1.0f,0.0f,0.0f);
        glRotatef(90,0.0f,1.0f,0.0f);
        glRotatef(90,0.0f,0.0f,1.0f);

        glTranslatef(0.0f,0.0f,4.0f);
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, pindah);
            glRotatef(rot, 0.0f, 0.0f, 1.0f);
            tube2(); // Pada fungsi yang sudah dibuat pada pembahasan sebelumnya
        glPopMatrix();
     
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, pindah);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        spring();
        glPopMatrix();
     
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, pindah);
            glRotatef(rot, 0.0f, 0.0f, 1.0f);
            tube(); // Pada fungsi yang sudah dibuat pada pembahasan sebelumnya
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-3.0f,0.0f,4.0f);
        donat(); // Pada fungsi yang sudah dibuat pada pembahasan sebelumnya
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-3.0f,0.0f,4.0f);
        donat1(); // Pada fungsi yang sudah dibuat pada pembahasan sebelumnya
        glPopMatrix();

        glFlush();
        glutSwapBuffers();

        
       

        if(pindah >= 2.8f) {
            pindah == 0.0f;
            
        } else {
            pindah += 0.01f;
         rot++;
        }
      if(rot == 360) {
            rot = 0;
        }
    }

    int main(int argc, char **argv){
        glutInit(&argc, argv);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
        glutInitWindowSize(480, 360);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("hemisphere");
        glutDisplayFunc(display_pen);
        glutReshapeFunc(reshape);
        initGL();
        glutMouseFunc(mouseControl);
        glutMotionFunc(mouseMotion);
        glutTimerFunc(0, timer, 0);
        glutMainLoop();
        return 0;
    }
