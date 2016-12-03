#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>

static int window_width, window_height; // dimenzije prozora

const static float duzina_auta = 1;
const static float sirina_auta= 0.5;

static void on_reshape(int width, int height);
static void on_display(void);
static void drawCar(double x_koordinata, double y_koordinata);


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(1200,650);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	
	
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	glClearColor(1,1,1,0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(2);

	glutMainLoop();
	return 0;
}

static void on_reshape(int width, int height)
{
    	window_width = width;
    	window_height = height;
}

static void on_display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    	glViewport(0, 0, window_width, window_height);
    
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluPerspective(60, window_width/(float)window_height, 1, 5);

    	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
	//gluLookAt(1, 2, 3, 0, 0, 0, 0, 1, 0);
    	gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);
	drawCar(0,0);
	 
    	
    	glutSwapBuffers();
}

static void drawCar(double x_koordinata, double y_koordinata)
{

	int i;	
	glBegin(GL_POLYGON);
		glColor3f(0.9,0,0);
		glVertex3f(x_koordinata, y_koordinata,0);
		glColor3f(0.6,0,0);
		glVertex3f(x_koordinata, y_koordinata+duzina_auta,0);;
		glVertex3f(x_koordinata + sirina_auta,y_koordinata + duzina_auta,0);
		glColor3f(0.9,0,0);
		glVertex3f(x_koordinata + sirina_auta, y_koordinata,0);
	glEnd();
	
	glBegin(GL_POLYGON);
		for(i =0; i <= 360; i++){
			glColor3f(0.6,0,0);
			double angle =3.14 * i / 360;
			double x =x_koordinata + sirina_auta/2+cos(angle)/4;
			double y =y_koordinata + duzina_auta+sin(angle)/7;
			glVertex3f(x,y,0);
		}
	glEnd();
	
	glBegin(GL_POLYGON);
		for(i =0; i <= 360; i++){
			glColor3f(0.9,0,0);
			double angle =-3.14 * i / 8;
			double x = x_koordinata + sirina_auta/2+cos(angle)/4;
			double y = y_koordinata + sin(angle)/7;
			glVertex3f(x,y,0);
		}
	glEnd();
	
	//Desni far
	
	glBegin(GL_POLYGON);
		for(i=0; i<360; i++)
		{
		  glColor3f(1,1,0.6);
			double angle =-3.14 * i / 8;
			double x = x_koordinata + sirina_auta - 0.1+cos(angle)/20;
			double y = y_koordinata + sin(angle)/40 - 0.1;
			glVertex3f(x,y,0.0001);
		}
	glEnd();
	
	//Levi far
	
	glBegin(GL_POLYGON);
		for(i=0; i<360; i++)
		{
		  glColor3f(1,1,0.6);
			double angle =-3.14 * i / 8;
			double x = x_koordinata +0.1 +cos(angle)/20;
			double y = y_koordinata + sin(angle)/40 - 0.1;
			glVertex3f(x,y,0.0001);
	
		}
	glEnd();
	
	//Sofersajbna
	glBegin(GL_QUADS);
		glColor3f(0.2,0.2,0.2);
   		glVertex3f(x_koordinata+0.05, y_koordinata+0.1, 0.001);
		//glColor3f(0.4,0.4,0.4);
    		glVertex3f(x_koordinata + sirina_auta-0.05, y_koordinata+0.1, 0.001);
		glColor3f(0.4,0.4,0.4);
    		glVertex3f(x_koordinata+sirina_auta-0.1, y_koordinata+0.3, 0.001);
		glColor3f(0.7,0.7,0.7);
    		glVertex3f(x_koordinata+0.1, y_koordinata+0.3, 0.001);
    	glEnd();
	
	
	//Prozor na krovu
	glBegin(GL_QUADS);
		glColor3f(0.3,0.3,0.3);
   		glVertex3f(x_koordinata+0.11, y_koordinata+0.35, 0.001);
		//glColor3f(0.4,0.4,0.4);
    		glVertex3f(x_koordinata + sirina_auta-0.11, y_koordinata+0.35, 0.001);
		//glColor3f(0.4,0.4,0.4);
    		glVertex3f(x_koordinata+sirina_auta-0.11, y_koordinata+0.5, 0.001);
		glColor3f(0.7,0.7,0.7);
    		glVertex3f(x_koordinata+0.11, y_koordinata+0.5, 0.001);
    	glEnd();
	
	//Gepek
	
	glBegin(GL_QUADS);
		glColor3f(0.4,0.4,0.4);
   		glVertex3f(x_koordinata+0.05, y_koordinata + duzina_auta - 0.04 , 0.001);
    		glVertex3f(x_koordinata + sirina_auta-0.05, y_koordinata+duzina_auta -0.04 , 0.001);
    		glVertex3f(x_koordinata+sirina_auta-0.1, y_koordinata + duzina_auta-0.2, 0.001);
		glColor3f(0.2,0.2,0.2);
    		glVertex3f(x_koordinata+0.1, y_koordinata + duzina_auta-0.2, 0.001);
    	glEnd();
	
	//Prozori sa leve strane
	glBegin(GL_QUADS);
		glColor3f(0.3,0.3,0.3);
		glVertex3f(x_koordinata+0.03,y_koordinata+0.22,0.001);
		glVertex3f(x_koordinata+0.07,y_koordinata+0.26,0.001);
		glVertex3f(x_koordinata + 0.07,y_koordinata+duzina_auta/2+0.03, 0.001);
		glColor3f(0.6,0.6,0.6);
		glVertex3f(x_koordinata+0.03,y_koordinata+duzina_auta/2+0.03,0.001);
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f(0.3,0.3,0.3);
		glVertex3f(x_koordinata + 0.03,y_koordinata+duzina_auta/2+0.05, 0.001);
		glVertex3f(x_koordinata+0.07,y_koordinata+duzina_auta/2+0.05,0.001);
		glVertex3f(x_koordinata+0.07,y_koordinata+duzina_auta-0.22,0.001);
		glColor3f(0.6,0.6,0.6);
		glVertex3f(x_koordinata+0.03,y_koordinata+duzina_auta-0.20,0.001);
		
	glEnd();
	
	//Prozori sa desne strane
	glBegin(GL_QUADS);
		glColor3f(0.3,0.3,0.3);
		glVertex3f(x_koordinata+sirina_auta-0.07,y_koordinata+0.26,0.001);
		glVertex3f(x_koordinata+sirina_auta - 0.03,y_koordinata+0.22,0.001);
		glVertex3f(x_koordinata + sirina_auta - 0.03,y_koordinata+duzina_auta/2+0.03, 0.001);
		glColor3f(0.6,0.6,0.6);
		glVertex3f(x_koordinata+sirina_auta-0.07,y_koordinata+duzina_auta/2+0.03,0.001);
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f(0.3,0.3,0.3);
		glVertex3f(x_koordinata + sirina_auta -0.07,y_koordinata+duzina_auta/2+0.05, 0.001);
		glVertex3f(x_koordinata + sirina_auta -0.03,y_koordinata+duzina_auta/2+0.05,0.001);
		glVertex3f(x_koordinata + sirina_auta -0.03,y_koordinata+duzina_auta-0.20,0.001);
		glColor3f(0.6,0.6,0.6);
		glVertex3f(x_koordinata +sirina_auta -0.07,y_koordinata+duzina_auta-0.22,0.001);
		
	glEnd();
}




