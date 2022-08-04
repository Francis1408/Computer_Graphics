#include <GL/glew.h>
#include <GL/freeglut.h>

int i=0;

void desenhaQuadrado()
{

    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(90.0,10.0,0.0);
        glVertex3f(70.0,30.0,0.0);
        glVertex3f(90.0,90.0,0.0);
        glVertex3f(70.0,70.0,0.0);
        glVertex3f(10.0,90.0,0.0);
        glVertex3f(30.0,70.0,0.0);
        glVertex3f(10.0,10.0,0.0);
        glVertex3f(30.0,30.0,0.0);
        glVertex3f(90.0,10.0,0.0);
        glVertex3f(70.0,30.0,0.0);
    glEnd();
    glFlush();
}
void redesenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(i%2==0){
        glColor3f(0.0, 1.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        desenhaQuadrado();
    }
    else{
        glColor3f(0.0, 1.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        desenhaQuadrado();
        glColor3f(0.0, 0.0, 0.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        desenhaQuadrado();
    }



}

void setup()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}


void redimensionada(int width, int height)
{

   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void teclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;
    case 99:
        glutPostRedisplay();
        i++;
        break;

    default:
        break;
    }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);

   glutInitWindowPosition(100, 100);
   glutCreateWindow("Disco Quadrado");


   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);
   glutDisplayFunc(redesenha);

   setup();

   glutMainLoop();
   return 0;
}
