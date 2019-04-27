
#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // background color
	glColor3f(1.0, 0, 0);  // foreground color

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex2f(0, 0.5);
		glVertex2f(0.5, 0);
		glVertex2f(-0.5, 0);
	glEnd();
	glFlush();
}

void main (int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Example"); // open a window named "Example"
	glutDisplayFunc(mydisplay);  // display callback
	init(); // set OpenGL state
	glutMainLoop(); // enter event loop
}

