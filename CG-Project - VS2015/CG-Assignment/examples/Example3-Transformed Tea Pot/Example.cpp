
#include <GL/glut.h>
// #include <GL/glaux.h>

void init()
{
	//light source
	GLfloat light_position[]={0,50,-100,1};
	GLfloat ambient[]={0.2,0.2,0.2,1};
	GLfloat diffuse[]={0.8,0.8,0.8,1};
	GLfloat specular[]={1,0.6,0.6,1};
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);
	glLightfv(GL_LIGHT1,GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,specular);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glClearColor(0.3,0.4,0.8,0.1);
	glShadeModel(GL_SMOOTH);
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat tp_ambient[]={0.05,0.05,0.05,1};
	GLfloat tp_diffuse[]={0.7,0.3,1,1};
	GLfloat tp_specular[]={0.6,0.6,0.6,1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,tp_ambient);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,tp_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,tp_specular);
	//Transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.2, 0.5, -0.7); //translate
	glRotatef(-30.0, 0.0, 0.0, 1.0); //rotate about Z axis
	glScalef(1.8, 1, 1); //scale
	glutSolidTeapot(0.2);

	glFlush();
}

void main (int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	//window
	glutInitWindowSize(800,600);
	glutInitWindowPosition(150,100);
	glutCreateWindow("Example");

	glutDisplayFunc(mydisplay);  // display callback
	init(); // set OpenGL state
	glutMainLoop(); // enter event loop
}

