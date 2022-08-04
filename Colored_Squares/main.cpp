#include <GL/glew.h>
#include <GL/freeglut.h>

void desenhaQuadrado()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Vermelho
        glVertex3f(50.0, 50.0, 0.0);
        glVertex3f(50.0, 100.0, 0.0);
        glVertex3f(100.0, 100.0, 0.0);
        glVertex3f(100.0, 50.0, 0.0);
    glEnd();

    glColor3f(1.0,1.0,0.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Amarelo
        glVertex3f(100.0,50.0,0.0);
        glVertex3f(100.0,100.0,0.0);
        glVertex3f(150.0,100.0,0.0);
        glVertex3f(150.0,50.0,0.0);
    glEnd();

    glColor3f(0.0,1.0,0.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Verde
        glVertex3f(150.0,50.0,0.0);
        glVertex3f(150.0,100.0,0.0);
        glVertex3f(200.0,100.0,0.0);
        glVertex3f(200.0,50.0,0.0);
    glEnd();

    glColor3f(0.0,0.0,1.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Azul
        glVertex3f(50.0,100.0,0.0);
        glVertex3f(50.0,150.0,0.0);
        glVertex3f(100.0,150.0,0.0);
        glVertex3f(100.0,100.0,0.0);
    glEnd();

    glColor3f(0.0,1.0,1.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Ciano
        glVertex3f(100.0,100.0,0.0);
        glVertex3f(100.0,150.0,0.0);
        glVertex3f(150.0,150.0,0.0);
        glVertex3f(150.0,100.0,0.0);
    glEnd();

    glColor3f(1.0,0.0,1.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Magenta
        glVertex3f(150.0,100.0,0.0);
        glVertex3f(150.0,150.0,0.0);
        glVertex3f(200.0,150.0,0.0);
        glVertex3f(200.0,100.0,0.0);
    glEnd();

    glColor3b(0.0,0.0,0.0);

    glBegin(GL_TRIANGLE_FAN); //Desenha Quadrado Preto
        glVertex3f(50.0,150.0,0.0);
        glVertex3f(50.0,200.0,0.0);
        glVertex3f(100.0,200.0,0.0);
        glVertex3f(100.0,150.0,0.0);
    glEnd();

    glColor3f(0.6,0.6,0.6);

    glBegin(GL_TRIANGLE_FAN); // Desenha Quadrado Cinza
        glVertex3f(100.0,150.0,0.0);
        glVertex3f(100.0,200.0,0.0);
        glVertex3f(150.0,200.0,0.0);
        glVertex3f(150.0,150.0,0.0);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glColor3f(0.0,0.0,0.0); //Já que o branco nao aparece, fiz um contorno preto com o GL_LINE

    glBegin(GL_LINE_LOOP);
        glVertex3f(150.0,150.0,0.0);
        glVertex3f(150.0,200.0,0.0);
        glVertex3f(200.0,200.0,0.0);
        glVertex3f(200.0,150.0,0.0);
    glEnd();


    glFlush();
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
   glOrtho(0.0, 250.0, 0.0, 250.0, -1.0, 1.0);

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
   glutCreateWindow("Quadrados Coloridos");


   glutDisplayFunc(desenhaQuadrado);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);

   setup();

   glutMainLoop();
   return 0;
}
